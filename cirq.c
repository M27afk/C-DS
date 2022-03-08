#include <stdio.h>
#include <stdlib.h>
int max;
int count = 0;
typedef struct queue
{
    int *q, f, r;
} Q;

void ins(Q *qu)
{
    if ((qu->f == qu->r + 1) || (qu->f == 0 && qu->r == max - 1))
    {
        printf("\nQueue overflow");
        return;
    }
    int n;
    count++;
    printf("\nEnter element:");
    scanf("%d", &n);
    (qu->r) = ((qu->r) + 1) % max;
    qu->q[qu->r] = n;
    if (qu->f == -1)
    {
        qu->f = 0;
    }
    // printf("\n%d%d", qu->f, qu->r);
}

void del(Q *qu)
{
    if (qu->r == -1 && qu->f == -1)
    {
        printf("\nQueue underflow");
        return;
    }
    else if (qu->f == qu->r)
    {
        printf("\ndeleted %d", qu->q[qu->f]);
        count--;
        qu->f = -1;
        qu->r = -1;
    }
    else
    {
        printf("\ndeleted %d", qu->q[qu->f]);
        (qu->f) = (qu->f + 1) % max;
        count--;
    }
    printf("\n%d%d", qu->f, qu->r);
}

void disp(Q *q)
{
    if (q->f == -1)
    {
        printf("\nQueue underflow");
        return;
    }
    int i;
    printf("\n");
    for (i = q->f; i != q->r; i = (i + 1) % max)
    {
        printf("%d ", q->q[i]);
    }
    printf("%d ", q->q[i]);
}

int main()
{
    Q qu;
    qu.f = -1;
    qu.r = -1;
    int ch;
    printf("\nEnter the number of items\n ");

    scanf("%d", &max);
    qu.q = (int *)calloc(max, sizeof(int));
    while (1)
    {

        printf("\n1.Insert\n2.Delete\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            ins(&qu);
            break;
        case 2:
            del(&qu);
            break;
        default:
            exit(0);
        }
        disp(&qu);
    }
}