/******************************************************
 * Created by David Song in 2016-5-23
 *
 * Note:
 *   1. A un-directed graph with no weights on edge
 *   2. implement DFS
 *   3. implement BFS
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Que.h"

#define MAX_GRAPH 20

int visited[MAX_GRAPH] = {0};

typedef struct {
  int V;  // number of verteies
  int E;  // number of edges
  int adjMatrix[MAX_GRAPH][MAX_GRAPH];  // use a 2-D array to store edges
} Graph;

void InitGraph(Graph *p) {
  int i, j;
  p->V = 0;
  p->E = 0;
  for (i = 0; i < MAX_GRAPH; i++)
    for (j = 0; j < MAX_GRAPH; j++)
      p->adjMatrix[i][j] = 0;
}

void CreateGraph(Graph *p) {
  int n, m, i;
  int v, u;
  // printf("please input the number of verteies: \n");
  scanf("%d", &n);
  // printf("please input the number of edges: \n");
  scanf("%d", &m);
  p->V = n;
  p->E = m;
  for (i = 0; i < p->E; i++) {
    // printf("input edge: ");
    scanf("%d%d", &v, &u);
    p->adjMatrix[v][u] = 1;
    p->adjMatrix[u][v] = 1;
  }
}

void PrintGraph(Graph *p) {
  int i, j;
  printf("a graph with %d verteies and %d edges\n", p->V, p->E);
  for (i = 0; i < p->V; i++)
    for (j = i; j < p->V; j++) {
      if (p->adjMatrix[i][j] == 1)
        printf("%d -- %d\n", i, j);
    }
}













void DFS(Graph *p, int v) {
  int i;
  visited[v] = 1;
  printf("%d ", v);
  for (i = 0; i < p->V; i++)
    if (p->adjMatrix[v][i] != 0 && visited[i] == 0) {
      printf(" (%d-%d) ", v, i);
      DFS(p, i);
    }
}

void BFS(Graph *p, int v) {
  Que *q;
  int tmp, i;
  InitQue(&q);
  EnQue(q, v);
  visited[v] = 1;
  while (!QueEmpty(q)) {
    DeQue(q, &tmp);
    printf("%d ", tmp);
    for (i = 0; i < p->V; i++) {
      if (visited[i] == 0 && p->adjMatrix[tmp][i] != 0) {
        EnQue(q, i);
        visited[i] = 1;
        // PrintQue(q);
      }
    }
  }
}

int main() {
  Graph G;
  InitGraph(&G);
  CreateGraph(&G);
  PrintGraph(&G);
  puts("DFS traverse:");
  DFS(&G, 0);
  // puts("BFS traverse:");
  // BFS(&G, 0);
  return 0;
}
