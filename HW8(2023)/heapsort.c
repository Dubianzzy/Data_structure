/************************************************
 Created by David Song in 2016-6-8

 Note:
   1. A program to sort array increasely
   2. with the help of a max heap
*************************************************/

#include <stdio.h>
#include <stdlib.h>

void exch(int *p, int *q) {
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

void PrintArr(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%5d", a[i]);
  putchar('\n');
}

void FixDown(int a[], int n, int k) {
  int i, j, tmp;
  i = k;
  tmp = a[i];
  j = 2 * i + 1;
  while (j < n) {
    if (j + 1 < n && a[j + 1] > a[j]) j++;
    if (a[j] < tmp) break;
    else {
      a[i] = a[j];
      i = j;
      j = 2 * i + 1;
    }
  }
  a[i] = tmp;
  PrintArr(a, n);
}

void Heapify(int a[], int n) {
  int i;
  for (i = (n - 2) / 2; i >= 0; i--)
    FixDown(a, n, i);
}

void HeapSort(int a[], int n) {
  int i;
  Heapify(a, n);
  puts("after heapify, start sorting...");
  for (i = 0; i < n - 1; i++) {
    exch(&a[0], &a[n - i - 1]);
    FixDown(a, n - i - 1, 0);
  }
}

int main() {
  int N, *a, i;
  scanf("%d", &N);
  a = malloc(sizeof(int) * N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);
  HeapSort(a, N);
  puts("sorting results:");
  PrintArr(a, N);
  return 0;
}


