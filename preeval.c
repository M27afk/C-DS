#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
char st[30];
int top = -1;
void push(int x)
{
    st[++top] = x;
}
char pop()
{
    return st[top--];
}
int main()
{
    printf("\nEnter the expression:");
    char exp[30], ch;
    int n1, n2, n3;
    int i = 0;
    scanf("%s", &exp);
    int len = strlen(exp);
    while (len != -1)
    {
        ch = exp[len];
        if (isdigit(ch))
        {
            n3 = ch - 48;
            push(n3);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (ch)
            {
            case '+':
                n3 = n2 + n1;

                break;
            case '-':
                n3 = n1 - n2;

                break;
            case '*':
                n3 = n2 * n1;

                break;
            case '/':
                n3 = n1 / n2;

                break;
            case '^':
                n3 = pow(n1, n2);

                break;
            }
            push(n3);
        }
        len--;
    }
    printf("\n::%d", pop());
}
