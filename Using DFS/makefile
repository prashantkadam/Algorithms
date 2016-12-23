all:clean dfsCompute run

dfsCompute:   dfsCompute.c
			 gcc -o submission dfsCompute.c -lm
run:
			./submission input0.txt output0.txt
			./submission input1.txt output1.txt
			./submission input2.txt output2.txt
			./submission input4.txt output4.txt
			./submission input5.txt output5.txt
clean:
	rm -f submission *~

