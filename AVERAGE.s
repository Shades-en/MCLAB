			AREA AVERAGE, CODE, READONLY
DIVIDEND	RN 4
DIVISOR		RN 5
QUOTIENT	RN 3
REMAINDER	RN 2
COUNT		RN 6
SUM 		RN 7
ENTRY
		LDR R0, =TABLE
		MOV COUNT, #5
		MOV SUM, #0
LOOP	LDRH R1, [R0], #2
		ADD SUM, SUM, R1
		SUBS COUNT, COUNT, #1
		BNE LOOP
		MOV DIVIDEND, SUM
		MOV DIVISOR, #5
		MOV QUOTIENT, #0
DIV		SUBS DIVIDEND, DIVIDEND, DIVISOR
		ADDPL QUOTIENT, QUOTIENT, #1
		BPL DIV
		ADDMI REMAINDER, DIVIDEND, DIVISOR
STOP	B STOP
TABLE	DCW 44, 78, 34, 64, 23
		END