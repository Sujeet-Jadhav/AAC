
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define V 6 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value,
// from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // The output array dist[i] holds the shortest distance from src to i
    int sptSet[V];   // sptSet[i] will be true if vertex i is included in the shortest
                     // path tree or the shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    int graph[V][V] = {{0, 2, 0, 0, 0, 0},
                       {2, 0, 4, 1, 0, 0},
                       {0, 4, 0, 7, 3, 0},
                       {0, 1, 7, 0, 0, 2},
                       {0, 0, 3, 0, 0, 6},
                       {0, 0, 0, 2, 6, 0}};

    int source = 0;

    dijkstra(graph, source);

    return 0;
}