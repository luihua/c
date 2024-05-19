
#define MAXSIZE 10
typedef struct Stack
{
    int top;//栈顶指针
    int data[MAXSIZE];//静态数组存数据
}Sqstack;//栈的顺序实现 

typedef struct
{
    int data[MAXSIZE];//静态数组存数据
    int front; //队头指针，指向即将出队的元素
    int rear;  //队尾指针,指向即将入队的空白
}Queue;//队列的顺序实现


void InitStack(Sqstack &S);
bool Push(Sqstack &S, int PushNumber);
bool pop(Sqstack &S, int &PopNumber);
bool getall(Sqstack S, int *GetNumber);