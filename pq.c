#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int *q, f, r;
} Q;
int l;
void insert(Q *qu)
{
    if (qu->r == l)
    {
        printf("\nOverflow");
        return;
    }

    printf("\nInsert ele");
    int i;
    scanf("%d", &i);
    int j = qu->r;
    while (j >= 0 && i < qu->q[j])
    {
        qu->q[j + 1] = qu->q[j];
        j--;
    }
    qu->q[j + 1] = i;
    qu->r = qu->r + 1;
}
void del(Q *qu)
{
    if (qu->f > qu->r)
    {
        printf("\nUnderflow");
        return;
    }
    qu->f++;
}
void disp(Q *qu)
{
    int i;
    if (qu->f > qu->r)
    {
        printf("\nQueue empty\n");
        return;
    }
    for (i = qu->f; i <= qu->r; i++)
        printf("%d\t", qu->q[i]);
}
int main()
{
    Q qu;
    qu.f = 0;
    qu.r = -1;

    printf("Enter no of ele\n");
    scanf("%d", &l);
    qu.q = (int *)calloc(l, sizeof(int));
    int ele, ch;
    for (;;)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(&qu);
            break;
        case 2:
            del(&qu);
            break;
        case 3:
            disp(&qu);
            break;
        case 4:
            exit(0);
        }
        disp(&qu);
    }
    return 0;
}
