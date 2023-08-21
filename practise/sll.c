#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

struct node *createNode(int data){
    struct node *temp = (struct node *)(malloc(sizeof(struct node)));
    temp->data = data;
    return temp;
}

void insert(int data, int pos){
    struct node *temp = createNode(data);
    if(pos == 0){
        temp->next = head;
        head = temp;
    }
    else{
        struct node *current = head;
        for (int i = 0; i < pos - 1; i++){
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void delete_node(int pos){
    struct node *current = head;
    if(pos == 0){
        head = current->next;
        free(current);
    }
    else{
        for (int i = 0; i < pos-1; i++)
        {
            current = current->next;
        }
        head = current->next->next;
        free(current);
    }
}

void display(){
    struct node *current = head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    insert(12, 0);
    insert(13, 0);
    insert(14, 0);
    insert(15, 0);
    insert(16, 0);
    display();
    delete_node(0);
    delete_node(0);
    display();
}