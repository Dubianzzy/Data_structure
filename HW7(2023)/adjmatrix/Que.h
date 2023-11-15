#ifndef Seq_H
#define Seq_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef int ElemType;
typedef struct seqQue {
  ElemType a[MAX];
  int front;
  int rear;
} Que;

void InitQue(Que **p);
int QueEmpty(Que *p);
int QueFull(Que *p);
void EnQue(Que *p, ElemType x);
void DeQue(Que *p, ElemType *q);
void PrintQue(Que *p);
void QueClear(Que *p);
void QueDestory(Que **p);

#endif
