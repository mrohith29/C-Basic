#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void push(int data){
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void pop(){
    if(head == NULL){
        printf("Stack is empty.\n");
        return;
    }
    struct node *temp = head;
    head = temp->next;
    free(temp);
}

