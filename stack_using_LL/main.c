/
// Stack using L.L
#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void show();

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    int choice = 0;
    printf("\n*****MENU of Stack Using L.L.*****\n");
    printf("\n 1. Push\n 2. Pop\n 3. Show\n 4. Exit\n");

    while(1)
    {
        printf("\nEnter your choice among 1 to 4: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: show();
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nPlease Enter The Valid Input\n");
                    break;
        }
    }

    return 0;
}

void push()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Not able to push element\n");
    }
    else
    {
        printf("Enter value to add: ");
        scanf("%d",&val);

        ptr->val = val;
        ptr->next = head;
        head = ptr;

        printf("%d is ADDED \n",val);
    }
}

void pop()
{
    int item;
    struct node *ptr;

    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("%d is REMOVED \n",item);
    }
}

void show()
{
    struct node *ptr = head;

    if (ptr == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("The stack elements are:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}
*/
