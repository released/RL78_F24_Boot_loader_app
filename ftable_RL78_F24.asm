$INCLUDE "ftable.inc"
	.EXTERN _start
;	.EXTERN _f1
;	.EXTERN _f2
;	check Interrupt Source List in User’s Manual: Hardware
.jtext  .CSEG AT FLASH_TABLE                    ; Vector Name            		Vector Address Relocated Vector Address
                                                ;-------------           		-------------- ------------------------ 
         BR     !!_start                        ; RESET                         ;0x0000
		.DB4    0xffffffff                      ; Reserved                      ;0x0002
		.DB4    0xffffffff                      ; INTWDTI                       ;0x0004
		.DB4    0xffffffff                      ; INTLVI                        ;0x0006
		.DB4    0xffffffff			            ; INTP0                         ;0x0008
		.DB4    0xffffffff                      ; INTP1                         ;0x000A
		.DB4    0xffffffff			            ; INTP2                         ;0x000C
		.DB4    0xffffffff                      ; INTP3                         ;0x000E
		.DB4    0xffffffff			            ; INTP4/INTSPM                  ;0x0010
		.DB4    0xffffffff                      ; INTP5/INTCMP0      			;0x0012
		.DB4    0xffffffff                      ; INTP13/INTCL	             	;0x0014
		 BR     !!_r_Config_UART0_interrupt_send	; INTST0/INTCSI00/INTIIC00  ;0x0016
		 BR     !!_r_Config_UART0_interrupt_receive	; INTSR0/INTCSI01/INTIIC01 	;0x0018
		.DB4    0xffffffff						; INTTRD0                       ;0x001A
		.DB4    0xffffffff                      ; INTTRD1                       ;0x001C
		.DB4    0xffffffff                      ; INTTRJ0				        ;0x001E
		.DB4    0xffffffff                      ; INTRAM      					;0x0020
		.DB4    0xffffffff                      ; INTLIN0TRM 			        ;0x0022
		.DB4    0xffffffff					    ; INTLIN0RVC      				;0x0024
		.DB4    0xffffffff					    ; INTLIN0STA/INTLIN0	        ;0x0026
		 BR     !!_r_Config_IICA0_interrupt	    ; INTIICA0 		                ;0x0028
		.DB4    0xffffffff                      ; INTP8/INTRTC                  ;0x002A
		.DB4    0xffffffff      				; INTTM00                     	;0x002C
		 BR     !!_r_Config_TAU0_1_interrupt    ; INTTM01                       ;0x002E
		.DB4    0xffffffff                	    ; INTTM02                       ;0x0030
		.DB4    0xffffffff 					    ; INTTM03                       ;0x0032
		.DB4    0xffffffff                      ; INTAD                        	;0x0034
		.DB4    0xffffffff                      ; INTP6/INTTM11H                ;0x0036
		.DB4    0xffffffff                      ; INTP7/INTTM13H                ;0x0038
		.DB4    0xffffffff                      ; INTP9/INTTM01H                ;0x003A
		.DB4    0xffffffff                      ; INTP10/INTTM03H               ;0x003C
		 BR     !!_r_Config_UART1_interrupt_send	; INTST1/INTCSI10/INTIIC10      ;0x003E
		 BR     !!_r_Config_UART1_interrupt_receive	; INTSR1/INTCSI11/INTIIC11      ;0x0040
		.DB4    0xffffffff					    ; INTTM04                       ;0x0042
		.DB4    0xffffffff                      ; INTTM05                       ;0x0044
		.DB4    0xffffffff                      ; INTTM06                       ;0x0046
		.DB4    0xffffffff                      ; INTTM07                       ;0x0048
		.DB4    0xffffffff                      ; INTP11/INTLIN0WUP             ;0x004A
		.DB4    0xffffffff                      ; INTKR/INTRCANGRVC             ;0x004C
		.DB4    0xffffffff                      ; INTRCAN0ERR                   ;0x004E
		.DB4    0xffffffff                      ; INTRCAN0WUP                   ;0x0050
		.DB4    0xffffffff                      ; INTRCAN0CFR                   ;0x0052
		.DB4    0xffffffff                      ; INTRCAN0TRM                   ;0x0054
		.DB4    0xffffffff                      ; INTRCANGRFR                   ;0x0056
		.DB4    0xffffffff                      ; INTRCANGERR                   ;0x0058
		.DB4    0xffffffff                      ; INTTM10                      	;0x005A
		.DB4    0xffffffff                      ; INTTM11                      	;0x005C
		.DB4    0xffffffff                      ; INTTM12                      	;0x005E
		.DB4    0xffffffff                      ; INTTM13                      	;0x0060
		.DB4    0xffffffff                      ; Reserved                      ;0x0062
		.DB4    0xffffffff                      ; INTP12/INTLIN1WUP             ;0x0064
		.DB4    0xffffffff                      ; INTLIN1TRM                    ;0x0066
		.DB4    0xffffffff                      ; INTLIN1RVC                    ;0x0068
		.DB4    0xffffffff                      ; INTLIN1STA/INTLIN1            ;0x006A
		.DB4    0xffffffff                      ; INTTM14                      	;0x006C
		.DB4    0xffffffff                      ; INTTM15                      	;0x006E
		.DB4    0xffffffff                      ; INTTM16                      	;0x0070
		.DB4    0xffffffff                      ; INTTM17                      	;0x0072
		.DB4    0xffffffff                      ; Reserved                      ;0x0074
		.DB4    0xffffffff                      ; Reserved                      ;0x0076
		.DB4    0xffffffff                      ; INTADGB                      	;0x0078
		.DB4    0xffffffff                      ; INTCRAM                      	;0x007A
		.DB4    0xffffffff                      ; INTROM                      	;0x007C
		.DB4    0xffffffff                      ; BRK                           ;0x007E

;            ~ Omitted ~
;.jtext2 .CSEG AT FLASH_TABLE+INTERRUPT_OFFSET
;         BR     !!_f1
;         BR     !!_f2
