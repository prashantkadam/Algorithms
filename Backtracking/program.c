#include<stdio.h>
#include<time.h>
FILE *fp, *fp1;
int n,m,clause_size;
int clause=0, counter=0, counter1=0, flag=0, print_flag=0, tempclause_flag=0;
int print_clause=1;
int Temp_clausevalue[100], x[1000], clause_value[100];

int promising(int depth)
{
	int i,z,j;
	
	rewind(fp);
        fscanf(fp, "%d %d %d ", &n, &m, &clause_size);
	
	
	
	for(i=0;i<m;i++)
	{
		Temp_clausevalue[i] = 110;
	}
	
	if(depth==0)
        {
                return 1;
        }
	else if(depth <= n)
	{
		
		tempclause_flag = 0;
		print_clause = 1;
                for(j=0;j<m;j++)
                {
			
			clause = 0;
       	        	for(i=0;i<clause_size;i++)
                	{
				
                		fscanf(fp,"%d",&clause_value[i]);
				
       	        		if(clause_value[i]>0)
                        	{
					
         	        		z = clause_value[i];
					z--;
					
					if(x[z] == 111)
						clause = 50;
					else
                        			clause = clause | x[z];

					
                        	}
                        	else
                        	{
                        		z = -1*clause_value[i];
                        		z--;
					
					if(x[z] == 111)
						clause = 50;
					else
                        			clause = clause | !x[z];
                        	}
				
				
				
					if(clause == 50)
					{
						if(Temp_clausevalue[j] == 1)
							Temp_clausevalue[j] = 1;
						else
							Temp_clausevalue[j] = clause;	
					}
					else if(clause > 50 || clause == 1)
						Temp_clausevalue[j] = 1;

					
						
			}
			
		}

		for(i=0;i<m;i++)
		{
			if(Temp_clausevalue[i] == 1)
			{
				tempclause_flag++ ;
			}
			else if(Temp_clausevalue[i] == 50)
			{
				
				return 1;
			}
			else
			{
				
				return 0;
			}
		}
		
		if(tempclause_flag == m)
		{
			flag = 1;
			if(n>5 && m>30)
                        {
                                if(counter1<1)
                                {
                                        fprintf(fp1,"There is satisfying assignments.\n");
                                        counter1=1;

                                }
                        }
			else
			{
				if(n>5 && m<=30)
                                {
                                        if(counter<n)
                                        {
                                                fprintf(fp1,"solution is: \n");
                                                for(i=0;i<depth;i++)
                                                {
                                                        fprintf(fp1," x[%d] = %d\n",i+1,x[i]);
                                                        counter++;
                                                }
						fprintf(fp1,"There is a satisfying assignment.\n");
						
                                        }
                                }
				else	
				{
					fprintf(fp1,"The solution is:\n");
					for(i=0;i<depth;i++)
        				{
        					fprintf(fp1,"x[%d]=%d\n",i+1,x[i]);
        				}
				
					return 0;
				}
			}
		}
		else 
		{
					
			return 0;
		}

        }
	else
		return 0;
}	

void initialize(int d)
{
	int i;
	for(i=d;i<110;i++)
	{
		x[i] = 111;
	}

}

void backTrackCompute(int depth)
{
        int i,j,z,k=n;
	
	
	initialize(depth);



	if(promising(depth))
	{	
        	x[depth]=1;
		
        	backTrackCompute(depth+1);
        	x[depth]=0;
		
        	backTrackCompute(depth+1);
	}
	
}




int main(int argc, char *argv[])
{
        int i;
        clock_t start, end;
        double cpu_time_used;
	for(i=0;i<110;i++)
	{
		x[i] = 111;
	}
	

        fp = fopen(argv[1], "r");
        fp1 = fopen(argv[2],"w");

        if(!fp)
        {
                printf("\n Error while proccesing input file\n Please give input file.txt\n");
                return 0;
        }
        fscanf(fp,"%d %d %d", &n, &m, &clause_size);
	//int x[n],clause_value[n];
        start = clock();
        backTrackCompute(0);
        end = clock();
	if(flag != 1)
        {
                fprintf(fp1,"There are no satisfying assignments.\n");
        }

        cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1000;
        fprintf(fp1,"The Run time is %f milliseconds.\n",cpu_time_used);
        fclose(fp);
        fclose(fp1);

        return 0;

}
