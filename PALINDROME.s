			AREA PALINDROME, CODE, READONLY
ENTRY
		LDR R1, =123321
		MOV R6, R1
		MOV R2, #10
		MOV R3, #0
LOOP	BL DIV
		MLA R3, R2, R3, R5
		MOV R1, R4
		CMP R1, #0
		BNE LOOP
		CMP R6, R3
		MOVEQ R7, #1
		MOVNE R7, #0
STOP	B STOP
DIV		MOV R4, #0
RPT		SUBS R1, R1, R2
		ADDPL R4, R4, #1
		BPL RPT
		ADDMI R5, R1, R2
		BX LR
		END