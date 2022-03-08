#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *rlink;
    struct node *llink;

} * NODE;
NODE create()
{
    NODE s;
    if ((s = (NODE)malloc(sizeof(struct node))) == NULL)
    {
        printf("\nMemeory error");
        exit(0);
    }
    s->llink = s;
    s->rlink = s;
    return s;
}
NODE insert(NODE n)
{
    int pos, item;
    printf("\nEnter position:");
    scanf("%d", &pos);
    if ((pos < 1) || (pos > (n->data) + 1))
    {
        printf("\nInvalid pos!\n");
        return n;
    }

    printf("\nEnter element:");
    scanf("%d", &item);

    printf("\n%d", n->data);
    NODE temp = create();
    temp->data = item;
    if (pos == 1)
    {

        temp->rlink = n->rlink;
        temp->llink = n;
        n->rlink->llink = temp;
        n->rlink = temp;
        n->data++;
        return n;
    }
    NODE prev = n, t = n->rlink;
    for (int i = 0; i < pos - 1; i++)
    {
        prev = t;
        t = t->rlink;
    }
    prev->rlink = temp;
    temp->rlink = t;
    temp->llink = prev;
    t->llink = temp;
    n->data++;
    return n;
}
NODE del(NODE n)
{
    if (n->data == 0)
    {
        printf("\nEmpty list");
        return n;
    }
    int pos;
    printf("\nEnter position:");
    scanf("%d", &pos);
    if ((pos < 1) || (pos > n->data))
    {
        printf("\nInvalid pos!\n");
        return n;
    }
    if (pos == 1)
    {

        NODE temp = n->rlink;
        n->rlink = n->rlink->rlink;
        free(n->rlink->llink);
        n->rlink->llink = n;
        n->data--;
        return n;
    }
    else
    {
        NODE prev = n, t = n->rlink;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = t;
            t = t->rlink;
        }
        prev->rlink = t->rlink;

        t->rlink->llink = prev;

        free(t);
        n->data--;
        return n;
    }
}
NODE reverse(NODE n)
{
    NODE temp, cur, t;
    if (n->data == 0)
    {
        printf("\nEMpty");
        return n;
    }
    t = n->rlink;
    cur = n;
    while (t != n)
    {
        temp = t;
        t = t->rlink;
        temp->rlink = cur;
        cur->llink = temp;
        n->rlink = temp;
        temp->llink = n;
        cur = temp;
    }
    return t;
}
void display(NODE n)
{
    if (n->data == 0)
    {
        printf("\nEMpty !");
        return;
    }
    NODE temp = n->rlink;
    printf("\n");
    do
    {
        printf("<%d>\t", temp->data);
        temp = temp->rlink;
    } while (temp != n);
}
int main()
{
    int ch;
    NODE n = create();
    n->data = 0;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Reverse\n5.Order\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            n = insert(n);
            break;
        case 2:
            n = del(n);
            break;

        // case 3:
        //     search(n);
        //     break;
        case 4:
            n = reverse(n);
            break;
        // case 5:
        //     n = order(n);
        //     break;
        default:
            exit(0);
        }
        display(n);
    }
}