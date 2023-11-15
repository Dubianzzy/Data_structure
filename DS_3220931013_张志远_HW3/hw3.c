/*************************************************************
 * Created by David Song in 2016-4-26                        *
 * Updated by David Song in 2019-9-12                        *
 * 提问：你能从函数的首行定义中看出，调用初始化函数的调用方，            *
 *       应该准备什么样的变量吗？                                 *
 *                                                           *
 * Note:                                                     *
 *   1. Sequencial implementation of stack                   *
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef char ElemType;
typedef struct stack {
  ElemType a[MAX];
  int top;
} Stack;

void InitStack(Stack *p) {
    p->top=-1;
}

int StackEmpty(Stack *p) {
    return p->top == -1;
}

int StackFull(Stack *p) {
    return p->top == MAX-1;
}

void Push(Stack *p, ElemType x) {
    p->top++;
    p->a[p->top]=x;
}

void Pop(Stack *p, ElemType *q) {
    *q=p->a[p->top];
    p->top--;
}

int StackTop(Stack *p, ElemType *q) {
    *q=p->a[p->top];
    return 1;
}

void StackClear(Stack *p) {
    ElemType q;
    while(p->top!=-1)
    {
        Pop(p,&q);
    }
}

// 待判断的字符串保存在数组a中，数组的有效长度保存在n中
// 通过计算返回0，表示括号不匹配，返回1表示匹配
int Match(char a[], int n) {
    int i;
    Stack p;
    ElemType tmp,r;
    for (i = 0; a[i]; i++) {
    if (a[i] == '(' || a[i] == '[' || a[i] == '{') {
        Push(&p, a[i]);
    } else if (a[i] == ')' || a[i] == ']' || a[i] == '}') {
        StackTop(&p, &tmp);
        if ((tmp == '(' && a[i] == ')') ||
            (tmp == '[' && a[i] == ']') ||
            (tmp == '{' && a[i] == '}')) {
            Pop(&p, &r);
        } else {
            return 0; // 括号不匹配，直接返回
        }
    } else {
        printf("输入错误\n");
        return 0; // 输入错误，直接返回
    }
}
return 1;
}
                               

int main() {
  //char str[100] = "()[]{}";
  //char str[100] = "{[()][(()())]}";
  //char str[100] = "([)]{}";
  char str[100] = "{[)(]{}}";
  printf("%d\n",Match(str,strlen(str)));
  return 0;
}        
