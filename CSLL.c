#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} * NODE;
int count = 0;

NODE create()
{
    NODE s;
    if ((s = (NODE)malloc(sizeof(struct node))) == NULL)
    {
        printf("\nMem error!");
        exit(0);
    }
    s->link = s;
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

        temp->link = n->link;
        n->link = temp;
        count++;
        return n;
    }
    if (pos == count + 1)
    {
        temp->link = n->link;
        n->link = temp;
        count++;
        return temp;
    }
    NODE t = n->link, prev = n;
    int i = 0;
    while (i < pos - 1)
    {
        prev = t;
        t = t->link;
        i++;
    }
    prev->link = temp;
    temp->link = t;
    count++;
    return n;
}
NODE del(NODE n)
{
    int pos;
    printf("\nEnter position:");
    scanf("%d", &pos);
    if ((pos < 1) || (pos > count))
    {
        printf("\nInvalid pos!\n");
        return n;
    }
    if (count == 0)
    {
        printf("\nEMpty\n");
        return n;
    }

    if (pos == 1)
    {
        if (n->link == n)
        {
            count--;
            return NULL;
        }
        NODE temp;
        temp = n->link;
        n->link = temp->link;
        free(temp);

        count--;
        return n;
    }
    // if (pos == count)
    // {
    //     NODE temp;
    //     while (temp->link != n)
    //     {
    //         temp = temp->link;
    //     }

    //     temp->link = n->link;
    //     free(n);

    //     count--;
    //     return temp;
    // }
    NODE t = n->link, prev = n;
    int i = 0;
    while (i < pos - 1)
    {
        prev = t;
        t = t->link;
        i++;
    }
    prev->link = t->link;
    free(t);

    if (pos == count)
    {
        count--;
        return prev;
    }
    count--;
    return n;
}
void search(NODE n)
{
    if (n == NULL)
    {
        printf("\nEMpty !");
        return;
    }
    int item, i = 0;
    printf("\nEnter element:");
    scanf("%d", &item);
    NODE temp = n->link;
    while (i <= count)
    {
        if (temp->data == item)
        {
            printf("\nFound at %d\n", i + 1);
            return;
        }
        temp = temp->link;
        i++;
    }
    printf("\nNOt Found at \n");
}
NODE delkey(NODE n)
{
    if (n == NULL)
    {
        printf("\nEMpty !");
        return n;
    }
    int item, i = 0;
    printf("\nEnter element:");
    scanf("%d", &item);
    NODE temp = n->link, prev = n;
    if (count == 1 && item == n->data)
    {
        free(n);
        count--;
        return NULL;
    }

    while (i <= count)
    {
        if (temp->data == item)
        {
            printf("\nFound at %d\n", i + 1);
            prev->link = temp->link;
            free(temp);
            count--;
            if (i == count)
            {
                return prev;
            }
            return n;
        }
        prev = temp;
        temp = temp->link;
        i++;
    }
    printf("\nNOt Found at \n");
    return n;
}
NODE reverse(NODE n)
{
    if (n == NULL)
    {
        printf("\nEmpty ");
        return n;
    }
    if (count == 1)
    {
        return n;
    }
    NODE first = n->link, prev = n->link, t = n, temp = NULL;
    while (temp != first)
    {
        temp = prev->link;
        prev->link = t;
        t = prev;
        prev = temp;
    }
    return first;
}
NODE order(NODE n)
{
    int item;
    printf("\nEnter element:");
    scanf("%d", &item);

    printf("\n%d", count);
    NODE temp = create();
    temp->data = item;

    if (n == NULL)
    {
        count++;
        return temp;
    }
    NODE t = n->link, prev = NULL;
    // int i = 0;
    while (prev != n && item > t->data)
    {
        prev = t;
        t = t->link;
    }
    prev->link = temp;
    temp->link = t;
    count++;
    if (prev == n)
    {
        return temp;
    }
    return n;
}
void display(NODE n)
{
    if (n == NULL)
    {
        printf("\nEMpty !");
        return;
    }
    NODE temp = n->link;
    printf("\n");
    while (temp != n)
    {
        printf("<%d>", temp->data);
        temp = temp->link;
    }
    printf("<%d>\n", n->data);
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
        case 6:
            n = delkey(n);
            break;
        default:
            exit(0);
        }
        display(n);
    }
}
