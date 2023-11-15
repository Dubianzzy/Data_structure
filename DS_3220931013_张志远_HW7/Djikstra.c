#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 邻接链表的节点
typedef struct Node
{
    int dest; // 目标顶点
    int weight;
    struct Node *next; // 指向下一个节点的指针
} Node;

// 邻接链表
typedef struct List
{
    Node *head; // 链表头节点指针
} List;

// 图的结构体
typedef struct Graph
{
    int V;              // 顶点的个数
    List *adjListArray; // 邻接链表的数组
} Graph;

// 定义一个结构体，用于存储最短路径的信息
typedef struct Path
{
    int dist; // 最短距离
    int prev; // 前驱节点
} Path;

// 创建节点
Node *createNode(int dest, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// 创建图
Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;

    graph->adjListArray = (List *)malloc(V * sizeof(List));

    int i;
    for (i = 0; i < V; i++)
    {
        graph->adjListArray[i].head = NULL;
    }

    return graph;
}

// 添加边
void addEdge(Graph *graph, int src, int dest, int weight)
{
    // 添加从 src 到 dest 的边
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjListArray[src].head;
    graph->adjListArray[src].head = newNode;
}

// 打印图的邻接链表
void printGraph(Graph *graph)
{
    int i;
    for (i = 0; i < graph->V; i++)
    {
        Node *temp = graph->adjListArray[i].head;
        printf("顶点 %d 的邻接链表：", i);
        while (temp)
        {
            printf("\n -> %d  %d", temp->dest, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void addVertex(Graph **graph, int newV)
{
    // 创建一个新的图结构体，顶点个数为新的顶点编号加一
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->V = newV + 1;

    // 为新的图分配邻接链表数组的空间
    newGraph->adjListArray = (List *)malloc(newGraph->V * sizeof(List));

    // 初始化新的图的邻接链表数组
    int i;
    for (i = 0; i < newGraph->V; i++)
    {
        newGraph->adjListArray[i].head = NULL;
    }

    // 复制原来的图的邻接链表到新的图中
    for (i = 0; i < (*graph)->V; i++)
    {
        Node *temp = (*graph)->adjListArray[i].head;
        while (temp)
        {
            addEdge(newGraph, i, temp->dest, temp->weight);
            temp = temp->next;
        }
    }

    // 释放原来的图的空间
    free((*graph)->adjListArray);
    free(*graph);

    // 将新的图的指针赋值给原来的图的指针
    *graph = newGraph;
}

// 定义一个函数，用于打印最短路径
void printPath(int v, Path *path)
{
    if (path[v].prev != -1)
    {
        printPath(path[v].prev, path);                 // 递归打印前驱节点
        printf(" -> "); // 打印箭头
        printf("%d", v); // 打印当前节点
    }
}

// 定义一个函数，用于求解单元最短路径
void dijkstra(Graph *graph, int src, int dest)
{
    int V = graph->V;                                 // 获取顶点的个数
    Path *path = (Path *)malloc(V * sizeof(Path));    // 分配路径信息数组的空间
    bool *visited = (bool *)malloc(V * sizeof(bool)); // 分配访问标记数组的空间

    // 初始化路径信息数组和访问标记数组
    for (int i = 0; i < V; i++)
    {
        path[i].dist = INT_MAX; // 初始距离为无穷大
        path[i].prev = -1;      // 初始前驱节点为-1
        visited[i] = false;     // 初始访问标记为false
    }

    // 设置源节点的距离为0
    path[src].dist = 0;

    // 循环V-1次，每次找到一个未访问的最近节点
    for (int i = 0; i < V - 1; i++)
    {
        // 找到未访问的最近节点
        int min = INT_MAX;
        int u = -1;
        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && path[j].dist < min)
            {
                min = path[j].dist;
                u = j;
            }
        }

        // 如果没有找到，说明没有可达的节点，退出循环
        if (u == -1)
        {
            break;
        }

        // 标记该节点为已访问
        visited[u] = true;

        // 更新该节点的邻接节点的距离和前驱节点
        Node *temp = graph->adjListArray[u].head;
        while (temp)
        {
            int v = temp->dest;
            int w = temp->weight;
            if (!visited[v] && path[u].dist + w < path[v].dist)
            {
                path[v].dist = path[u].dist + w;
                path[v].prev = u;
            }
            temp = temp->next;
        }
    }

    // 如果目标节点的距离不是无穷大，说明存在最短路径，打印结果
    if (path[dest].dist != INT_MAX)
    {
        printf("从节点%d到节点%d的最短距离是%d\n", src, dest, path[dest].dist);
        printf("具体的路径是：");
        printPath(dest, path);
        printf("\n");
    }
    else
    {
        printf("从节点%d到节点%d没有可达的路径\n", src, dest);
    }

    // 释放路径信息数组和访问标记数组的空间
    free(path);
    free(visited);
}

int main()
{
    int V = 100; // 顶点的个数
    int src, dest, weight;
    Graph *graph = createGraph(V);
    FILE *file = fopen("D:\\C_project_clion\\HW7\\data_dij.txt", "r");
    if (!file)
    {
        printf("Unable to open file\n");
        return 0;
    }
    while (fscanf(file, "%d %d %d", &src, &dest, &weight) == 3)
    {
        if (src >= graph->V || dest >= graph->V)
            addVertex(&graph, src >= dest ? src : dest);
        addEdge(graph, src, dest, weight);
    }

    //printGraph(graph);
    printf("请输入要查询最短路径的两节点：\n");
    while(scanf("%d %d", &src, &dest)!=EOF)
    dijkstra(graph, src, dest);

    return 0;
}
