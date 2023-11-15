/*******************************************************
 * Created by David Song in 2016-5-23
 *
 * Note:
 *   1. Sequencial implementation of circular queue
 *   2. Save one slot to dicide whether queue is empty 
 ******************************************************/
#include "Que.h"

void InitQue(Que **p) {
  *p = malloc(sizeof(Que));
  (*p)->front = 0;
  (*p)->rear  = 0;
}

int QueEmpty(Que *p) {
  return p->front == p->rear;
}

int QueFull(Que *p) {
  return (p->rear + 1) % MAX == p->front;
}

void EnQue(Que *p, ElemType x) {
  // printf("p->front: %d, p->rear: %d\n", p->front, p->rear);
  if (QueFull(p))
    puts("error: enqueue to a full queue!");
  else {
    p->a[p->rear] = x;
    p->rear = (p->rear + 1) % MAX;
    
  }
}

void DeQue(Que *p, ElemType *q) {
  if (QueEmpty(p))
    puts("error: depart from an empty queue!");
  else {
    p->front = (p->front + 1) % MAX;
    *q = p->a[p->front];
  }
}

void PrintQue(Que *p) {
  if (QueEmpty(p)) return;
  puts("the queue has: ");
  int i = (p->front + 1) % MAX;
  while (i != p->rear) {
    printf("%5d", p->a[i]);
    i = (i + 1) % MAX;
  }
  printf("%5d\n", p->a[i]);
}

void QueClear(Que *p) {
  p->front = p->rear = 0;
}

void QueDestory(Que **p) {
  free(*p);
  *p = NULL;
}

