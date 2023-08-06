#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;

struct node *getNode(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int data){
    if(root == NULL){
        root = getNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
}

void levelOrder(struct node *root){
    if(root == NULL){
        return;
    }
    struct node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while(front != rear){
        struct node *current = queue[++front];
        printf("%d ", current->data);
        if(current->left != NULL){
            queue[++rear] = current->left;
        }
        if(current->right != NULL){
            queue[++rear] = current->right;
        }
    }
}

void max(struct node *root){
    if(root->right == NULL)
        return;
    else:
    max(root->right);
}

void min(struct node *root){
    if(root->left == NULL)
        return;
    else:
    min(root->left);
}

void delete_node(struct node *root, int data){
    if(root == NULL){
        free(root);
        root = NULL;
    }
    else if(root->left == NULL){
        struct node *temp = root;
        root = temp->right;
        free(temp);
    }
    else if(root->right == NULL){
        struct node *temp = root;
        root = temp->left;
        free(temp);
    }
    else{
        struct node *temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        delete_node(root->right, temp->data);
    }
}