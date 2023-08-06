#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head = NULL;

struct node *getNode(int data){
    struct node *newNode = (struct node *)(malloc(sizeof(struct node)));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void insert(int data, int pos){
    struct node *newNode = getNode(data);
    if(pos==0){
        newNode->next = head;
        head = newNode;
    }
    else{
        struct node *current = head;
        for (int i = 0; i < pos - 1;i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void delete_node(int pos){
    struct node *temp = head;
    if(pos == 0){
        head = temp->next;
        free(temp);
    }
    else{
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        head = temp->next->next;
        free(temp);
    }
}

void display(){
    struct node *current = head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
    free(current);
    printf("\n");
}

int main(){
    insert(12, 0);
    insert(13, 1);
    insert(15, 2);
    display();
    insert(18, 2);
    delete_node(0);
    display();
}