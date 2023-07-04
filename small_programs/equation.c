#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
};

struct Node *head = NULL; 

struct Node *createNode(int coefficient, int exponent)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void addTerm(int coefficient, int exponent)
{
    struct Node *newNode = createNode(coefficient, exponent);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *lastNode = head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void displayPolynomial()
{
    if (head == NULL)
    {
        printf("Polynomial is empty.\n");
    }
    else
    {
        struct Node *currentNode = head;
        while (currentNode != NULL)
        {
            if(currentNode->exponent == 0)
                printf("%d", currentNode->coefficient);
            else if(currentNode->exponent == 1)
                printf("%dx", currentNode->coefficient);
            else{
                printf("%dx^%d", currentNode->coefficient, currentNode->exponent);
            }
            currentNode = currentNode->next;
            if (currentNode != NULL)
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    int exponent = n - 1;
    for(int i = exponent; i >= 0; i--)
    {
        int coefficient;
        printf("Enter the coefficient and of exponent term %d: ", i);
        scanf("%d", &coefficient);
        addTerm(coefficient, i);
    }
    printf("The polynomial is: ");
    displayPolynomial();

    return 0;
}
