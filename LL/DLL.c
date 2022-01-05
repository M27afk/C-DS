#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE p = NULL;
NODE create()
{
    NODE first;
    first = (NODE)malloc(sizeof(struct node));
    if (first == NULL)
    {
        printf("memory error\n");
        return first;
    }
    first->llink = first->rlink = NULL;
    return first;
}
void display(NODE first)
{
    if (first == NULL)
    {
        printf("list empty\n");
        return;
    }
    NODE temp = first;
    printf("\n[\t");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->rlink;
    }
    printf("]\n");
    return;
}
NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    if (first == NULL)
    {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;
}
NODE insert_rear(NODE first, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    if (first == NULL)
    {
        return temp;
    }
    NODE cur = first;
    while (cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    temp->rlink = NULL;
    return first;
}
NODE delete_front(NODE first)
{
    if (first == NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    NODE temp = first;
    first = first->rlink;
    first->llink = NULL;
    printf("%d", temp->data);
    free(temp);
    return first;
}
NODE delete_rear(NODE first)
{
    if (first == NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    NODE cur = first;
    while (cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    (cur->llink)->rlink = NULL;
    printf("%d", cur->data);
    free(cur);
    return first;
}
int count(NODE first)
{
    NODE temp;
    int count = 1;
    temp = first;
    while (temp->rlink != NULL)
    {
        temp = temp->rlink;
        count++;
    }
    return count;
}
NODE insert_pos(NODE first, int item, int pos)
{
    NODE temp;
    int c, i = 2;
    c = count(first);
    if (pos < 1 || pos > c + 1)
    {
        printf("invalid position\n");
        return first;
    }
    temp = create();
    temp->data = item;
    if (pos == 1)
    {
        temp->rlink = first;
        first->llink = temp;
        c++;
        return temp;
    }
    NODE prev = first, cur = first->rlink;
    while (i < pos)
    {
        prev = cur;
        cur = cur->rlink;
        i++;
    }
    temp->rlink = cur;
    prev->rlink = temp;
    temp->llink = prev;
    if (cur != NULL)
    {
        cur->llink = temp;
        return first;
    }
    return first;
}
NODE delete_pos(NODE first, int pos)
{
    int c;
    NODE temp;
    c = count(first);
    if (pos < 1 || pos > c)
    {
        printf("invalid position\n");
        return first;
    }
    if (pos == 1)
    {
        temp = first;
        first = first->rlink;
        first->llink = NULL;
        printf("%d", temp->data);
        free(temp);
        c--;
        return first;
    }
    NODE prev = first, cur = first->rlink;
    int i = 2;
    while (i < pos)
    {
        prev = cur;
        cur = cur->rlink;
        i++;
    }
    prev->rlink = cur->rlink;
    if (cur->rlink != NULL)
    {
        (cur->rlink)->llink = prev;
    }
    printf("%d", cur->data);
    free(cur);
    c--;
    return first;
}
NODE reverse(NODE first)
{
    NODE temp, cur;
    temp = first;
    cur = NULL;
    while (first != NULL)
    {
        first = first->rlink;
        temp->rlink = cur;
        if (cur != NULL)
        {
            cur->llink = temp;
        }
        cur = temp;
        temp = first;
    }
    return cur;
}
NODE update(NODE first, int key, int item)
{
    if (first == NULL)
    {
        printf("list empty\n");
        return NULL;
    }
    if (first->data == key)
    {
        first->data = item;
        return first;
    }
    NODE temp = first->rlink;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->rlink;
    }
    if (temp == NULL)
    {
        printf("unsuccessful\n");
        return first;
    }
    else
    {
        temp->data = item;
        printf("successful\n");
        return first;
    }
}
NODE search(NODE first, int key)
{
    int pos = 1;
    if (first == NULL)
    {
        printf("empty list\n");
        return NULL;
    }
    if (first->data == key)
    {
        printf("found in position %d", pos);
        return first;
    }
    NODE temp = first->rlink;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->rlink;
        pos++;
    }
    if (temp == NULL)
    {
        printf("key not found\n");
        return first;
    }
    else
    {
        printf("key found in position %d", pos + 1);
        return first;
    }
}
NODE ordered_list(NODE first, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    if (first == NULL)
    {
        return temp;
    }
    if (item < first->data)
    {
        temp->rlink = first;
        first->llink = temp;
        return temp;
    }
    NODE prev = first, cur = first->rlink;
    while (cur != NULL && item >= cur->data)
    {
        prev = cur;
        cur = cur->rlink;
    }
    if (cur == NULL)
    {
        prev->rlink = temp;
        temp->llink = prev;
        temp->rlink = cur;
        return first;
    }
    else
        temp->rlink = cur;
    prev->rlink = temp;
    temp->llink = prev;
    cur->llink = temp;
    return first;
}
NODE copy(NODE first)
{
    NODE second, temp, cur, prev;
    if (first == NULL)
    {
        printf("list empty\n");
        return NULL;
    }
    temp = create();
    cur = first;
    temp->data = cur->data;
    cur = cur->rlink;
    second = temp;
    prev = second;
    while (cur != NULL)
    {
        temp = create();
        temp->data = cur->data;
        prev->rlink = temp;
        temp->llink = prev;
        cur = cur->rlink;
        prev = prev->rlink;
    }
    prev->rlink = NULL;
    return second;
}
int main()
{
    int choices, pos, item, key;
    for (;;)
    {
        printf("\nM E N U\n");
        printf("1.insert_front\n2.display\n3.insert_rear\n4.delete_front\n5.delete_rear\n6.insert_pos\n7.delete_pos\n8.reverse\n9.update\n10.search\n11.ordered list\n12.copy\n");
        scanf("%d", &choices);
        switch (choices)
        {
        case 1:
            printf("enter the item to be inserted\n");
            scanf("%d", &item);
            p = insert_front(p, item);
            break;
        case 2:
            display(p);
            break;
        case 3:
            printf("enter the item to be insereted\n");
            scanf("%d", &item);
            p = insert_rear(p, item);
            break;
        case 4:
            p = delete_front(p);
            break;
        case 5:
            p = delete_rear(p);
            break;
        case 6:
            printf("enter the item to be inserted\n");
            scanf("%d", &item);
            printf("enter the position\n");
            scanf("%d", &pos);
            p = insert_pos(p, item, pos);
            break;
        case 7:
            printf("enter the position to be deleted\n");
            scanf("%d", &pos);
            p = delete_pos(p, pos);
            break;
        case 8:
            printf("reverse list\n");
            p = reverse(p);
            break;
        case 9:
            printf("enter the key to be updated\n");
            scanf("%d", &key);
            printf("enter the item to be updated with\n");
            scanf("%d", &item);
            p = update(p, key, item);
            break;
        case 10:
            printf("enter the key to be searched\n");
            scanf("%d", &key);
            p = search(p, key);
            break;
        case 11:
            printf("enter the item to be inserted\n");
            scanf("%d", &item);
            p = ordered_list(p, item);
            break;
        case 12:
            printf("the copy list is\n");
            p = copy(p);
            display(p);
            break;
        case 13:
            count(p);
            break;
        default:
            exit(0);
        }
    }
}
