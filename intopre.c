#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char st[30];
int top = -1;
void push(char ch)
{
    st[++top] = ch;
}
char pop()
{
    return st[top--];
}
int priority(char a)
{
    if (a == ')')
        return 0;
    else if (a == '+' || a == '-')
        return 1;
    else if (a == '/' || a == '*')
        return 2;
    else if (a == '^')
        return 3;
}

int main()
{
    char inf[30], pos[30], ch, n;
    int i = 0, k = 0;
    printf("\nEnter the exp: ");
    scanf("%s", &inf);
    int len = strlen(inf);
    while (len != -1)
    {
        ch = inf[len];
        if (isalnum(ch))
        {
            pos[k++] = ch;
        }
        else if (ch == ')')
        {
            push(ch);   
        }
        else if (ch == '(')
        {
            while (st[top] != ')')
            {
                pos[k++] = pop();
            }
            pop();
        }
        else
        {
            while (priority(st[top]) > priority(ch))
            {
                pos[k++] = pop();
            }
            push(ch);
        }
        len--;
    }
    while (top != -1)
    {
        pos[k++] = pop();
    }
    len = strlen(pos);
    for (int i = len; i > 0; i--)
    {
        printf("%c", pos[i]);
    }
}