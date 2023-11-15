#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// �ڽ�����Ľڵ�
typedef struct Node
{
    int dest; // Ŀ�궥��
    int weight;
    struct Node *next; // ָ����һ���ڵ��ָ��
} Node;

// �ڽ�����
typedef struct List
{
    Node *head; // ����ͷ�ڵ�ָ��
} List;

// ͼ�Ľṹ��
typedef struct Graph
{
    int V;              // ����ĸ���
    List *adjListArray; // �ڽ����������
} Graph;

// ����һ���ṹ�壬���ڴ洢���·������Ϣ
typedef struct Path
{
    int dist; // ��̾���
    int prev; // ǰ���ڵ�
} Path;

// �����ڵ�
Node *createNode(int dest, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// ����ͼ
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

// ��ӱ�
void addEdge(Graph *graph, int src, int dest, int weight)
{
    // ��Ӵ� src �� dest �ı�
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjListArray[src].head;
    graph->adjListArray[src].head = newNode;
}

// ��ӡͼ���ڽ�����
void printGraph(Graph *graph)
{
    int i;
    for (i = 0; i < graph->V; i++)
    {
        Node *temp = graph->adjListArray[i].head;
        printf("���� %d ���ڽ�����", i);
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
    // ����һ���µ�ͼ�ṹ�壬�������Ϊ�µĶ����ż�һ
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->V = newV + 1;

    // Ϊ�µ�ͼ�����ڽ���������Ŀռ�
    newGraph->adjListArray = (List *)malloc(newGraph->V * sizeof(List));

    // ��ʼ���µ�ͼ���ڽ���������
    int i;
    for (i = 0; i < newGraph->V; i++)
    {
        newGraph->adjListArray[i].head = NULL;
    }

    // ����ԭ����ͼ���ڽ������µ�ͼ��
    for (i = 0; i < (*graph)->V; i++)
    {
        Node *temp = (*graph)->adjListArray[i].head;
        while (temp)
        {
            addEdge(newGraph, i, temp->dest, temp->weight);
            temp = temp->next;
        }
    }

    // �ͷ�ԭ����ͼ�Ŀռ�
    free((*graph)->adjListArray);
    free(*graph);

    // ���µ�ͼ��ָ�븳ֵ��ԭ����ͼ��ָ��
    *graph = newGraph;
}

// ����һ�����������ڴ�ӡ���·��
void printPath(int v, Path *path)
{
    if (path[v].prev != -1)
    {
        printPath(path[v].prev, path);                 // �ݹ��ӡǰ���ڵ�
        printf(" -> "); // ��ӡ��ͷ
        printf("%d", v); // ��ӡ��ǰ�ڵ�
    }
}

// ����һ��������������ⵥԪ���·��
void dijkstra(Graph *graph, int src, int dest)
{
    int V = graph->V;                                 // ��ȡ����ĸ���
    Path *path = (Path *)malloc(V * sizeof(Path));    // ����·����Ϣ����Ŀռ�
    bool *visited = (bool *)malloc(V * sizeof(bool)); // ������ʱ������Ŀռ�

    // ��ʼ��·����Ϣ����ͷ��ʱ������
    for (int i = 0; i < V; i++)
    {
        path[i].dist = INT_MAX; // ��ʼ����Ϊ�����
        path[i].prev = -1;      // ��ʼǰ���ڵ�Ϊ-1
        visited[i] = false;     // ��ʼ���ʱ��Ϊfalse
    }

    // ����Դ�ڵ�ľ���Ϊ0
    path[src].dist = 0;

    // ѭ��V-1�Σ�ÿ���ҵ�һ��δ���ʵ�����ڵ�
    for (int i = 0; i < V - 1; i++)
    {
        // �ҵ�δ���ʵ�����ڵ�
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

        // ���û���ҵ���˵��û�пɴ�Ľڵ㣬�˳�ѭ��
        if (u == -1)
        {
            break;
        }

        // ��Ǹýڵ�Ϊ�ѷ���
        visited[u] = true;

        // ���¸ýڵ���ڽӽڵ�ľ����ǰ���ڵ�
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

    // ���Ŀ��ڵ�ľ��벻�������˵���������·������ӡ���
    if (path[dest].dist != INT_MAX)
    {
        printf("�ӽڵ�%d���ڵ�%d����̾�����%d\n", src, dest, path[dest].dist);
        printf("�����·���ǣ�");
        printPath(dest, path);
        printf("\n");
    }
    else
    {
        printf("�ӽڵ�%d���ڵ�%dû�пɴ��·��\n", src, dest);
    }

    // �ͷ�·����Ϣ����ͷ��ʱ������Ŀռ�
    free(path);
    free(visited);
}

int main()
{
    int V = 100; // ����ĸ���
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
    printf("������Ҫ��ѯ���·�������ڵ㣺\n");
    while(scanf("%d %d", &src, &dest)!=EOF)
    dijkstra(graph, src, dest);

    return 0;
}
