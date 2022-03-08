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
    s->link = NULL;
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
        temp->link = n;
        count++;
        return temp;
    }
    // else if (pos == count + 1)
    // {
    //     NODE t = n;
    //     while (t->link != NULL)
    //     {
    //         t = t->link;
    //     }
    //     t->link = temp;
    //     count++;
    //     return n;
    // }
    else
    {
        NODE prev = NULL, t = n;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = t;
            t = t->link;
        }
        prev->link = temp;
        temp->link = t;
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

        NODE temp = n->link;
        free(n);
        count--;
        return temp;
    }
    else
    {
        NODE prev = NULL, t = n;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = t;
            t = t->link;
        }
        prev->link = t->link;
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
        t = t->link;
        i++;
    }
    printf("\nElement not found ");
}
NODE reverse(NODE n)
{
    if (n == NULL)
    {
        printf("\nEMpty !");
    }
    NODE temp = n, prev = NULL, t;
    while (temp != NULL)
    {
        t = temp->link;
        temp->link = prev;
        prev = temp;
        temp = t;
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
        info->link = n;
        return info;
    }
    NODE temp = n, prev = NULL;
    while ((temp != NULL) && (item > (temp->data)))
    {
        prev = temp;
        temp = temp->link;
    }

    prev->link = info;
    info->link = temp;
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
        temp = temp->link;
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