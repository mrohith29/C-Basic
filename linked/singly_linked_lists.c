// Singly Linked Lists in c are a data structure that can be used to store a list of values.
// They are defined as structures with a pointer to the next node in the list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insert_at_beginning(int ele){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int ele){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = NULL;
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_position(int ele, int pos){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = ele;
    struct node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_beginning(){
    struct node *temp = head;
    head = temp->next;
    free(temp);
}

int main(){
    int choice, ele, pos;
    while(1){
        printf("\n1. Display\n2. Insert at beginning\n3. Insert at end\n4. Insert at position\n5. Delete at beginning\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                display();
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert_at_beginning(ele);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                insert_at_end(ele);
                break;
            case 4:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_at_position(ele, pos);
                break;
            case 5:
                delete_at_beginning();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}