all:program_1 program_2

program_1:   program_1.c
			 gcc -o program_1 program_1.c -lm
program_2:   program_2.c
			 gcc -o program_2 program_2.c -lm
run_program1_3:
	./program_1 3 >> out1.txt
run_program1_4:
	./program_1 4 >> out2.txt
run_program1_5:
	./program_1 5 >> out2.txt
run_program1_6:
	./program_1 6 >> out2.txt
run_program1_7:
	./program_1 7 >> out2.txt
run_program1_8:
	./program_1 8 >> out2.txt
run_program1_9:
	./program_1 9 >> out2.txt
run_program1_10:
	./program_1 10 >> out2.txt
run_program1_11:
	./program_1 11 >> out2.txt
run_program2_3:
	./program_2 3
clean:
	rm -f program_1 out1.txt out2.txt program_2  *~

