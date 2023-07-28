#include <stdio.h>
#include <stdlib.h>

struct node
{
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

struct node *insert(struct node *root, int data)
{
  if (root == NULL)
  {
    root = getNode(data);
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

int search(struct node *root, int data)
{
  if (root == NULL)
  {
    return 0;
  }
  else if (root->data == data)
  {
    return 1;
  }
  else if (data <= root->data)
  {
    return search(root->left, data);
  }
  else
  {
    return search(root->right, data);
  }
}

void displayInorder(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  displayInorder(root->left);
  printf("%d ", root->data);
  displayInorder(root->right);
}

void displayPreorder(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  printf("%d ", root->data);
  displayPreorder(root->left);
  displayPreorder(root->right);
}

void displayPostorder(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  displayPostorder(root->left);
  displayPostorder(root->right);
  printf("%d ", root->data);
}

void delete(struct node *root, int data)
{
  if (root == NULL)
  {
    return;
  }
  else if (data < root->data)
  {
    delete (root->left, data);
  }
  else if (data > root->data)
  {
    delete (root->right, data);
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
      struct node *temp = root;
      root = root->right;
      free(temp);
    }
    else if (root->right == NULL)
    {
      struct node *temp = root;
      root = root->left;
      free(temp);
    }
    else
    {
      struct node *temp = root->right;
      while (temp->left != NULL)
      {
        temp = temp->left;
      }
      root->data = temp->data;
      delete (root->right, temp->data);
    }
  }
}

int min_ele(struct node *root)
{
  if (root->left == NULL)
  {
    return root->data;
  }
  min_ele(root->left);
}

int max_ele(struct node *root)
{
  if (root->right == NULL)
  {
    return root->data;
  }
  max_ele(root->right);
}

int getMax(int a, int b)
{
  return a > b ? a : b;
}

int getHeight(struct node *root)
{
  if (root == NULL)
  {
    return -1;
  }
  else
  {
    return (1 + getMax(getHeight(root->left), getHeight(root->right)));
  }
}

int countNodes(struct node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    return (1 + countNodes(root->left) + countNodes(root->right));
  }
}