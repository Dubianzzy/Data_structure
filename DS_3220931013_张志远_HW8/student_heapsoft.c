#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  char name[50];
  int score;
} STU;

void swap(STU *a, STU *b) {
  STU t = *a;
  *a = *b;
  *b = t;
}

void Heapify(STU a[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && a[left].id > a[largest].id)
    largest = left;

  if (right < n && a[right].id > a[largest].id)
    largest = right;

  if (largest != i) {
    swap(&a[i], &a[largest]);
    Heapify(a, n, largest);
  }
}

void HeapSort(STU a[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    Heapify(a, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(&a[0], &a[i]);
    Heapify(a, i, 0);
  }
}

int main() {
  int N, i;
  STU *a;
  printf("Enter the number of students: ");
  scanf("%d", &N);
  a = malloc(sizeof(STU) * N);
  printf("Enter the id, name and score of each student:\n");
  for (i = 0; i < N; i++)
    scanf("%d %s %d", &a[i].id, a[i].name, &a[i].score);
  HeapSort(a, N);
  printf("The sorted student information is:\n");
  for (i = 0; i < N; i++)
    printf("%d %s %d\n", a[i].id, a[i].name, a[i].score);
  free(a);
  return 0;
}