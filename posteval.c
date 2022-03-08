#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
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
    scanf("%s", exp);
    while ((ch = exp[i++]) != '\0')
    {
        // printf("\n%c", ch);
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
                n3 = n2 - n1;

                break;
            case '*':
                n3 = n2 * n1;

                break;
            case '/':
                n3 = n2 / n1;
                break;
            case '^':
                n3 = pow(n2, n1);

                break;
            default:
                printf("\nInvalid op");
                exit(0);
            }
            push(n3);
        }
    }
    printf("\n::%d", st[top]);
}
