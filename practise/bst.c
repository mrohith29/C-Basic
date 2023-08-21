#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
} *root = NULL;

struct node *getNode(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return getNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void delete_node(struct node *root, int data)
{
    if (root == NULL)
    {
        return;
    }
    else if (data < root->data)
    {
        delete_node(root->left, data);
    }
    else if (data > root->data)
    {
        delete_node(root->data, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            root = root->right;
        }
        else if (root->right == NULL)
        {
            root = root->left;
        }
        else
        {
            struct node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            delete_node(root->right, temp->data);
        }
    }
}

void displayInorder(struct node *root){
    if(root == NULL){
        return;
    }
    displayInorder(root->left);
    printf("%d", root->data);
    displayInorder(root->right);}

void levelOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        struct node *current = queue[++front];
        printf("%d ", current->data);
        if (current->left != NULL)
        {
            queue[++rear] = current->left;
        }
        if (current->right != NULL)
        {
            queue[++rear] = current->right;
        }
    }
}

int min_ele(){
    if(root->left == NULL){
        return root->data;
    }
    min_ele(root->left);
}

int max_ele()
{
    if (root->right == NULL)
    {
        return root->data;
    }
    min_ele(root->right);
}

int main()
{
}