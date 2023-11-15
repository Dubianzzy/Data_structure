/************************************************
 Created by David Song in 2021-4-28

 Note:
   1. Link list implementation of stack
   2. Use link stack to help calculate postfix
      expressions
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 任务1，在这里补充链式栈的类型定义和操作函数

// 任务2，补充Calc函数体
int Calc(char *s) {
// 注意计算时，最好用一个整数型的栈，字符数字入栈前，先转换为整数（即减去'0'）再入栈
}

int main() {
  // (5+3)*2+(6+3) = 25
  char str[100] = "53+2*63++";
  int rst;
  rst = Calc(str);
  printf("the results is: %d\n", rst);
  return 0;
}
