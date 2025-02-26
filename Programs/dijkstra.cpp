#include <stdio.h>
#include <limits.h>

#define V 8 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm for a given graph represented as an adjacency matrix
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // The output array dist[i] holds the shortest distance from src to i
    int sptSet[V];   // sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in the sptSet, there is an edge from u to v,
            // and the total weight of path from src to v through u is less than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

// Driver code
int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8},
                       {4, 0, 8, 0, 0, 0, 0, 11},
                       {0, 8, 0, 7, 0, 4, 0, 0},
                       {0, 0, 7, 0, 9, 14, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1},
                       {8, 11, 0, 0, 0, 0, 1, 0}};

    // Print the shortest paths using Dijkstra's algorithm
    dijkstra(graph, 0);

    return 0;
}

