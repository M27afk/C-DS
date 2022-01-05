#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE create()
{
    NODE head;
    head = (NODE)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory error\n");
    }
    head->llink = head;
    head->rlink = head;
    return head;
}
void display(NODE head)
{
    if (head->data == 0)
    {
        printf("list empty\n");
        return;
    }
    NODE temp = head->rlink;
    printf("\n[\t");
    do
    {
        printf("%d\t", temp->data);
        temp = temp->rlink;
    } while (temp != head);
    printf("]\n");
    return;
}
NODE insert_front(NODE head, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    temp->rlink = head->rlink;
    head->rlink = temp;
    (temp->rlink)->llink = temp;
    temp->llink = head;
    head->data++;
    return head;
}
NODE insert_rear(NODE head, int item)
{
    NODE temp, cur;
    temp = create();
    temp->data = item;
    cur = head->llink;
    cur->rlink = temp;
    temp->llink = cur;
    temp->rlink = head;
    head->llink = temp;
    head->data++;
    return head;
}
NODE delete_front(NODE head)
{
    if (head->data == 0)
    {
        printf("list is empty\n");
        return head;
    }
    NODE temp = head->rlink;
    head->rlink = temp->rlink;
    (temp->rlink)->llink = head;
    printf("%d", temp->data);
    free(temp);
    head->data--;
    return head;
}
NODE delete_rear(NODE head)
{
    if (head->rlink == head)
    {
        printf("list is empty\n");
        return head;
    }
    NODE temp = head->llink;
    temp->llink->rlink = head;
    head->llink = temp->llink;
    printf("%d", temp->data);
    free(temp);
    head->data--;
    return head;
}
NODE insert_pos(NODE head, int item, int pos)
{
    NODE temp;
    int i = 1;
    if (pos < 1 || pos > head->data + 1)
    {
        printf("invalid position\n");
        return head;
    }
    temp = create();
    temp->data = item;
    NODE prev = head, cur = head->rlink;
    while (i < pos)
    {
        prev = cur;
        cur = cur->rlink;
        i++;
    }
    prev->rlink = temp;
    temp->rlink = cur;
    temp->llink = prev;
    cur->llink = temp;
    head->data++;
    return head;
}
NODE delete_pos(NODE head, int pos)
{
    NODE temp;
    if (pos < 1 || pos > head->data)
    {
        printf("invalid position\n");
        return head;
    }
    NODE prev = head, cur = head->rlink;
    int i = 1;
    while (i < pos)
    {
        prev = cur;
        cur = cur->rlink;
        i++;
    }
    prev->rlink = cur->rlink;
    (cur->rlink)->llink = prev;
    printf("%d", cur->data);
    free(cur);
    head->data--;
    return head;
}
void reverse(NODE header)
{
    NODE temp, cur, t;
    if (header->rlink == header)
    {
        printf("\nEmpty list!......");
    }
    t = header->rlink;
    cur = header;

    while (t != header)
    {
        temp = t;
        t = t->rlink;
        temp->rlink = cur;
        cur->llink = temp;
        header->rlink = temp;
        temp->llink = header;
        cur = temp;
    }
}
NODE update(NODE head, int key, int item)
{
    if (head->rlink == head)
    {
        printf("list empty\n");
        return head;
    }
    NODE temp = head->rlink;
    if (temp->data == key)
    {
        temp->data = item;
        return head;
    }
    while (temp != head && temp->data != key)
    {
        temp = temp->rlink;
    }
    if (temp == head)
    {
        printf("unsuccessful\n");
        return head;
    }
    else
    {
        temp->data = item;
        printf("successful\n");
        return head;
    }
}
NODE search(NODE head, int key)
{
    int pos = 1;
    if (head->rlink == head)
    {
        printf("empty list\n");
        return head;
    }
    NODE temp = head->rlink;
    if (temp->data == key)
    {
        printf("found in position %d", pos);
        return head;
    }
    temp = temp->rlink;
    while (temp != head && temp->data != key)
    {
        temp = temp->rlink;
        pos++;
    }
    if (temp == head)
    {
        printf("key not found\n");
        return head;
    }
    else
    {
        printf("key found in position %d", pos + 1);
        return head;
    }
}
NODE ordered_list(NODE head, int item)
{
    NODE temp;
    temp = create();
    temp->data = item;
    if (head->rlink == head)
    {

        head->rlink = temp;
        temp->llink = head;
        head->llink = temp;
        temp->rlink = head;
        head->data++;
        return head;
    }
    NODE prev = head, cur = head->rlink;
    if (item < cur->data)
    {
        temp->rlink = cur;
        head->rlink = temp;
        cur->llink = temp;
        temp->llink = head;
        head->data++;
        return head;
    }
    prev = cur;
    cur = cur->rlink;
    while (cur != head && item >= cur->data)
    {
        prev = cur;
        cur = cur->rlink;
    }
    temp->rlink = prev->rlink;
    prev->rlink = temp;
    temp->llink = prev;
    cur->llink = temp;
    head->data++;
    return head;
}
NODE copy(NODE head)
{
    NODE second, temp, cur, prev;
    if (head->rlink == head)
    {
        printf("list empty\n");
        return head;
    }
    temp = create();
    cur = head->rlink;
    temp->data = cur->data;
    cur = cur->rlink;
    second = temp;
    prev = second;
    while (cur != head)
    {
        temp = create();
        temp->data = cur->data;
        prev->rlink = temp;
        temp->llink = prev;
        cur = cur->rlink;
        prev = prev->rlink;
    }
    head->rlink = second;
    second->llink = head;
    prev->rlink = head;
    head->llink = prev;
    return head;
}
int main()
{
    NODE head;
    head = create();
    head->data = 0;
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
            head = insert_front(head, item);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("enter the item to be insereted\n");
            scanf("%d", &item);
            head = insert_rear(head, item);
            break;
        case 4:
            head = delete_front(head);
            break;
        case 5:
            head = delete_rear(head);
            break;
        case 6:
            printf("enter the item to be inserted\n");
            scanf("%d", &item);
            printf("enter the position\n");
            scanf("%d", &pos);
            head = insert_pos(head, item, pos);
            break;
        case 7:
            printf("enter the position to be deleted\n");
            scanf("%d", &pos);
            head = delete_pos(head, pos);
            break;
        case 8:
            printf("reverse list\n");
            reverse(head);
            break;
        case 9:
            printf("enter the key to be updated\n");
            scanf("%d", &key);
            printf("enter the item to be updated with\n");
            scanf("%d", &item);
            head = update(head, key, item);
            break;
        case 10:
            printf("enter the key to be searched\n");
            scanf("%d", &key);
            head = search(head, key);
            break;
        case 11:
            printf("enter the item to be inserted\n");
            scanf("%d", &item);
            head = ordered_list(head, item);
            break;
        case 12:
            printf("the copy list is\n");
            head = copy(head);
            display(head);
            break;
        default:
            exit(0);
        }
        display(head);
    }
}
