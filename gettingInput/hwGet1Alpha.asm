		.orig x3000
		LEA R0, PROMPT
		PUTS
		JSR GETALPHA
		JSR GETALPHA
		HALT

PROMPT		.stringz "Enter two letters: "
		  		

GETALPHA	ST R7, VAR7
		ST R1, VAR1
		ST R2, VAR2
		
TOP		GETC
		
		ADD R1, R0, #-10
		BRZ R_OUT

		LD R2, N95
		ADD R1, R0, R2
		BRZ PRINTCHAR

		LD R2, N40
		ADD R1, R0, R2
		BRNZ TOP

		LD R2, N91
		ADD R1, R0, R2
		BRN PRINTCHAR

		LD R2, N96
		ADD R1, R0, R2
		BRNZ TOP
		
		LD R2, N123
		ADD R1, R0, R2
		BRN PRINTCHAR
	
		BRNZP TOP

PRINTCHAR	OUT

R_OUT		LD R7, VAR7
		LD R1, VAR1
		LD R2, VAR2
		
		RET

VAR7		.fill 0
VAR1		.fill 0
VAR2		.fill 0

N95		.fill -95
N40		.fill -40
N91		.fill -91
N96		.fill -96
N123		.fill -123

		.end	
