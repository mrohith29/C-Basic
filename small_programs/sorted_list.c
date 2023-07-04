#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *currentNode = *head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void printList(struct Node *head)
{
    struct Node *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Bubble sort algorithm to sort the linked list
void sortLinkedList(struct Node **head)
{
    struct Node *currentNode = *head;
    struct Node *index = NULL;
    int temp;

    if (currentNode == NULL)
    {
        return;
    }
    else
    {
        while (currentNode != NULL)
        {
            index = currentNode->next;

            while (index != NULL)
            {
                if (currentNode->data > index->data)
                {
                    temp = currentNode->data;
                    currentNode->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            currentNode = currentNode->next;
        }
    }
}

int main()
{
    struct Node *head = NULL;

    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 9);

    printf("Original Linked List: ");
    printList(head);

    sortLinkedList(&head);

    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}
