#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG 0
int n,m,sizeC;
int isNoSatisfyingSoution=0;
int printFirstSoluOnly=0;
int manySoution=0;
FILE *fo;
clock_t t1;
int ispromising(int depth,int x[],int c[][sizeC])
{
    if (depth==0) return 1;
    int i,j;
    int c_Copy[m][sizeC];
    if(DEBUG)
    	printf("\ndepth is %d\n", depth);
    //int m=depth+1;
    int ClauseAns[m];
    int Dintermediate[m][sizeC];
    for(i=0;i<m;i++)
    for(j=0;j<sizeC;j++)
    {
       c_Copy[i][j]=c[i][j]; 
    }
    //copy C array to D array ;
    for(i=0;i<m;i++)
    for(j=0;j<sizeC;j++)
    {
        if(c_Copy[i][j]<0)
        {
            int t = c_Copy[i][j]*-1;
            if(t>depth)
                Dintermediate[i][j] = 1;
            else
                Dintermediate[i][j]=x[((c_Copy[i][j])*-1)-1]?0:1;
        }
        else
        {
            int t = c_Copy[i][j];
            if(t>depth)
                Dintermediate[i][j] = 1;
            else
                Dintermediate[i][j]=x[(c_Copy[i][j])-1];
        }
    }
      //evaluate clauses
    i=0;j=0;
    for(i=0;i<m;i++)
    for(j=0;j<sizeC;j++)
    {
        if(Dintermediate[i][j]==1)
            {
                ClauseAns[i]=1;
                break;
            }
        else
            {
                ClauseAns[i]=0;
            }
    }
    i=0;
    int isSolution =1;
    for(i=0;i<m;i++)
    {
        if(ClauseAns[i]==0)
        {
            isSolution =0;
            break;
        }
    }
    if(isSolution)
    {
         return 1;
    }
        return 0;
}


int willAllBeTrue(int depth,int x[],int c[][sizeC])
{
    if (depth==0) return 0;
    int i,j;
    int c_Copy[m][sizeC];
    if(DEBUG)
   	 	printf("\ndepth is %d\n", depth);
    //int m=depth+1;
    int ClauseAns[m];
    int ClauseAns1[m];
    int Dintermediate[m][sizeC];
    int Dintermediate1[m][sizeC];
    for(i=0;i<m;i++)
    for(j=0;j<sizeC;j++)
    {
       c_Copy[i][j]=c[i][j]; 
    }
    //copy C array to D array ;
    for(i=0;i<m;i++)
    for(j=0;j<sizeC;j++)
    {
        if(c_Copy[i][j]<0)
        {
            int t = c_Copy[i][j]*-1;
            if(t>depth)
            {
                Dintermediate[i][j] = 1;
                Dintermediate1[i][j] = 0;
            }
            else
            {
                Dintermediate[i][j]=x[((c_Copy[i][j])*-1)-1]?0:1;
                Dintermediate1[i][j]=x[((c_Copy[i][j])*-1)-1]?0:1;
            }
        }
        else
        {
            int t = c_Copy[i][j];
            if(t>depth)
            {
                Dintermediate[i][j] = 1;
                Dintermediate1[i][j] = 0;
            }
            else
            {
                Dintermediate[i][j]=x[(c_Copy[i][j])-1];
                Dintermediate1[i][j]=x[(c_Copy[i][j])-1];
            }
        }
    }
      //evaluate clauses
    i=0;j=0;
    for(i=0;i<m;i++)
    for(j=0;j<sizeC;j++)
    {
        if(Dintermediate[i][j]==1)
            {
                ClauseAns[i]=1;
                break;
            }
        else
            {
                ClauseAns[i]=0;
            }
    }
    i=0;
    int isSolution =1;
    for(i=0;i<m;i++)
    {
        if(ClauseAns[i]==0)
        {
            isSolution =0;
            break;
        }
    }

    //evaluate clauses
    i=0;j=0;
    for(i=0;i<m;i++)
    for(j=0;j<sizeC;j++)
    {
        if(Dintermediate1[i][j]==1)
            {
                ClauseAns1[i]=1;
                break;
            }
        else
            {
                ClauseAns1[i]=0;
            }
    }
    i=0;
    int isSolution1 =1;
    for(i=0;i<m;i++)
    {
        if(ClauseAns1[i]==0)
        {
            isSolution1 =0;
            break;
        }
    }

    if(isSolution && isSolution1)
    {
         return 1;
    }
        return 0;
}


