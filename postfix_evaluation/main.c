//postfix expression

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100
#define PMAX 100

int stack[MAX];
int top = -1;

void push(int item)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        stack[++top] = item;
    }
}

int pop(int item)
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        item = stack[top--];
    }
}

int main()
{
    int i;
    char postfix[PMAX];

    printf("Postfix Expression contains: \n 4 Operators (+, -, *, /) \n Operands are Single Digit \n Expression ends with ')'\n");
    printf("Enter the postfix Expression: ");
    scanf("%s", postfix);            // important & is not apply

    for (i = 0; postfix[i] != ')'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0'); // Convert character to integer
        }
        else
        {
            int a = pop();
            int b = pop();

            switch (postfix[i])
            {
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*':
                    push(b * a);
                    break;
                case '/':
                    if (a == 0)
                    {
                        printf("check Denominator never zero\n");
                        return 1;
                    }
                    else
                    {
                        push(b / a);
                    }
                    break;
                default:
                    printf("Please enter a valid operator\n");
                    return 1;
            }
        }
    }

    printf("The result of evaluation of the postfix expression is: %d\n", pop());
    return 0;
}
