#include <stdio.h>
#include <stdlib.h>
#define max 5
typedef struct queue
{
    int q[max], f, r;
} Q;

void insert(Q *qu, int n)
{
    if (qu->r == max - 1)
    {
        printf("\nQueue full");
        return;
    }
    qu->r = qu->r + 1;
    qu->q[qu->r] = n;
}

int del(Q *qu)
{
    if (qu->f == max - 1 || qu->f > qu->r)
    {
        printf("\nQueue empty");
        return 0;
    }

    return qu->q[qu->f++];
}
void display(Q *qu)
{
    if (qu->f == max - 1 || qu->f > qu->r || qu->r == -1)
    {
        printf("\nQueue empty");
        return;
    }
    for (int i = qu->f; i <= qu->r; i++)
    {
        printf("%d\t", qu->q[i]);
    }
}

int main()
{
    Q qu;
    qu.f = 0;
    qu.r = -1;
    int ch, n;
    while (1)
    {
        printf("\n1.Insert\n2.Rear\n3.Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nINsert element :");
            scanf("%d", &n);
            insert(&qu, n);
            break;

        case 2:
            n = del(&qu);
            printf("\n%d\n", n);
            break;

        case 3:
            display(&qu);
            break;

        default:
            exit(0);
        }
        display(&qu);
    }
}