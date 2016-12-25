

Name 				- Prashant Kadam
Email id			- pkadam1@binghamton.edu
the language used 	- C

-------------------------------------------------
instructions for compiling and running the code
-------------------------------------------------

To Compile Both the programs - 
		bingsuns2% make

	--------------------------
	information for program 1 -
	---------------------------

		To Run Program 1 with command line argument 3 i.e. Number = 3  use following command
				bingsuns2%  make run_program1_3

		explanation of Run Commands-  	

			information for program 1 - 
					1.the above command will run program 1 for number = 3 this will print all combination in out1.txt . 
					2.the new output will be appended at the end of already available content. 
					3.In my make file I am using 3 as command line argumnt for above command. 
					4.similary for number higher than 3, command name in makefile will only vary in last digit ,
						 meaning for number 4 Command is "make run_program1_4" for number 5 it is "make run_program1_5" , and so on. 
						 underline target for is "make run_program1_4" is   "./program_1 4 >> out2.txt" (here 4 is command line argument)
						 follwing are all commands

						 - make run_program1_3
						 - make run_program1_4
						 - make run_program1_5
						 - make run_program1_6
						 - make run_program1_7
						 - make run_program1_8
						 - make run_program1_8
						 - make run_program1_9
						 - make run_program1_10
						 - make run_program1_11

					5.for all run command except "run_program1_3" , output will be appended in out2.txt

				Note : 
					for all run command except "run_program1_3" , I am not printing the output. so "printf -> number" will not be executed. So time for this statement is not measured.

					for n = 11   -> its taking too many seconds so harrdcoded in out2.txt ---- "Cpu Limit Exceeded"

	--------------------------
	information for program 2 -
	---------------------------
		To Run Program 2 with command line argument 3 i.e. Number = 3  use follwoing command
				bingsuns2%  make run_program2_3 			
							- this will print output to Console....

	--------------------------
	information to clean files -
	---------------------------
		To Clean files use follwoing make run command
			 make clean -  this wil delete .o files for both programs



Request - Please let me know if you need more information to run my programs .. Thanks..

