#include<stdio.h>
int isDigitRepeatedInNumber(int n)
{
  int numberPresentFlags[10]={0};
  int index;
  while(n>0)
  {
    index=n%10;
    if(numberPresentFlags[index]>0)
    {
      return  1;  // repeated digit detected so return 1
    }
    else{
      numberPresentFlags[index]++;
    }
    n=n/10;
  }
return  0;        // repeated digit detected so return 0
}

void recursiveWithoutduplicate(int n, int current_depth,int depth)
{
int i=0;
    for(i=0;i<depth;i++)
    {
      n=n*10+(i+1);
        if(current_depth+1==depth)
            {
                if(isDigitRepeatedInNumber(n)!=1)
                   printf("%d\n",n);
                   n=n/10;
            }
            else
            {
                recursiveWithoutduplicate(n,current_depth+1,depth);//call to recusive function
                n=n/10;
            }
    }
}


int main(int argc, char* argv[])
{
  int number = atoi(argv[1]);
  int x=1;
  int  current_depth=1;
  while(x<=number){
         recursiveWithoutduplicate(x,current_depth,number); //first call to recusive function
         x=x+1;
    }
  return 0;
}
