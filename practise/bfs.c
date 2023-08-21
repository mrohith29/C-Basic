#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100

// Queue data structure for BFS
int queue[MAX_NODES];
int front = -1, rear = -1;

// Adjacency matrix representation of the graph
int adjMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES]; // To keep track of visited nodes

// Function to enqueue a node
void enqueue(int node)
{
    if (rear == MAX_NODES - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = node;
    }
}

// Function to dequeue a node
int dequeue()
{
    int node;
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        node = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return node;
    }
}

// BFS traversal using adjacency matrix
void bfs(int start, int n)
{
    enqueue(start);
    visited[start] = 1;

    while (front != -1)
    {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[currentNode][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
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

    // Starting node for BFS
    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    bfs(startNode, n);

    return 0;
}
