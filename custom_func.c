/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>

#include "sample_control_data_flash.h"
#include "sample_control_common.h"
#include "sample_defines.h"
#include "sample_types.h"
// #include "sample_config.h"

#include "r_rfd_common_api.h"
#include "r_rfd_common_control_api.h"
#include "r_rfd_common_userown.h"
#include "r_rfd_code_flash_api.h"

#include "r_smc_entry.h"
#include "platform.h"

#include "misc_config.h"
#include "custom_func.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

volatile struct flag_32bit flag_PROJ_CTL;
#define FLAG_PROJ_TIMER_PERIOD_1000MS                 	(flag_PROJ_CTL.bit0)
#define FLAG_PROJ_TRIG_BTN1                       	    (flag_PROJ_CTL.bit1)
#define FLAG_PROJ_TRIG_BTN2                 	        (flag_PROJ_CTL.bit2)
#define FLAG_PROJ_REVERSE3                    		    (flag_PROJ_CTL.bit3)
#define FLAG_PROJ_REVERSE4                              (flag_PROJ_CTL.bit4)
#define FLAG_PROJ_REVERSE5                              (flag_PROJ_CTL.bit5)
#define FLAG_PROJ_REVERSE6                              (flag_PROJ_CTL.bit6)
#define FLAG_PROJ_REVERSE7                              (flag_PROJ_CTL.bit7)


#define FLAG_PROJ_TRIG_1                                (flag_PROJ_CTL.bit8)
#define FLAG_PROJ_TRIG_2                                (flag_PROJ_CTL.bit9)
#define FLAG_PROJ_TRIG_3                                (flag_PROJ_CTL.bit10)
#define FLAG_PROJ_TRIG_4                                (flag_PROJ_CTL.bit11)
#define FLAG_PROJ_TRIG_5                                (flag_PROJ_CTL.bit12)
#define FLAG_PROJ_REVERSE13                             (flag_PROJ_CTL.bit13)
#define FLAG_PROJ_REVERSE14                             (flag_PROJ_CTL.bit14)
#define FLAG_PROJ_REVERSE15                             (flag_PROJ_CTL.bit15)

/*_____ D E F I N I T I O N S ______________________________________________*/

volatile unsigned long counter_tick = 0;
// volatile unsigned long btn_counter_tick = 0;

// #define BTN_PRESSED_LONG                                (2500)

#define CPU_FREQUENCY                                   (40u)

/*
    RL78/F23  12 Kbytes (FCF00H to FFEFFH) 
    RL78/F24  24 Kbytes (F9F00H to FFEFFH) 

    ram flag : LAST ram address - 2K (0x800)
    RL78/F24:FFF00H - 0x800 = FF700
    RL78/F23:FFF00H - 0x800 = FF700
*/

#define RESET_TO_BOOT_SIGN 0xAA55AA55
#pragma address (reset_to_bootloader = 0x000FF700)
volatile uint32_t reset_to_bootloader;

uint8_t iic_buf[12] = {0};

volatile bool g_i2c_transmit_complete = false;
volatile bool g_i2c_receive_complete = false;

const uint8_t switch_device_to_boot_mode_cmd[6] = {0x01, 0x00, 0x01, 0x3D, 0xC2, 0x03};
const uint8_t response_status_ok[7] = {0x81, 0x00, 0x02, 0x3D, 0x00, 0xC1, 0x03};


/*
    DATA FLASH
*/
/**** CPU frequency (MHz) ****/
/* It must be rounded up digits after the decimal point to form an integer (MHz). */
#define CPU_FREQUENCY     (40u)

/**** Address to write ****/
/* It should be the head address of the flash block. */
#define WRITE_ADDRESS     (0x000F1000uL)

/**** Data length to write ****/
/* Don't across the boundary of the flash block. */
#define WRITE_DATA_LENGTH (64u)

unsigned char data_flash_data_read[WRITE_DATA_LENGTH] = {0};
unsigned char data_flash_data_write[WRITE_DATA_LENGTH] = {0};


