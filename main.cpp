#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yy.hpp"
int main()
{   
    printf("x=0中序遍历二叉树,x=1先序遍历二叉树\n");
    scanf("%d",&x);
    ThreadTree T=NULL;
    pre=(Threadnode*)malloc(sizeof(Threadnode));
   // pre=NULL;
    pre->left=NULL;
    pre->right=NULL;
    Initbitree(T);
    InThread(T);    
    if(pre->right==NULL)//处理最后访问节点
       pre->rtag=1;
    printf("\n");
    traversalBitree(T);
    return 0;

}