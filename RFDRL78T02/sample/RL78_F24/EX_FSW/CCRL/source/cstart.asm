;/**********************************************************************************************************************
; * DISCLAIMER
; * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
; * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
; * applicable laws, including copyright laws.
; * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
; * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
; * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
; * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
; * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
; * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
; * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
; * this software. By using this software, you agree to the additional terms and conditions found by accessing the
; * following link:
; * http://www.renesas.com/disclaimer
; *
; * Copyright (C) 2021-2022 Renesas Electronics Corporation. All rights reserved.
; *********************************************************************************************************************/
;   NOTE       : THIS IS A TYPICAL EXAMPLE.

$IFNDEF __RENESAS_VERSION__
__RENESAS_VERSION__	.EQU	0x01000000
$ENDIF

	.public	_start
	.public _exit

;-----------------------------------------------------------------------------
;	RAM section
;-----------------------------------------------------------------------------
.SECTION .dataR, DATA
.SECTION .sdataR, DATA
.SECTION RFD_DATA_nR, DATA
.SECTION RFD_CMN_fR, TEXTF
.SECTION RFD_EX_fR, TEXTF
.SECTION SMP_CMN_fR, TEXTF
.SECTION SMP_EX_fR, TEXTF
; .SECTION .datafR, DATAF
; .SECTION .textfR, TEXTF

;$IF (__RENESAS_VERSION__ < 0x01010000)	; for CC-RL V1.00
;-----------------------------------------------------------------------------
;	stack area
;-----------------------------------------------------------------------------
; !!! [CAUTION] !!!
; Set up stack size suitable for a project.
.SECTION .stack_bss, BSS
_stackend:
	.DS     0x500
_stacktop:
;$ENDIF

;-----------------------------------------------------------------------------
;	RESET vector
;-----------------------------------------------------------------------------
_start	.VECTOR	0

;-----------------------------------------------------------------------------
;	startup
;-----------------------------------------------------------------------------
.SECTION .text, TEXT
_start:
	;--------------------------------------------------
	; setting register bank
	;--------------------------------------------------
;	SEL	RB0

	;--------------------------------------------------
	; setting mirror area
	;--------------------------------------------------
;	ONEB    !PMC		; mirror area = 10000-1FFFFH

	;--------------------------------------------------
	; setting RAMSAR=0x9F RAM area is 24KB (RL78/F24)
	;--------------------------------------------------
	MOV !RAMSAR, #0x9F
	NOP
	NOP

	;--------------------------------------------------
	; setting the stack pointer
	;--------------------------------------------------
;$IF (__RENESAS_VERSION__ >= 0x01010000)
;	MOVW	SP,#LOWW(__STACK_ADDR_START)
;$ELSE	; for CC-RL V1.00
	MOVW	SP,#LOWW(_stacktop)
;$ENDIF

	;--------------------------------------------------
	; initializing stack area
	;--------------------------------------------------
;$IF (__RENESAS_VERSION__ >= 0x01010000)
;	MOVW	AX,#LOWW(__STACK_ADDR_END)
;$ELSE	; for CC-RL V1.00
	MOVW	AX,#LOWW(_stackend)
;$ENDIF
	CALL	!!_stkinit

	;--------------------------------------------------
	; hardware initialization
	;--------------------------------------------------
	CALL	!!_hdwinit

	;--------------------------------------------------
	; initializing BSS
	;--------------------------------------------------
	; clear external variables which doesn't have initial value (near)
	MOVW	HL,#LOWW(STARTOF(.bss))
	MOVW	AX,#LOWW(STARTOF(.bss) + SIZEOF(.bss))
	BR	$.L2_BSS
.L1_BSS:
	MOV	[HL+0],#0
	INCW	HL
.L2_BSS:
	CMPW	AX,HL
	BNZ	$.L1_BSS

	; clear saddr variables which doesn't have initial value
	MOVW	HL,#LOWW(STARTOF(.sbss))
	MOVW	AX,#LOWW(STARTOF(.sbss) + SIZEOF(.sbss))
	BR	$.L2_SBSS
.L1_SBSS:
	MOV	[HL+0],#0
	INCW	HL
.L2_SBSS:
	CMPW	AX,HL
	BNZ	$.L1_SBSS

	; clear external variables which doesn't have initial value (far)
;	MOV	ES,#HIGHW(STARTOF(.bssf))
;	MOVW	HL,#LOWW(STARTOF(.bssf))
;	MOVW	AX,#LOWW(STARTOF(.bssf) + SIZEOF(.bssf))
;	BR	$.L2_BSSF
;.L1_BSSF:
;	MOV	ES:[HL+0],#0
;	INCW	HL
;.L2_BSSF:
;	CMPW	AX,HL
;	BNZ	$.L1_BSSF

	;--------------------------------------------------
	; ROM data copy
	;--------------------------------------------------
	; copy external variables having initial value (near)
	MOV	ES,#HIGHW(STARTOF(.data))
	MOVW	BC,#LOWW(SIZEOF(.data))
	BR	$.L2_DATA
.L1_DATA:
	DECW	BC
	MOV	A,ES:LOWW(STARTOF(.data))[BC]
	MOV	LOWW(STARTOF(.dataR))[BC],A
.L2_DATA:
	CLRW	AX
	CMPW	AX,BC
	BNZ	$.L1_DATA

	; copy saddr variables having initial value
	MOV	ES,#HIGHW(STARTOF(.sdata))
	MOVW	BC,#LOWW(SIZEOF(.sdata))
	BR	$.L2_SDATA
.L1_SDATA:
	DECW	BC
	MOV	A,ES:LOWW(STARTOF(.sdata))[BC]
	MOV	LOWW(STARTOF(.sdataR))[BC],A
