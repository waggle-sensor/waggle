#define SPH_MASK 0x07

.global __low_level_init
__low_level_init:

	;R31 stuck test
	R31_0x55_TST:
		ldi  R31, 0x55
		cpi  R31, 0x55
		breq  R31_0xAA_TST
		jmp  Failure
	R31_0xAA_TST:
		ldi  R31, 0xAA
		cpi  R31, 0xAA 
		breq  R30_0x55_TST 
		jmp  Failure

	;R30 stuck test
	R30_0x55_TST:  
		ldi  R30, 0x55
		cpi  R30, 0x55
		breq  R30_0xAA_TST
		jmp  Failure
	R30_0xAA_TST:  
		ldi  R30, 0xAA
		cpi  R30, 0xAA
		breq  R28_0x55_TST
		jmp  Failure

	;R29 stuck test
	R29_0x55_TST:  
		mov R31, R29   ;save R29    
		ldi  R29, 0x55   
		cpi  R29, 0x55
		breq  R29_0xAA_TST
		jmp  Failure
	R29_0xAA_TST:
		ldi  R29, 0xAA
		cpi  R29, 0xAA
		breq  R29_END_TST
		jmp  Failure
	R29_END_TST:
		mov R29, R31  ;restore R29

	;R28 stuck test
	R28_0x55_TST:  
		mov R31, R28   ;save R28
		ldi  R28, 0x55
		cpi  R28, 0x55
		breq  R28_0xAA_TST
		jmp  Failure
	R28_0xAA_TST:  
		ldi  R28, 0xAA
		cpi  R28, 0xAA
		breq  R28_END_TST
		jmp  Failure
	R28_END_TST:
		mov R28, R31  ;restore R28

	;R27 stuck test
	R27_0x55_TST:
		ldi  R27, 0x55
		cpi  R27, 0x55
		breq  R27_0xAA_TST
		jmp  Failure
	R27_0xAA_TST:  
		ldi  R27, 0xAA
		cpi  R27, 0xAA
		breq  R27_END_TST
		jmp  Failure
	R27_END_TST:

	;R0 to R27 stuck test
	RX_TST:        
		ldi  R30,0x00
		ldi  R31,0x00
	RX_0x55_TST:   
		ldi  R27,0x55
		st  Z,R27
		ldi  R27,0x00
		ld  R27,Z
		cpi  R27,0x55
		breq  RX_0xAA_TST
		jmp  Failure
	RX_0xAA_TST:   
		ldi  R27,0xAA
		ST  Z,R27
		ldi  R27,0x00
		ld  R27,Z+
		cpi  R27, 0xAA
		breq  RX_TST_2
		jmp  Failure
	RX_TST_2:      
		cpi  r30,27  ;test until R27
		brne  RX_0x55_TST 

	;Stack pointer Stuck Test (16 bit Stack pointer)
	;Save SP values
	SP_TST:        
		in    R23,0x3E
		in    R22,0x3D
	SPL_0x55_TST:  
		ldi   R24,0x55
		out   0x3D,R24
		in    R24,0x3D
		cpi   R24,0x55
		breq  SPL_0xAA_TST
		jmp   Failure
	SPL_0xAA_TST:  
		ldi   R24,0xAA
		out   0x3D,R24
		in    R24,0x3D
		cpi   R24,0xAA
		breq  SPH_0x55_TST
		jmp   Failure
	SPH_0x55_TST:  
		ldi   R25,SPH_MASK
		andi  R25,0x55
		out   0x3E,R25
		in    R24,0x3E
		cp    R24,R25
		breq  SPH_0xAA_TST
		jmp   Failure
	SPH_0xAA_TST:  
		ldi   R25,SPH_MASK
		andi  R25,0xAA
		out   0x3E,R25
		in    R24,0x3E
		cp    R24,R25
		breq  RESTORE_SP
		jmp   Failure
	RESTORE_SP:    
		out   0x3E,R23
		out   0x3D,R22
		rjmp  ALL_TEST_OK

	;Stop here on failure
	Failure:        
		jmp Failure
	ALL_TEST_OK: