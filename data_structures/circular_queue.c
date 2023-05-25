#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull()
{
    if ((rear + 1) % MAX_SIZE == front)
        return 1;
    else
        return 0;
}

// Function to insert an element into the queue
void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = data;
    printf("Element %d enqueued successfully.\n", data);
}

// Function to remove an element from the queue
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue element.\n");
        return;
    }
    else if (front == rear)
    {
        printf("Element %d dequeued successfully.\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Element %d dequeued successfully.\n", queue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to display the elements of the queue
void displayQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[i]);
}

int main()
{
    int choice, ele;
    while(1){
        scanf("%d", &choice);
        switch (choice){
            case 1:
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
                break;
            default:
                return 0;
        }
    }
    return 0;
}