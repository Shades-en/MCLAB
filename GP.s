			AREA  GP, CODE, READONLY
A		RN 0
R		RN 1
N 		RN 2
ENTRY
		MOV A, #1
		MOV R, #2
		MOV N, #5
		LDR R3, =0X40000000
LOOP 	STR A, [R3], #4
		MUL A, R, A
		SUBS N, N, #1
		BNE LOOP
STOP	B STOP
		END
		
		
		
		