#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insert();
void delete();
void display();
void search();

int c = 0, b = 0;
void main()
{
    int a, ch;
    head = NULL;
    while (1)
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
}
void insert()
{
    int n, p, i;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp2, *x;
    scanf("%d %d", &n, &p);
    if (p <= 0 || p > c + 1)
        printf("Enter a valid position");
    else
    {
        c++;
        temp->data = n;
        temp->next = NULL;
        if (p == 1)
        {
            temp->next = head;
            head = temp;
            x = head;
            for (i = 1; i < c; i++)
            {
                x = x->next;
            }
            x->next = temp;
        }
        else
        {
            temp2 = head;
            for (i = 1; i < p - 1; i++)
                temp2 = temp2->next;
            temp->next = temp2->next;
            temp2->next = temp;
        }
    }
}
void delete()
{
    int p, i;
    struct node *temp1 = head, *temp2, *x;
    scanf("%d", &p);
    if (p <= 0 || p > c)
        printf("Enter a valid position");
    else
    {
        c--;
        if (p == 1)
        {
            head = temp1->next;
            free(temp1);
            x = head;
            for (i = 1; i < c; i++)
                x = x->next;
            x->next = head;
        }
        else
        {
            for (i = 1; i < p - 1; i++)
            {
                temp1 = temp1->next;
            }
            temp2 = temp1->next;
            temp1->next = temp2->next;
            free(temp2);
        }
    }
}
void search()
{
    int n, p = 0;
    struct node *x;
    scanf("%d", &n);
    x = head;
    do
    {
        if (x == NULL)
        {
            printf("List is empty\n");
            return;
        }
        p++;
        if (x->data == n)
        {
            printf("%d found at position %d\n", x->data, p);
            return;
        }
        x = x->next;
    } while (x != head);
    printf("element not found");
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}