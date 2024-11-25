//infix to postfix

#include <stdio.h>
#include <string.h>
# define MAXSTACK 50

char stack[MAXSTACK];
int top = -1;

void push(char symbol)
{
    if (top >= MAXSTACK-1)
    {
        printf("Stack is overflow\n");
        return;
    } else
    {
        stack[++top] = symbol;
    }
}

char pop()
{
    char item;
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return 0;
    } else
    {
        item = stack[top--];
    }
    return item;
}

int precedence(char ch)
{
    if (ch == '/')
        {
        return 5;
        }
    else if (ch == '*')
        {
        return 4;
        }
    if (ch == '+' || ch == '-')
    {
        return 3;
    }
    else
    {
        return 2;
    }
}

void post(char infix[])
{
    int l;
    int index = 0, position = 0;
    char symbol, temp;
    char postfix[40];
    l = strlen(infix);
    push('#');
    while (index < l)
        {
        symbol = infix[index];
        switch (symbol)
        {
            case '(': push(symbol);
            break;
            case ')': temp = pop();

            while (temp != '(')
                {
                    postfix[position++] = temp;
                    temp = pop();
                }
                    break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '^':
                    while (precedence(stack[top]) >= precedence(symbol))
                    {
                        temp = pop();
                        postfix[position++] = temp;
                    }
                    push(symbol);
                    break;
                    default: postfix[position++] = symbol;
                    break;
        }
        index++;
    }
    while (stack[top] != '#')
        {
            temp = pop();
            postfix[position++] = temp;
        }
    postfix[position] = '\0';
    puts(postfix);
    return;
}

int main()
{
    char infix[25];
    printf("\nEnter the infix expression = ");
    gets(infix);
    post(infix);

    printf("\nPostfix expression: %s\n", postfix);
    return 0;
}