void backtrackCompute(int depth,int n,int x[],int clause[][sizeC]) {
            if(willAllBeTrue(depth,x,clause))
            {
                isNoSatisfyingSoution=1;
                if(n<=5)
                {
                    fprintf(fo, "%s","The solution is \n");
                    int temp=0;
                    for(temp=0;temp<depth;temp++)
                    {
                        fprintf(fo,"x[%d]=%d \n",temp+1,x[temp]);
                    }
                }
                if(n>5 && m>30)
                {
                    manySoution =1;
                    fprintf(fo,"\nThere are satisfying assignments\n");
                    t1 = clock() - t1;
				    double time_req = (((double)t1)/CLOCKS_PER_SEC)*1000;
				    fprintf(fo,"\"Run time is %.4f milliSeconds\"\n",time_req);
    				fclose(fo);
    				exit(0);
                }
                if(n>5 && m<=30 && printFirstSoluOnly==0)
                {
                    printFirstSoluOnly=1;
                    fprintf(fo,"\nThe solution is \n");
                    int temp=0;
                    for(temp=0;temp<depth;temp++)
                    {
                        fprintf(fo,"x[%d]=%d \n",temp+1,x[temp]);
                    }
                    t1 = clock() - t1;
				    double time_req = (((double)t1)/CLOCKS_PER_SEC)*1000;
				    fprintf(fo,"\"Run time is %.4f milliSeconds\"\n",time_req);
    				fclose(fo);
    				exit(0);
                }
                return;
            }
            else
            {
                   if(isNoSatisfyingSoution!=1)
                        isNoSatisfyingSoution=0;
            }
    if(ispromising(depth,x,clause))
    {
        if(DEBUG)
        {
        	printf("%d depth is promising\n",depth);
        	printf("x is  ");
        }
        int r=0;
        if(DEBUG)
        {
        for(r=0;r<depth;r++)
            printf("%d  ",x[r]);
       	}
    	x[depth]=1;
    	backtrackCompute(depth+1,n,x,clause);
    	x[depth]=0;
    	backtrackCompute(depth+1,n,x,clause);
    }
    else
    {
    	if(DEBUG)
        {
	        printf("%d depth is not promising\n",depth );
	        printf("x is  ");	   
            int r=0;
            for(r=0;r<depth;r++)        
                	printf("%d ",x[r]);
         }
       
    }
   }

int main(int argc, char* argv[])
{
    int Line1_i[3]={0};
    int i=0,j=0;
    FILE *fp;
    char* filename= argv[1];
    fp= fopen(filename,"r");
    if(fp==NULL)
        {
            fprintf(fo,"%s","No File exists...\n");
            exit(0);
        }
    for (i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &Line1_i[i] );
        }
    n=Line1_i[0];
    m=Line1_i[1];
    sizeC =Line1_i[2];
    //Now declare array wth required size  -  input.txt values file
    int clauseCopysize= (m*sizeC)+3;
    int clause[m][sizeC];
    int clauseCopy[clauseCopysize];
    int x[n];
    int t;
    int totalSize = m*sizeC;
    for (t = 0; t <totalSize ; t++)
        for(i=0;i<m;i++)
            for(j=0;j<sizeC;j++)
            {
                fscanf(fp, "%d", &clause[i][j] );
            }
    fclose(fp);
    fo=fopen(argv[2],"w");
    t1=clock();
    backtrackCompute(0,n,x,clause);
    if(isNoSatisfyingSoution==0)
        fprintf(fo,"%s","\nNo satisfying assignment.\n");
    t1 = clock() - t1;
    double time_req = (((double)t1)/CLOCKS_PER_SEC)*1000;
    fprintf(fo,"\"Run time is %.4f milliSeconds\"\n",time_req);
    fclose(fo);
    return 0;
}
