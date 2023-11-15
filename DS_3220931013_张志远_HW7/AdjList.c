/******************************************************
 * Created by David Song in 2016-5-24
 *
 * Note:
 *   1. A un-directed graph with no weights on edge
 *   2. A adjacent chain version
 *   3. implement DFS
 *   4. implement BFS
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Que.h"


#define MAX_GRAPH 20

int visited[MAX_GRAPH] = {0};

typedef struct edge {
  int head;
  struct edge *next;
} Edge;

typedef struct {
  int V;
  int E;
  Edge *adjList[MAX_GRAPH];
} Graph;

void InitGraph(Graph *p) {
  int i;
  p->V = 0;
  p->E = 0;
  for (i = 0; i < MAX_GRAPH; i++)
      p->adjList[i] = NULL;
}

void CreateGraph(Graph *p) {
  int n, m, i;
  int v, u;
  Edge *s;
  printf("please input the number of verteies: \n");
  scanf("%d", &n);
  printf("please input the number of edges: \n");
  scanf("%d", &m);
  p->V = n;
  p->E = m;
  for (i = 0; i < p->E; i++) {
    printf("input edge: ");
    scanf("%d%d", &v, &u);
    // insert v-u edge
    s = malloc(sizeof(Edge));
    s->head = u;
    s->next = p->adjList[v];
    p->adjList[v] = s;
    // insert u-v edge
//    s = malloc(sizeof(Edge));
//    s->head = v;
//    s->next = p->adjList[u];
//    p->adjList[u] = s;
  }
}

int _FindEdge(Graph *p, int v, int u) {
    Edge *tmp;
    int found = 0;
    tmp = p->adjList[v];
    while (tmp != NULL) {
        if (tmp->head == u) {
            found = 1;
            break;
        }
        tmp = tmp->next;
    }
    return found;
}

void PrintGraph(Graph *p) {
  int i, j;
  printf("a graph with %d verteies and %d edges\n", p->V, p->E);
  for (i = 0; i < p->V; i++)
    for (j = i; j < p->V; j++) {
      if (_FindEdge(p, i, j))
        printf("%d -- %d\n", i, j);
    }
}



void DFS(Graph *p, int v) {
  int i;
  Edge *tmp;
  visited[v] = 1;
  printf("%d ", v);
  tmp = p->adjList[v];
  while (tmp != NULL) {
    if (visited[tmp->head] != 1)
      DFS(p, tmp->head);
    tmp = tmp->next;
  }    
}


int main() {
  Graph G;
  InitGraph(&G);
  CreateGraph(&G);
  PrintGraph(&G);
  DFS(&G, 0);
  return 0;
}
  
