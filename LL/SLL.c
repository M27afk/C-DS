#include <stdio.h>
#include <stdlib.h>
int count = 0;
typedef struct node
{
    int data;
    struct node *next;
} * NODE;
NODE create()
{
    NODE s;
    if ((s = (NODE)malloc(sizeof(struct node))) == NULL)
    {
        printf("\n Memory error");
    }
    s->next = NULL;
    return s;
}
void display(NODE first, int count)
{
    if (count == 0)
    {
        printf("\n empty");
    }
    printf("\n");
    NODE temp;
    temp = first;
    while (temp != NULL)
    {
        printf("<%d>", temp->data);
        temp = temp->next;
    }
}
NODE insert_beg(NODE first, int info)
{
    NODE temp;
    temp = create();
    temp->data = info;
    if (first == NULL)
    {
        return temp;
    }
    temp->next = first;
    return temp;
}
NODE insert_end(NODE first, int info)
{
    NODE temp, trav;
    temp = create();
    temp->data = info;
    if (first == NULL)
    {
        return temp;
    }

    trav = first;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    trav->next = temp;
    return first;
}

NODE del_beg(NODE first)
{
    if (first == NULL)
    {
        printf("List empty ra mama");
        return first;
    }
    NODE temp = first;
    temp = temp->next;
    free(first);
    return temp;
}

NODE del_end(NODE first)
{
    if (first == NULL)
    {
        printf("List empty ra mama");
        return first;
    }
    NODE curr = first, prev = NULL;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return first;
}

NODE del_key(NODE first, int key)
{
    if (first == NULL)
    {
        printf("List empty ra mama");
        return first;
    }

    if (first->data == key)
    {
        del_beg(first);
    }
    int flag = 0;
    NODE curr = first, prev = NULL;
    while (curr->next != NULL)
    {
        if (curr->data == key)
        {
            flag = 1;
            prev->next = curr;

            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (flag == 0)
    {
        printf("\n Element not found");
    }

    return first;
}
NODE order(NODE first, int info)
{
    NODE temp1 = create();
    temp1->data = info;
    if (first == NULL)
    {
        return temp1;
    }
    if (info < first->data)
    {
        temp1->next = first;
        return temp1;
    }
    NODE prev = NULL, curr = first;
    while (info > curr->data && curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (info < curr->data && curr->next == NULL)
    {
        prev->next = temp1;
        temp1->next = curr;
        return first;
    }
    if (curr->next == NULL)
    {
        curr->next = temp1;
    }

    else
    {
        prev->next = temp1;
        temp1->next = curr;
    }
    return first;
}
NODE copy(NODE first)
{

    if (first == NULL)
        return NULL;

    NODE newHead = create();
    newHead->data = first->data;

    NODE p = newHead;
    first = first->next;
    while (first != NULL)
    {
        p->next = create();
        p = p->next;
        p->data = first->data;
        first = first->next;
    }
    p->next = NULL;
    return newHead;
}
NODE reverse(NODE first)
{
    NODE curr, temp, prev;
    curr = first;
    prev = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        // first = first->next;
        prev = curr;
        curr = temp;
    }
    first = prev;
    return first;
}
int main()
{
    NODE first = NULL, second;

    int choice, key, n;
    for (;;)

    {
        printf("\nEnter the choice");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the data to be inserted in the beginning");
            scanf("%d", &n);
            first = insert_beg(first, n);
            count++;
            break;
        case 2:
            display(first, count);
            break;
        case 3:
            printf("\n Enter the data to be inserted in the end");
            scanf("%d", &n);
            first = insert_end(first, n);
            count++;
            break;
        case 4:
            first = del_beg(first);
            count--;
            break;
        case 5:
            first = del_end(first);
            count--;
            break;
        case 6:
            printf("\n Enter the data to be inserted in order:");
            scanf("%d", &n);
            first = order(first, n);
            count++;
            break;
        case 7:
            first = reverse(first);
            break;
        case 8:
            second = copy(first);
            printf("\nThe copied list in\n");
            display(second, count);
            break;
        default:
            exit(0);
        }
        display(first, count);
    }

    return 0;
}
