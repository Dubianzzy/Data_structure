
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
// 在这里补充一个结构体，包括系数和指数两项
typedef struct polynomial{
  double coef;  //系数
  int expn;  //指数
}poly;



// 把下面的double替换为自己定义的结构体类型（即顺序表中元素的类型是自己定义的）
typedef poly ElemType;

typedef struct list {
  ElemType a[MAXSIZE + 1];
  int len;
} SeqList;

SeqList * InitList();
void InitList2(SeqList **ppList);
int ListFull(SeqList *pList);
int ListEmpty(SeqList *pList);
int ListLen(SeqList *pList);
void Error(char *msg);
int GetElem(SeqList *pList, int i, ElemType *pElm);
int InsertElem(SeqList * pList, int i, ElemType elm);
int DelElem(SeqList *pList, int i, ElemType *pElm);
void PrintList(SeqList *pList);
void AddPolynomials(SeqList *polyA, SeqList *polyB, SeqList *polyC);


int main() {
  int i, j, k;
  SeqList *A, *B, *C;
  // 下面的a 和 b表示了两个多项式，数组中的数据是多项式系数，
  // 它们在数组中的位置表示多少次方，例如a表示的是：
  // 0*X^0 + 0*X^1 + 7*X^2 + 0*X^3 + 3*X^4 + 1*X^5 + 9*X^6 + ...
  // b表示的是：
  // 0*X^0 + 0*X^1 + 8*X^2 + 1*X^3 + 22*X^4 + 7*X^5 ...
  // ElemType a[M] = {0, 0, 7,0,3,1,9,8,5,17,-8,100}, b[N] = {0, 0, 8,1,22,7,-9, 8}, x;
  // a和b数组是原始的输入数据
  InitList2(&A);
  InitList2(&B);
  InitList2(&C);
  poly x,y;
  printf("Enter the number of terms of the a polynomial: \n");
  scanf("%d",&k);
  for (int tmp1=0,i = 1; i <= k-tmp1; ) {
    scanf("%lf%d", &x.coef, &x.expn);
    if(x.coef!=0)
    {
      InsertElem(A,i,x);
      i++;
    }else if(x.coef==0)
    {
      tmp1++;
    }
    
  }
  printf("Enter the number of terms of the b polynomial: \n");
  scanf("%d",&k);
  for (int tmp2=0,j = 1; j <= k-tmp2; ) {
    scanf("%lf%d", &y.coef, &y.expn);
    if(y.coef!=0)
    {
      InsertElem(B,j,y);
      j++;
    }else if(y.coef==0)
    {
      tmp2++;
    }
    
  }
  AddPolynomials(A, B, C);
  printf("A + B = \n");
  PrintList(C);

  // 释放内存
  free(A);
  free(B);
  free(C);
  
  return 0;
}


/* 输入：无
   返回：指向顺序表的指针，通过返回值，把申请到的、指向内存空间的指针带回调用方。
   功能：为顺序表申请内存空间，并把顺序表的大小置为0。
*/
SeqList * InitList() {
  SeqList *pList;
  pList = (SeqList *)malloc(sizeof(SeqList));
  pList->len = 0;
  return pList;
}

/* 输入：指向顺序表结构体的二级指针，调用方需要准备一个顺序表指针变量，然后把该
         变量的地址传递进来（即一个二级地址）
   返回：无
   功能：为顺序表申请内存空间，并把顺序表的大小置为0。
*/
void InitList2(SeqList **ppList) {
  *ppList = (SeqList *)malloc(sizeof(SeqList));
  (*ppList)->len = 0;
}

/* 输入：指向顺序表的指针
   返回：返回整型变量1，表示顺序表已满，否则未满。
   功能：判断顺序表是否已满。
*/
int ListFull(SeqList *pList) {
  /*
  if (pList->len == MAXSIZE)
    return 1;
  else
    return 0;
  */
  return (pList->len == MAXSIZE) ? 1 : 0;
}

/* 输入：指向顺序表的指针
   返回：返回整型变量1，表示顺序表是空表，否则非空。
   功能：判断顺序表是否已空。
*/
int ListEmpty(SeqList *pList) {
  return (pList->len == 0) ? 1 : 0;
}

/* 输入：指向顺序表的指针
   返回：返回整型变量，表示顺序表有效元素个数
   功能：提供顺序表有效元素个数
*/
int ListLen(SeqList *pList) {
  return pList->len;
}

/* 输入：字符指针
   返回：无
   功能：输出自定义的出错消息定义
*/
void Error(char *msg) {
  printf("[错误]：%s\n", msg);
}
int GetElem(SeqList *pList, int i, ElemType *pElm) {
  if (ListEmpty(pList)) {
    Error("从空表中读取数据元素");
    return 0;
  }
  if (i < 1 || i > MAXSIZE) {
    Error("读取位置错误！");
    return 0;
  }
  *pElm = pList->a[i];
  return 1;
}

int InsertElem(SeqList *pList, int i, ElemType elm) {
  int k;
  if (ListFull(pList)) {
    Error("无法向已经满了的顺序表插入数据元素!");
    return 0;
  }
  if (i < 1 || i > pList->len + 1) {
    Error("插入位置越界!");
    return 0;
  }
  pList->a[i] = elm;
  pList->len += 1;
  return 1;
}


int DelElem(SeqList *pList, int i, ElemType *pElm) {
  // 补充完整
  int k;
  if (ListEmpty(pList)) {
    Error("delete element from an empty list");
    return 0;
  }
  if (i < 1 || i > pList->len) {
    Error("delete element out of range");
    return 0;
  }
  *pElm = pList->a[i];
  for (k = i; k < pList->len; k++)
    pList->a[k] = pList->a[k + 1];
  pList->len -= 1;
  return 1;
}

void PrintList(SeqList *pList) {
  int i;
  for (i = 1; i <= pList->len; i++)
    printf("%.2lf %d\n", pList->a[i].coef,pList->a[i].expn);
  putchar('\n');
}
void AddPolynomials(SeqList *pListA, SeqList *pListB, SeqList *pListC) 
{
  int i=1,j=1,k=1;
  poly tmpA,tmpB;
  while(i<=pListA->len&&j<=pListB->len)
  {
    tmpA=pListA->a[i];
    tmpB=pListB->a[j];
    if(tmpA.expn<tmpB.expn)
    {
      InsertElem(pListC,k,tmpA);
      i++;
    }else if(tmpA.expn>tmpB.expn)
    {
      InsertElem(pListC,k,tmpB);
      j++;
    }else if(tmpA.expn==tmpB.expn)
    {
      poly newtmp;
      newtmp.coef=tmpA.coef+tmpB.coef;
      newtmp.expn=tmpA.expn;
      InsertElem(pListC,k,newtmp);
      i++;j++;
    }
    k++;
  }
  while(i<=pListA->len)
  {
    tmpA=pListA->a[i];
    InsertElem(pListC,k,tmpA);
    i++;k++;
  }
  while(j<=pListB->len)
  {
    tmpB=pListB->a[j];
    InsertElem(pListC,k,tmpB);
    j++;k++;
  }
}