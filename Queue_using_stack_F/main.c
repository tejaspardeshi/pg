
// queue using stack

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int item);
int pop1();
void push2(int item);
int pop2();

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    printf("\n--------------------------QUEUE USING STACK MENU---------------------");
    printf("\n1] Enqueue(push)  \n2] Dequeue(pop)  \n3] Display \n4] Exit");

    while(1)
        {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("\nExiting...\n"); break;
            default: printf("\nInvalid operation\n");
        }
    }

    return 0;
}

void push1(int item)
{
    if (top1 == MAX - 1)
        {
        printf("\nStack is full\n");
        }
    else
    {
        stack1[++top1] = item;
    }
}

int pop1()
{
    if (top1 == -1)
    {
        printf("\nStack is empty\n");
        return -1;
    }
    else
    {
        return stack1[top1--];
    }
}

void push2(int item)
{
    if (top2 == MAX - 1)
    {
        printf("\nStack 2 is full\n");
    }
    else
    {
        stack2[++top2] = item;
    }
}

int pop2()
{
    if (top2 == -1)
    {
        printf("\nStack 2 is empty\n");
        return -1;
    }
    else
    {
        return stack2[top2--];
    }
}

void enqueue()
{
    int item;
    if (top1 == MAX - 1)
    {
        printf("\nQueue is full (stack1 is full)\n");
    }
    else
    {
        printf("Enter value to enqueue: ");
        scanf("%d", &item);
        push1(item);
        printf("%d is successfully enqueued\n", item);
    }
}

void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        if (top2 == -1)         //stack1 to stack2
        {
            while (top1 != -1)
            {
                push2(pop1());
            }
        }
        printf("%d is successfully dequeued\n", pop2());
    }
}

void display()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements in the queue are:\n");
        for (int i = top2; i >= 0; i--)   // stack2
        {
            printf("%d\n", stack2[i]);
        }

        for (int i = 0; i <= top1; i++)     //stack1
        {
            printf("%d\n", stack1[i]);
        }
    }
}

