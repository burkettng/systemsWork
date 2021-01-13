		.orig x3000
		LEA R0, STR1
		LEA R1, STR2
		JSR STRCAT
		PUTS
		HALT

		.blkw 100
STR1		.stringz "Hello-"

		.blkw 100
STR2		.stringz "World\n"

		JSR FINDLAST
