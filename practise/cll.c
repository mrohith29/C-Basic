#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *getNode(int data)
{
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(int data, int pos)
{
    struct node *newNode = getNode(data);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct node *current = head;
        for (int i = 0; i < pos - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            printf("Invalid position, cannot insert.\n");
            free(newNode);
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    insert(12, 0);
    insert(13, 1);
    insert(15, 2);
    display();
    insert(18, 2);
    display();

    return 0;
}
