#pragma once
#ifndef _YY_H
#define _YY_H
#endif



/*******************************************MACRO-BEGIN*******************************************/
/*************************************************************************************************/

#define HARDWARE 0
#define SOFTWARE 1
#define ALL 2
#define MAXSIZE 10

/*************************************************************************************************/
/*******************************************MACRO-END*********************************************/


/*******************************************TYPEDEF-BEGIN*******************************************/
/***************************************************************************************************/

typedef struct LNode//单链表
{
    int data;
    struct LNode* next;

}*Linklist,Lnode;
typedef struct DLNode//双链表
{
    int data;
    struct DLNode *next, *prior;

}*DLinklist,DLnode;
typedef struct //循环队列队头队尾指针
{
    Lnode *front,*rear;
    
}QueueLink;

typedef struct ThreadNode//线索二叉树结点
{
   int data;
   struct ThreadNode *left, *right;//左右子结点或前后继结点
   int ltag, rtag;//左右线索标志
}Threadnode, *ThreadTree;

typedef struct People//图节点数据类型
{
    char name[20];
    bool IsTeacher;
    int Group;
}people;


typedef struct MgGraph//邻接矩阵存储图
{
    people Vex[MAXSIZE];//静态数组存顶点
    int Edge[MAXSIZE*(MAXSIZE-1)/2];//对称矩阵使用一阶数组压缩储存
    int vexnum,arcnum;//顶点数目和边数(弧数)
}mggraph;
/*******************************************TYPEDEF-END*******************************************/
/*************************************************************************************************/



bool PrintLinklist(Linklist L);
Linklist InitList(Linklist &L);
LNode* Findlist(int i, Linklist L);
bool PreInsertNode(int i, int e, Linklist &L);
bool InsertPriorNode(Lnode *p, int e);
Linklist RInitList(Linklist &L);
bool InsertNode(int i, int e , Linklist &L);
bool PrintLinklist(DLinklist DL);
int LinkListLength(Linklist L);
DLinklist InitList(DLinklist &DL);
bool DeleteNextNode(Lnode*p, int &DeleteNumber);
bool DeInitLinklist(Linklist &L);
void Initbitree(ThreadTree &T);
void InThread(ThreadTree T);
void visit(Threadnode *p);
void CreateLeftTree(Threadnode *p);
void CreatRightTree(Threadnode *p);
Threadnode* Firstnode(ThreadTree T);
void traversalBitree(ThreadTree T);

extern unsigned int x;
extern Threadnode *pre;