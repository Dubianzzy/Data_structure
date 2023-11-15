#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
typedef char ElemType;
typedef struct Queue
{
    ElemType a[Max];
    int front;
    int rear;
} Queue;
void InitQueue(Queue **p)
{
    (*p) = (Queue *)malloc(sizeof(Queue));
    (*p)->front = (*p)->rear = 0;
}
int EmptyQueue(Queue *p)
{
    return p->front == p->rear;
}
int FullQueue(Queue *p)
{
    return (p->rear + 1) % Max == p->front;
}
void EnQueue(Queue *p, ElemType a)
{
    if (FullQueue(p))
        printf("Error:The queue is full\n");
    p->a[p->rear] = a;
    p->rear = (p->rear + 1) % Max;
}
void DeQueue(Queue *p, ElemType *a)
{
    if (EmptyQueue(p))
        printf("Error:The queue is empty\n");
    *a = p->a[p->front];
    p->front = (p->front + 1) % Max;
}
void QueClear(Queue *p)
{
    p->front = p->rear = 0;
}
void QueDestory(Queue **p)
{
    free(*p);
    *p = NULL;
}
int main()
{
    Queue *p;
    InitQueue(&p);
    char a[Max] = "root:root", b[Max];
    int sign = 0, len;
    printf("Please enter a string of characters：\n");
    scanf("%s", a);
    len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] == ':')
        {
            sign = 1;
            i++;
            for (int j = 0; i < len; i++, j++)
            {
                b[j] = a[i];
            }
            break;
        }
        EnQueue(p, a[i]);
    }
    if (sign != 1)
        printf("N\n");
    else
    {
        switch (strcmp(p->a, b))
        {
        case 0:
            printf("S\n");
            break;
        default:
        {
            if (strlen(p->a) == strlen(b))
                printf("D\n");
            if (strlen(p->a) > strlen(b))
                printf("L\n");
            if (strlen(p->a) < strlen(b))
                printf("R\n");
        }
        }
    }
    return 0;
}
