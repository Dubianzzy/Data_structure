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
    if (j + 1 < n && a[j + 1] < a[j]) j++;
    if (a[j] > tmp) break;
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
  for (i = n / 2 - 1; i >= 0; i--)
    FixDown(a, n, i);
}

void heapsort(int a[], int n) {
  Heapify(a, n);
  int end = n - 1;
  while (end > 0) {
    exch(&a[0], &a[end]);
    FixDown(a, end, 0);
    end--;
  }
}

int main() {
  int N, *a, i;
  scanf("%d", &N);
  a = malloc(sizeof(int) * N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);
  heapsort(a, N);
  puts("sorting results:");
  PrintArr(a, N);
  return 0;
}