/*_____ M A C R O S ________________________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/

// unsigned long btn_get_tick(void)
// {
// 	return (btn_counter_tick);
// }

// void btn_set_tick(unsigned long t)
// {
// 	btn_counter_tick = t;
// }

// void btn_tick_counter(void)
// {
// 	btn_counter_tick++;
//     if (btn_get_tick() >= 60000)
//     {
//         btn_set_tick(0);
//     }
// }

unsigned long get_tick(void)
{
	return (counter_tick);
}

void set_tick(unsigned long t)
{
	counter_tick = t;
}

void tick_counter(void)
{
	counter_tick++;
    if (get_tick() >= 60000)
    {
        set_tick(0);
    }
}

void delay_ms(unsigned long ms)
{
	#if 1
    unsigned long tickstart = get_tick();
    unsigned long wait = ms;
	unsigned long tmp = 0;
	
    while (1)
    {
		if (get_tick() > tickstart)	// tickstart = 59000 , tick_counter = 60000
		{
			tmp = get_tick() - tickstart;
		}
		else // tickstart = 59000 , tick_counter = 2048
		{
			tmp = 60000 -  tickstart + get_tick();
		}		
		
		if (tmp > wait)
			break;
    }
	
	#else
	TIMER_Delay(TIMER0, 1000*ms);
	#endif
}


void Data_Flash_read(void)
{
    unsigned short cnt = 0;
    unsigned long check_write_data_addr = 0;
    
    check_write_data_addr = WRITE_ADDRESS;

    BSP_DI();
    R_RFD_SetDataFlashAccessMode(R_RFD_ENUM_DF_ACCESS_ENABLE);

    for (cnt = 0 ; cnt < WRITE_DATA_LENGTH; cnt++)
    { 
        data_flash_data_read[cnt] = (*(volatile __far uint8_t*)check_write_data_addr);
        check_write_data_addr++;
    }

    R_RFD_SetDataFlashAccessMode(R_RFD_ENUM_DF_ACCESS_DISABLE);
    BSP_EI();

    dump_buffer_hex(data_flash_data_read ,WRITE_DATA_LENGTH);
}

void Data_Flash_write_test(void)
{
    unsigned long i = 0;     
    e_sample_ret_t l_e_rfsp_status_flag;

    BSP_DI();
    for ( i = 0 ; i < WRITE_DATA_LENGTH; i++)
    {
        data_flash_data_write[i] = 0x00;
    }
    data_flash_data_write[0] = 0x5A;
    data_flash_data_write[1] = 0x5A;

    data_flash_data_write[2] = data_flash_data_read[2] + 1;
    // printf_tiny("data:0x%02X\r\n",data_flash_data_write[2]);
    for ( i = 2 ; i < (WRITE_DATA_LENGTH -2) ; i++)
    {
        data_flash_data_write[i+1] = data_flash_data_write[i] + 1;
        // printf_tiny("addr:%2d-",i);
        // printf_tiny("data:0x%02X\r\n",data_flash_data_write[i+1]);
    }

    data_flash_data_write[WRITE_DATA_LENGTH-2] = 0xA5;
    data_flash_data_write[WRITE_DATA_LENGTH-1] = 0xA5;

    l_e_rfsp_status_flag = Sample_DataFlashControl(WRITE_ADDRESS, WRITE_DATA_LENGTH, data_flash_data_write);
    BSP_EI();

    printf_tiny("Sample_DataFlashControl finish(0x%02X)\r\n",l_e_rfsp_status_flag);

}

void Data_Flash_init(void)
 {
	e_rfd_ret_t	    l_e_rfd_status_flag;
    // e_rfd_ret_t     l_e_rfd_ret_status;

    BSP_DI();
    /* Check whether HOCO is already started */
    if (SAMPLE_VALUE_U01_MASK0_1BIT == HIOSTOP)
    {
        /* Initialize RFD */
        l_e_rfd_status_flag = R_RFD_Init(CPU_FREQUENCY);
        printf_tiny("R_RFD_Init\r\n");

        if (R_RFD_ENUM_RET_STS_OK == l_e_rfd_status_flag)
        {
            /* Initialization OK */            
            // printf_tiny("R_RFD_Init rdy\r\n");
        }
        else
        {
            /* Failed to initialize RFD */
            // printf_tiny("R_RFD_Init err:SAMPLE_ENUM_RET_ERR_PARAMETER\r\n");
        }
    }
    else
    {
        /* HOCO is not started */
        // printf_tiny("R_RFD_Init err:SAMPLE_ENUM_RET_ERR_CONFIGURATION\r\n");
    }
    BSP_EI();
}


