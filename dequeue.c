#include <stdio.h>
#include <stdlib.h>
int k;
typedef struct queue
{
    int *q, f, r;
} Q;
void inf(Q *qu, int n)
{
    if (qu->f == 0)
    {
        printf("\nFront insertion not possible\n");
        return;
    }
    if (qu->f == -1)
    {
        qu->f++;
        qu->q[qu->f] = n;
        qu->r = 0;
    }
    else
    {
        qu->q[--qu->f] = n;
    }
}

void inr(Q *qu, int n)
{
    if (qu->r == k - 1)
    {
        printf("\nRear insertion not possible\n");
        return;
    }
    qu->q[++qu->r] = n;
    if (qu->f == -1)
        qu->f = 0;
}

void def(Q *qu)
{
    if (qu->f > qu->r || qu->f == k)
    {
        printf("\nFront deletion not possible\n");
        return;
    }
    qu->f++;
}

void der(Q *qu)
{
    if (qu->f > qu->r || qu->r == -1)
    {
        printf("\nrear deletion not possible\n");
        return;
    }
    qu->r--;
}
void display(Q *qu)
{
    if (qu->f == k || qu->f > qu->r || qu->r == -1)
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
    qu.f = -1;
    qu.r = -1;
    int t;
    printf("\nEnter the num of elements\n");
    scanf("%d", &k);

    qu.q = (int *)calloc(t, sizeof(int));
    int ch, n;
    while (1)
    {
        printf("\n1.Ins F\n2.Ins R\n3.Del F\n4.Del R\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEle to be inserted:");
            scanf("%d", &n);
            inf(&qu, n);
            break;
        case 2:
            printf("\nEle to be inserted:");
            scanf("%d", &n);
            inr(&qu, n);
            break;
        case 3:
            def(&qu);
            break;
        case 4:
            der(&qu);
            break;
        default:
            exit(0);
        }
        display(&qu);
    }
}