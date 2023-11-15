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

}

int StackEmpty(Stack *p) {

}

int StackFull(Stack *p) {

}

void Push(Stack *p, ElemType x) {

}

void Pop(Stack *p, ElemType *q) {

}

int StackTop(Stack *p, ElemType *q) {

}

void StackClear(Stack *p) {

}

// 待判断的字符串保存在数组a中，数组的有效长度保存在n中
// 通过计算返回0，表示括号不匹配，返回1表示匹配
int Match(char a[], int n) {

}
                                

int main() {
  //char str[100] = "()[]{}";
  //char str[100] = "{[()][(()())]}";
  //char str[100] = "([)]{}";
  char str[100] = "{[)(]{}}";


  
  return 0;
}        
