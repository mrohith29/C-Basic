#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head = NULL;

void push(int ele){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = head;
    head = newnode;
}

void pop(){
    struct node *temp = head;
    head = temp->next;
    free(temp);
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int choice, ele;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}