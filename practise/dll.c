#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

struct node *createNode(int data)
{
    struct node *temp = (struct node *)(malloc(sizeof(struct node)));
    temp->data = data;
    return temp;
}

void insert(int data, int pos){
    struct node *current = head;
    struct node *temp = createNode(data);
    if(pos == 0){
        temp->next = current;
        current->prev = temp;
        current = temp;
    }
    else{
        for (int i = 0; i < pos - 1 && current != NULL; i++)
        {
            current = current->next;
        }
        temp->next = current->next;
        temp->prev = current;
        if (current->next != NULL)
            current->next->prev = temp;
        current->next = temp;
    }
}

void rev_display()
{
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void display(){
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
}

int main(){
    insert(12, 0);
    insert(13, 0);
    display();

    return 0;
}