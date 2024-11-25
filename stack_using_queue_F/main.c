
// stack using queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue1[MAX], queue2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue1(int item);
int dequeue1();
void enqueue2(int item);
int dequeue2();

void push();
void pop();
void display();

int main()
{
    int choice;
    printf("\n--------------------------STACK USING QUEUE MENU---------------------");
    printf("\n1] Push(enqueue)  \n2] Pop(dequeue)  \n3] Display \n4] Exit");

    while (1)
        {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("\nExiting...\n"); return 0;
            default: printf("\nInvalid operation\n");
        }
    }
}

void enqueue1(int item)
{
    if (rear1 == MAX - 1)
    {
        printf("\nQueue1 is full\n");
    }
    else
    {
        if (front1 == -1)
        {
            front1 = 0;
        }
        queue1[++rear1] = item;
    }
}

int dequeue1()
{
    if (front1 == -1 || front1 > rear1)
    {
        printf("\nQueue1 is empty\n");
        return -1;
    }
    else
    {
        return queue1[front1++];
    }
}

void enqueue2(int item)
{
    if (rear2 == MAX - 1)
    {
        printf("\nQueue2 is full\n");
    }
    else
    {
        if (front2 == -1)
        {
            front2 = 0;
        }
        queue2[++rear2] = item;
    }
}

int dequeue2()
{
    if (front2 == -1 || front2 > rear2)
    {
        printf("\nQueue2 is empty\n");
        return -1;
    }
    else
    {
        return queue2[front2++];
    }
}

void push()
{
    int item;
    if (rear1 == MAX - 1)
    {
        printf("\nStack is full (queue1 is full)\n");
    }
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &item);
        enqueue1(item);
        printf("%d is successfully pushed\n", item);
    }
}

void pop()
{
    if (front1 == -1 || front1 > rear1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        while (front1 != rear1)     // queue1 to queue2 except the last one
        {
            enqueue2(dequeue1());
        }

        // last remaining one element in queue1 is pop
        printf("%d is successfully popped\n", dequeue1());

        // Swap queue1 & queue2
        int tempFront = front1, tempRear = rear1;
        front1 = front2;
        rear1 = rear2;
        front2 = tempFront;
        rear2 = tempRear;
    }
}

void display()
{
    if (front1 == -1 || front1 > rear1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nElements in the stack are:\n");

        for (int i = front1; i <= rear1; i++)
        {
            printf("%d\n", queue1[i]);
        }
    }
}

