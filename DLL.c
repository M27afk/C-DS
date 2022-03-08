#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *rlink;
    struct node *llink;

} * NODE;
int count = 0;
NODE create()
{
    NODE s;
    if ((s = (NODE)malloc(sizeof(struct node))) == NULL)
    {
        printf("\nMemeory error");
        exit(0);
    }
    s->llink = NULL;
    s->rlink = NULL;
    return s;
}

NODE insert(NODE n)
{
    int pos, item;
    printf("\nEnter position:");
    scanf("%d", &pos);
    if ((pos < 1) || (pos > count + 1))
    {
        printf("\nInvalid pos!\n");
        return n;
    }

    printf("\nEnter element:");
    scanf("%d", &item);

    printf("\n%d", count);
    NODE temp = create();
    temp->data = item;
    if (pos == 1)
    {
        if (n == NULL)
        {
            count++;
            return temp;
        }
        temp->rlink = n;
        n->llink = temp;
        count++;
        return temp;
    }
    else
    {
        NODE prev = NULL, t = n;
        int i = 0;
        while (i < pos - 1)
        {
            prev = t;
            t = t->rlink;
            i++;
        }
        temp->rlink = prev->rlink;

        prev->rlink = temp;
        temp->llink = prev;
        if (t != NULL)
        {
            (t)->llink = temp;
            count++;
            return n;
        }
        count++;
        return n;
    }
}

NODE del(NODE n)
{
    if (n == NULL)
    {
        printf("\nEmpty list");
        return n;
    }
    int pos;
    printf("\nEnter position:");
    scanf("%d", &pos);
    if ((pos < 1) || (pos > count))
    {
        printf("\nInvalid pos!\n");
        return n;
    }
    if (pos == 1)
    {
        if (count == 1)
        {
            free(n);
            count--;
            return NULL;
        }
        n = n->rlink;
        free(n->llink);
        count--;
        return n;
    }
    else
    {
        NODE prev = NULL, t = n;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = t;
            t = t->rlink;
        }
        prev->rlink = t->rlink;
        if (t->rlink != NULL)
        {
            t->rlink->llink = prev;
        }
        free(t);
        count--;
        return n;
    }
}
void search(NODE n)
{
    printf("\nEnter element to be searched\n");
    int k;
    scanf("%d", &k);
    NODE t = n;
    int i = 0;
    while (t != NULL)
    {
        if (t->data == k)
        {
            printf("\nElement found at %d pos", i + 1);
            return;
        }
        t = t->rlink;
        i++;
    }
    printf("\nElement not found ");
}
NODE reverse(NODE n)
{
    NODE temp = n, prev = NULL;
    while (n != NULL)
    {
        n = n->rlink;
        temp->rlink = prev;
        if (prev != NULL)
        {
            prev->llink = temp;
        }
        prev = temp;
        temp = n;
    }
    return prev;
}
NODE order(NODE n)
{
    int item;
    printf("\nEnter element:");
    scanf("%d", &item);
    NODE info = create();
    info->data = item;
    count++;
    if (n == NULL || (item < n->data))
    {
        info->rlink = n;
        return info;
    }
    NODE temp = n, prev = NULL;
    while ((temp != NULL) && (item > (temp->data)))
    {
        prev = temp;
        temp = temp->rlink;
    }

    prev->rlink = info;
    info->llink = prev;
    info->rlink = temp;
    if (temp != NULL)
    {
        temp->llink = info;
    }

    return n;
}
void display(NODE n)
{
    if (n == NULL)
    {
        printf("\nEMpty !");
    }
    NODE temp = n;
    printf("\n");
    while (temp != NULL)
    {
        printf("<%d>\t", temp->data);
        temp = temp->rlink;
    }
}
int main()
{
    int ch;
    NODE n = NULL;
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
        case 3:
            search(n);
            break;
        case 4:
            n = reverse(n);
            break;
        case 5:
            n = order(n);
            break;
        default:
            exit(0);
        }
        display(n);
    }
}