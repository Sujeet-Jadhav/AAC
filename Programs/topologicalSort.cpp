#include <stdio.h>
#include <stdlib.h>

// #define 10 100

// Function to initialize the graph with zero edges
void initializeGraph(int graph[10][10], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

// Function to add a directed edge to the graph
void addEdge(int graph[10][10], int from, int to) {
    graph[from][to] = 1;
}

// Function to perform topological sorting using depth-first search
void topologicalSortUtil(int graph[10][10], int vertex, int visited[10], int stack[10], int* stackIndex) {
    visited[vertex] = 1; // Mark the current vertex as visited

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < 10; i++) {
        if (graph[vertex][i] && !visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, stackIndex);
        }
    }

    // Push the current vertex to the stack
    stack[(*stackIndex)++] = vertex;
}

// Function to perform topological sorting of a graph
void topologicalSort(int graph[10][10], int vertices) {
    int visited[10];
    int stack[10];
    int stackIndex = 0;

    // Mark all the vertices as not visited
    for (int i = 0; i < 10; i++) {
        visited[i] = 0;
    }

    // Call the recursive helper function to store topological sort starting from all vertices one by one
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }

    // Print the vertices in topological order from the stack
    printf("Topological Sort: ");
    while (stackIndex > 0) {
        printf("%d ", stack[--stackIndex]);
    }
    printf("\n");
}

// Driver code
int main() {
    int graph[10][10];
    int vertices, edges;

    // Get the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize the graph
    initializeGraph(graph, vertices);

    // Get the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Add edges to the graph
    for (int i = 0; i < edges; i++) {
        int from, to;
        printf("Enter edge (from to): ");
        scanf("%d %d", &from, &to);
        addEdge(graph, from, to);
    }

    // Perform topological sorting
    topologicalSort(graph, vertices);

    return 0;
}