.L2_SDATA:
	CLRW	AX
	CMPW	AX,BC
	BNZ	$.L1_SDATA

	; copy RFD external variables having initial value (near)
	MOV	ES,#HIGHW(STARTOF(RFD_DATA_n))
	MOVW	BC,#LOWW(SIZEOF(RFD_DATA_n))
	BR	$.L2_RFD_DATA
.L1_RFD_DATA:
	DECW	BC
	MOV	A,ES:LOWW(STARTOF(RFD_DATA_n))[BC]
	MOV	LOWW(STARTOF(RFD_DATA_nR))[BC],A
.L2_RFD_DATA:
	CLRW	AX
	CMPW	AX,BC
	BNZ	$.L1_RFD_DATA

	; copy external variables having initial value (far)
;	MOVW	BC,#LOWW(SIZEOF(.dataf))
;	BR	$.L2_DATAF
;.L1_DATAF:
;	DECW	BC
;	MOV	ES,#HIGHW(STARTOF(.dataf))
;	MOV	A,ES:LOWW(STARTOF(.dataf))[BC]
;	MOV	ES,#HIGHW(STARTOF(.datafR))
;	MOV	ES:LOWW(STARTOF(.datafR))[BC],A
;.L2_DATAF:
;	CLRW	AX
;	CMPW	AX,BC
;	BNZ	$.L1_DATAF
;;;;;;;;;;;;;;;;;;;;;
	; copy code to RAM (RFD_CMN)
	MOV	C,#HIGHW(STARTOF(RFD_CMN_f))
	MOVW	HL,#LOWW(STARTOF(RFD_CMN_f))
	MOVW	DE,#LOWW(STARTOF(RFD_CMN_fR))
	BR	$.L12_TEXT
.L11_TEXT:
	MOV	A,C
	MOV	ES,A
	MOV	A,ES:[HL]
	MOV	[DE],A
	INCW	DE
	INCW	HL
	CLRW	AX
	CMPW	AX,HL
	SKNZ
	INC	C
.L12_TEXT:
	MOVW	AX,HL
	CMPW	AX,#LOWW(STARTOF(RFD_CMN_f) + SIZEOF(RFD_CMN_f))
	BNZ	$.L11_TEXT

	; copy code to RAM (RFD_EX)
	MOV	C,#HIGHW(STARTOF(RFD_EX_f))
	MOVW	HL,#LOWW(STARTOF(RFD_EX_f))
	MOVW	DE,#LOWW(STARTOF(RFD_EX_fR))
	BR	$.L22_TEXT
.L21_TEXT:
	MOV	A,C
	MOV	ES,A
	MOV	A,ES:[HL]
	MOV	[DE],A
	INCW	DE
	INCW	HL
	CLRW	AX
	CMPW	AX,HL
	SKNZ
	INC	C
.L22_TEXT:
	MOVW	AX,HL
	CMPW	AX,#LOWW(STARTOF(RFD_EX_f) + SIZEOF(RFD_EX_f))
	BNZ	$.L21_TEXT

	; copy code to RAM (SMP_CMN)
	MOV	C,#HIGHW(STARTOF(SMP_CMN_f))
	MOVW	HL,#LOWW(STARTOF(SMP_CMN_f))
	MOVW	DE,#LOWW(STARTOF(SMP_CMN_fR))
	BR	$.L32_TEXT
.L31_TEXT:
	MOV	A,C
	MOV	ES,A
	MOV	A,ES:[HL]
	MOV	[DE],A
	INCW	DE
	INCW	HL
	CLRW	AX
	CMPW	AX,HL
	SKNZ
	INC	C
.L32_TEXT:
	MOVW	AX,HL
	CMPW	AX,#LOWW(STARTOF(SMP_CMN_f) + SIZEOF(SMP_CMN_f))
	BNZ	$.L31_TEXT

	; copy code to RAM (SMP_EX)
	MOV	C,#HIGHW(STARTOF(SMP_EX_f))
	MOVW	HL,#LOWW(STARTOF(SMP_EX_f))
	MOVW	DE,#LOWW(STARTOF(SMP_EX_fR))
	BR	$.L42_TEXT
.L41_TEXT:
	MOV	A,C
	MOV	ES,A
	MOV	A,ES:[HL]
	MOV	[DE],A
	INCW	DE
	INCW	HL
	CLRW	AX
	CMPW	AX,HL
	SKNZ
	INC	C
.L42_TEXT:
	MOVW	AX,HL
	CMPW	AX,#LOWW(STARTOF(SMP_EX_f) + SIZEOF(SMP_EX_f))
	BNZ	$.L41_TEXT

	;--------------------------------------------------
	; call main function
	;--------------------------------------------------
	CALL	!!_main		; main();

	;--------------------------------------------------
	; call exit function
	;--------------------------------------------------
	CLRW	AX		; exit(0)
_exit:
	BR	$_exit

;-----------------------------------------------------------------------------
;	section
;-----------------------------------------------------------------------------
$IF (__RENESAS_VERSION__ >= 0x01010000)
.SECTION .RLIB, TEXTF
.L_section_RLIB:
.SECTION .SLIB, TEXTF
.L_section_SLIB:
$ENDIF
.SECTION .textf, TEXTF
.L_section_textf:
.SECTION .const, CONST
.L_section_const:
.SECTION .constf, CONSTF
.L_section_constf:
.SECTION .data, DATA
.L_section_data:
;.SECTION .dataf, DATAF
;.L_section_dataf:
.SECTION .sdata, SDATA
.L_section_sdata:
.SECTION .bss, BSS
.L_section_bss:
;.SECTION .bssf, BSSF
;.L_section_bssf:
.SECTION .sbss, SBSS
.L_section_sbss:
