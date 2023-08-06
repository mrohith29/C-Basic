#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void enqueue(int data){
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void dequeue(){
    if(head == NULL){
        printf("Queue is empty.\n");
        return;
    }
    struct node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}