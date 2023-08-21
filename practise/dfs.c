#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100

// Adjacency matrix representation of the graph
int adjMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES]; // To keep track of visited nodes

// DFS traversal using adjacency matrix
void dfs(int currentNode)
{
    printf("%d ", currentNode);
    visited[currentNode] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[currentNode][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int n; // Number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // Starting node for DFS
    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("DFS traversal starting from node %d: ", startNode);
    dfs(startNode);

    return 0;
}
