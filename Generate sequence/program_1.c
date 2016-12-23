#include<stdio.h>
#include<time.h>
int printOutput=1;
void recursive(int n, int current_depth,int depth,int printOutput)
{
int i=0;
    for(i=0;i<depth;i++)
    {
      n=n*10+(i+1);
        if(current_depth+1==depth)
            {
              if(printOutput==1)
                    printf("%d , ",n);
                    n=n/10;
            }
            else
            {
                recursive(n,current_depth+1,depth,printOutput);
                n=n/10;
            }
    }
}
int main(int argc, char* argv[])
{
    int  current_depth=1;
    int depth =atoi(argv[1]);
    clock_t t1=clock();
    int x=1;
    int printOutput=0;
    if(depth==3)
        printOutput=1;
    while(x<=depth){
    	   recursive(x,current_depth,depth,printOutput);
         x=x+1;
         if(printOutput==1)
         printf("\n");
    }
    t1 = clock() - t1;
    double time_req = ((double)t1)/CLOCKS_PER_SEC;
    printf("\"The Run time for generating all sequences of size %d is \" %f \"seconds\" \n",depth, time_req);
    return 0;
}

