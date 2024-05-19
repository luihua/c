/**
 * @file bitree.cpp
 * @author jia (1075524832@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#include "yy.hpp"

/// @brief 线索二叉树前驱指针，指向访问结点的前一结点
Threadnode *pre=NULL;//初始化结构体时将指针指向NULL，不会分配内存

unsigned int x;



/**
 * @brief 创建二叉树
 * 
 * @param T 二叉树
 */
void Initbitree(ThreadTree &T)
{   
    
    T=(ThreadTree)malloc(sizeof(Threadnode));
    T->left=NULL;
    T->right=NULL;
    T->ltag=0;
    T->rtag=0;
    CreateLeftTree(T);
    CreateLeftTree(T->left);
    CreatRightTree(T->left);
    CreatRightTree(T);
    CreatRightTree(T->right);
    T->data=4;
    T->left->data=2;
    T->left->left->data=1;
    T->left->right->data=3;
    T->right->data=5;
    T->right->right->data=6;
    
}

/*************************************************************************************************/

/*************************************************************************************************/

/**
 * @brief Create a Left Tree of a Node
 * 
 * @param p 
 */
void CreateLeftTree(Threadnode *p)
{
    Threadnode *q;
    q=(Threadnode*)malloc(sizeof(Threadnode));
    p->ltag=0;
    p->rtag=0;
    p->left=q;
    q->left=NULL;
    q->right=NULL;
    q->ltag=0;
    q->rtag=0;
} 

/*************************************************************************************************/

/*************************************************************************************************/


/**
 * @brief Create a Right Tree of a Node
 * 
 * @param p 
 */
void CreatRightTree(Threadnode *p)
{
    Threadnode *q;
    q=(Threadnode*)malloc(sizeof(Threadnode));
    p->ltag=0;
    p->rtag=0;
    p->right=q;
    q->left=NULL;
    q->right=NULL;
    q->ltag=0;
    q->rtag=0;
}


/*************************************************************************************************/

/*************************************************************************************************/


/**
 * @brief  递归中序遍历访问二叉树各结
 * 
 * @param T 二叉树指针
 * 
 */
void InThread(ThreadTree T)
{
    if(T!=NULL)//非空树
    {
        if(x==1)
            visit(T);
        if(T->ltag==0)//当使用先序线索化时需判断left不是前驱线索
            InThread(T->left);
        if(x==0)
            visit(T);
        InThread(T->right);
        if(x==2)
            visit(T);
        
    }
    
}

/*************************************************************************************************/

/*************************************************************************************************/


/**
 * @brief 访问函数，对二叉树实现线索化
 * 
 * @param p 
 */
void visit(Threadnode *p)
{
    if(p->left==NULL)//访问节点左子树空，将左子树用于指向前驱结点
       {
          p->left=pre;
          p->ltag=1;
       }

    if(pre->right==NULL&&pre!=NULL)//前驱结点右子树空，将右子树指向访问结点
       {
          pre->right=p;
          pre->rtag=1;
       }
    printf("%d",p->data);
    pre=p;
}

/*************************************************************************************************/

/*************************************************************************************************/


/**
 * @brief 二叉树的遍历时第一访问的结点
 * @param T 遍历的二叉树
 *
 * 
 * @return Threadnode* 指向第一个访问节点的指针
 */
Threadnode* Firstnode(ThreadTree T)
{
    if(x==0)//若中序遍历二叉树
    {
        while (T->ltag==0)
        {
            T=T->left;
        }
    }
    
    if(x==1)//若先序二叉遍历树
    {
    }

    if(x==2)//若后序二叉遍历树
    {
        while (T->ltag==0||T->rtag==0)//存在子树就一直向下搜寻
        { 
            while(T->ltag==0)//存在左子树就一直向左搜寻
            {
                T=T->left;
            }
            if(T->ltag==1&&T->rtag==0)//搜寻到不存在左子树但存在右子树则进入右子树
                T->right;
        }

    }
    return T;
}

/*************************************************************************************************/

/*************************************************************************************************/

/**
 * @brief 利用已经线索化实现非递归遍历二叉树
 *
 * 
 * @param T 
 */
void traversalBitree(ThreadTree T)
{   

    T=Firstnode(T);


    while (T!=NULL)
    {
        while (T->rtag==0)
        {
        
        
            printf("%d",T->data);
            if(x==0||x==1&&T->ltag==1)
                T=T->right;
            if(x==1&&T->ltag==0)
                T=T->left;
            if(x==2);


            T=Firstnode(T);
        
  
        }
        while (T->rtag==1)
        {
            printf("%d",T->data);
            T=T->right;
        if (T==NULL)
        {
            printf("\n");
            break;
        }
        
        
        
    }
    
    }
    
    

}



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

}