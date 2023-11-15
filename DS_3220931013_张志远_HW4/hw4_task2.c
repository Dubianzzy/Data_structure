#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node{
    ElemType elem;
    struct node *next;
}Node;
typedef struct queue{
    Node *front;
    Node *rear;
}Queue;
void InitQueue(Queue **p)
{
    *p =(Queue*)malloc(sizeof(Queue));
    (*p)->front=NULL;
    (*p)->rear=NULL;
}
int QueueEmpty(Queue **p)
{
    return (*p)->front==NULL;
}
void EnQueue(Queue **p, ElemType a)
{
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->elem=a;
    tmp->next=NULL;
    if((*p)->front==NULL)
    {
        (*p)->front=tmp;
        (*p)->rear=tmp;
    }else
    {
        (*p)->rear->next=tmp;
        (*p)->rear=tmp;
    }
}
int DeQueue(Queue **p, ElemType *a)
{
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp=(*p)->front;
    *a=tmp->elem;
    (*p)->front=tmp->next;
    free(tmp);
}
int GetQueueHead(Queue **p)
{
    if((*p)->front==NULL)
    printf("队列为空。");
    return (*p)->front->elem;
}
int main()
{
    Queue *p;
    ElemType a=1,b,c,d=2;
    InitQueue(&p);
    EnQueue(&p, a);
    EnQueue(&p, d);
    printf("----向队列中加入1，2元素并删除第一个元素，并展示队列头元素和已删除的元素----\n");
    printf("p->front->elem=%d\n",p->front->elem);
    printf("p->front->next->elem=%d\n",p->front->next->elem);
    b=GetQueueHead(&p);
    printf("head_elem=%d\n",b);
    DeQueue(&p, &c);
    printf("de_elem=%d",c);
    free(p);
    return 0;
}