void uart_rcv_process(void)
{
    if (FLAG_PROJ_TRIG_3)
    {
        FLAG_PROJ_TRIG_3 = 0;

        reset_to_bootloader = RESET_TO_BOOT_SIGN;
        printf_tiny("(app)reset_to_bootloader:0x%X",reset_to_bootloader>>16);
        printf_tiny("%X\r\n",reset_to_bootloader&0xFFFF);

        _reset_by_illegal_memory_access();        
    }
}

void i2c_rcv_process(void)
{
    if(g_i2c_receive_complete)
    {
        if(0 == memcmp(&iic_buf[0], switch_device_to_boot_mode_cmd, 6))
        {
            R_Config_IICA0_Slave_Send((uint8_t *)response_status_ok, 7);
            while(!g_i2c_transmit_complete);

            reset_to_bootloader = RESET_TO_BOOT_SIGN;
            _reset_by_illegal_memory_access();
        }

        g_i2c_receive_complete = false;
    }
}

void Timer_1ms_IRQ(void)
{
    tick_counter();

    if ((get_tick() % 1000) == 0)
    {
        FLAG_PROJ_TIMER_PERIOD_1000MS = 1;
    }

    if ((get_tick() % 50) == 0)
    {

    }	

    // Button_Process_long_counter();
}


/*
    F24 target board
    LED1 connected to P66, LED2 connected to P67
*/
void LED_Toggle(void)
{
    // PIN_WRITE(6,6) = ~PIN_READ(6,6);
    // PIN_WRITE(6,7) = ~PIN_READ(6,7);
    P6_bit.no6 = ~P6_bit.no6;
    P6_bit.no7 = ~P6_bit.no7;
}

void loop(void)
{
	static unsigned long LOG1 = 0;

    if (FLAG_PROJ_TIMER_PERIOD_1000MS)
    {
        FLAG_PROJ_TIMER_PERIOD_1000MS = 0;

        // printf_tiny("log1(timer):%4d\r\n",LOG1++);
        // printf_tiny("log2(timer):%4d\r\n",LOG1++);
        printf_tiny("log3(timer):%4d\r\n",LOG1++);
        LED_Toggle();             
    }

    // Button_Process_in_polling();
    
    if (FLAG_PROJ_TRIG_1)
    {
        FLAG_PROJ_TRIG_1 = 0;
        Data_Flash_write_test();
    }
    if (FLAG_PROJ_TRIG_2)
    {
        FLAG_PROJ_TRIG_2 = 0;
        Data_Flash_read();
    }

    i2c_rcv_process();
    uart_rcv_process();
}


// F24 EVB , P137/INTP0 , set both edge 
// void Button_Process_long_counter(void)
// {
//     if (FLAG_PROJ_TRIG_BTN2)
//     {
//         btn_tick_counter();
//     }
//     else
//     {
//         btn_set_tick(0);
//     }
// }

// void Button_Process_in_polling(void)
// {
//     static unsigned char cnt = 0;

//     if (FLAG_PROJ_TRIG_BTN1)
//     {
//         FLAG_PROJ_TRIG_BTN1 = 0;
//         printf_tiny("BTN pressed(%d)\r\n",cnt);

//         if (cnt == 0)   //set both edge  , BTN pressed
//         {
//             FLAG_PROJ_TRIG_BTN2 = 1;
//         }
//         else if (cnt == 1)  //set both edge  , BTN released
//         {
//             FLAG_PROJ_TRIG_BTN2 = 0;
//         }

//         cnt = (cnt >= 1) ? (0) : (cnt+1) ;
//     }

//     if ((FLAG_PROJ_TRIG_BTN2 == 1) && 
//         (btn_get_tick() > BTN_PRESSED_LONG))
//     {         
//         printf_tiny("BTN pressed LONG\r\n");
//         btn_set_tick(0);
//         FLAG_PROJ_TRIG_BTN2 = 0;
//     }
// }

// // F24 EVB , P137/INTP0
// void Button_Process_in_IRQ(void)    
// {
//     FLAG_PROJ_TRIG_BTN1 = 1;
// }

void UARTx_Process(unsigned char rxbuf)
{    
    if (rxbuf > 0x7F)
    {
        printf_tiny("invalid command\r\n");
    }
    else
    {
        printf_tiny("press:%c(0x%02X)\r\n" , rxbuf,rxbuf);   // %c :  C99 libraries.
        switch(rxbuf)
        {
            case '1':
                FLAG_PROJ_TRIG_1 = 1;
                break;
            case '2':
                FLAG_PROJ_TRIG_2 = 1;
                break;
            case '3':
                FLAG_PROJ_TRIG_3 = 1;
                break;
            case '4':
                FLAG_PROJ_TRIG_4 = 1;
                break;
            case '5':
                FLAG_PROJ_TRIG_5 = 1;
                break;

            case 'X':
            case 'x':
                RL78_soft_reset(7);
                break;
            case 'Z':
            case 'z':
                RL78_soft_reset(1);
                break;
        }
    }
}

