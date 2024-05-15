#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "stack.hpp"




void InitStack(Sqstack &S)
{
  S.top=-1;
}

bool Push(Sqstack &S, int PushNumber)
{
   if(S.top==MAXSIZE-1)
    {
      printf("Stack is full,push error\n");
      return false;
    }
    S.top++;
    S.data[S.top]=PushNumber;//先加指针在压栈
    return true;

}

bool pop(Sqstack &S, int &PopNumber)
{
    if(S.top==-1)
    {
        printf("Stack is empty,pop error\n");
        return false;
    }

    PopNumber=S.data[S.top];//先出栈后减指针
    S.top--;
    return true;


}

bool getall(Sqstack S, int *GetNumber)
{
    int temp;//存放每次pop值；
    
    if(S.top==-1)
    {
        printf("Stack is empty,get top error\n");
        return false;

    }
    while(1)
    {
       if(pop(S,temp)==false)
       return true;
       GetNumber[S.top+1]=temp;
       

    }



    



}



int main()
{
    Sqstack S;
    InitStack(S);
    int x,popnum,i;
    printf("push value:\n");
    scanf("%d",&x);

    while (x!=999)
    {
        
        if(Push(S,x)==false)//栈满，跳出循环
        {
            break;
        }
        i++;
        if(i%3==0)//入栈3次弹出一次
        {
           if(pop(S,popnum))
                printf("pop number=%d\n",popnum);
        }
        printf("push value:\n");
        scanf("%d",&x);

    }
    
    for(int i=0;i<S.top+1;i++)
    {
        if(i==0)
        printf("STACK:%d",S.data[i]);
        else
        printf("->%d",S.data[i]);


    }

    
    return 0;

}