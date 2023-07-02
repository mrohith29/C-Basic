#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x){
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t == NULL){
        printf("Queue is full\n");
    }else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front = rear = t;
        }else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x = -1;
    struct node *t;
    if(front == NULL){
        printf("Queue is empty\n");
    }else{
        t = front;
        front = front->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display(){
    struct node *p = front;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int choice, ele;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                printf("The dequeued element is %d\n", dequeue());
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