/*
    Reset Control Flag Register (RESF) 
    BIT7 : TRAP
    BIT6 : 0
    BIT5 : 0
    BIT4 : WDCLRF
    BIT3 : 0
    BIT2 : 0
    BIT1 : IAWRF
    BIT0 : LVIRF
*/
// void check_reset_source(void)
// {
//     /*
//         Internal reset request by execution of illegal instruction
//         0  Internal reset request is not generated, or the RESF register is cleared. 
//         1  Internal reset request is generated. 
//     */
//     uint8_t src = RESF;
//     printf_tiny("Reset Source <0x%08X>\r\n", src);

//     #if 1   //DEBUG , list reset source
//     if (src & BIT0)
//     {
//         printf_tiny("0)voltage detector (LVD)\r\n");       
//     }
//     if (src & BIT1)
//     {
//         printf_tiny("1)illegal-memory access\r\n");       
//     }
//     if (src & BIT2)
//     {
//         printf_tiny("2)EMPTY\r\n");       
//     }
//     if (src & BIT3)
//     {
//         printf_tiny("3)EMPTY\r\n");       
//     }
//     if (src & BIT4)
//     {
//         printf_tiny("4)watchdog timer (WDT) or clock monitor\r\n");       
//     }
//     if (src & BIT5)
//     {
//         printf_tiny("5)EMPTY\r\n");       
//     }
//     if (src & BIT6)
//     {
//         printf_tiny("6)EMPTY\r\n");       
//     }
//     if (src & BIT7)
//     {
//         printf_tiny("7)execution of illegal instruction\r\n");       
//     }
//     #endif

// }

/*
    7:Internal reset by execution of illegal instruction
    1:Internal reset by illegal-memory access
*/
//perform sofware reset
void _reset_by_illegal_instruction(void)
{
    static const unsigned char illegal_Instruction = 0xFF;
    void (*dummy) (void) = (void (*)(void))&illegal_Instruction;
    dummy();
}
void _reset_by_illegal_memory_access(void)
{
    #if 1
    const unsigned char ILLEGAL_ACCESS_ON = 0x80;
    IAWCTL |= ILLEGAL_ACCESS_ON;            // switch IAWEN on (default off)
    *(__far volatile char *)0x00000 = 0x00; //write illegal address 0x00000(RESET VECTOR)
    #else
    signed char __far* a;                   // Create a far-Pointer
    IAWCTL |= _80_CGC_ILLEGAL_ACCESS_ON;    // switch IAWEN on (default off)
    a = (signed char __far*) 0x0000;        // Point to 0x000000 (FLASH-ROM area)
    *a = 0;
    #endif
}

void RL78_soft_reset(unsigned char flag)
{
    switch(flag)
    {
        case 7: // do not use under debug mode
            _reset_by_illegal_instruction();        
            break;
        case 1:
            _reset_by_illegal_memory_access();
            break;
    }
}

// retarget printf
// int __far putchar(int c)
// {
//     // F24 , UART0
//     STMK0 = 1U;    /* disable INTST0 interrupt */
//     SDR00L = (unsigned char)c;
//     while(STIF0 == 0)
//     {

//     }
//     STIF0 = 0U;    /* clear INTST0 interrupt flag */
//     return c;
// }

void hardware_init(void)
{
    // const unsigned char indicator[] = "hardware_init";
    BSP_EI();
    R_Config_UART0_Start();         // UART , P15 , P16
    R_Config_TAU0_1_Start();        // TIMER
    // R_Config_INTC_INTP0_Start();    // BUTTON , P137 
    
	R_Config_IICA0_Slave_Receive(iic_buf,6);

    printf_tiny("Reset Source <0x%0X>\r\n", RESF);

    Data_Flash_init();
    Data_Flash_read();
    Data_Flash_write_test();
    Data_Flash_read();

    // check_reset_source();
    printf_tiny("%s finish\r\n\r\n",__func__);
    printf("[build time]%s,%s\r\n", __DATE__ ,__TIME__ );
}
