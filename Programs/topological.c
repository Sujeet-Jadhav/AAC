
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = (struct Node*)malloc(vertices * sizeof(struct Node));

    for (int i = 0; i < vertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void topologicalSortUtil(int v, struct Graph* graph, int visited[], struct Node** stack) {
    visited[v] = 1;

    struct Node* adjNode = graph->adjList[v];
    while (adjNode != NULL) {
        if (!visited[adjNode->data])
            topologicalSortUtil(adjNode->data, graph, visited, stack);
        adjNode = adjNode->next;
    }

    struct Node* temp = createNode(v);
    temp->next = *stack;
    *stack = temp;
}

void topologicalSort(struct Graph* graph) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    struct Node* stack = NULL;

    for (int i = 0; i < graph->vertices; ++i)
        visited[i] = 0;

    for (int i = 0; i < graph->vertices; ++i) {
        if (!visited[i])
            topologicalSortUtil(i, graph, visited, &stack);
    }

    printf("Topological Ordering: ");
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}