#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

struct node *getNode(int data)
{
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return newNode;
}

void insert(int data, int pos){
    struct node *newNode = getNode(data);
    if(head == NULL){
        head = newNode;
    }
    else if(pos == 0){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else{
        struct node *current = head;
        for (int i = 0; i < pos - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if(current->next != NULL){
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void display()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
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

int main(){
    insert(12, 0);
    insert(14, 1);
    insert(15, 2);
    insert(16, 3);
    insert(11, 1);
    display();
}