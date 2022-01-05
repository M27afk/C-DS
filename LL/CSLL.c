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
    s->next = s;
    return s;
}
NODE insert_beg(NODE last, int item)
{
    NODE newnode = create();
    newnode->data = item;
    if (last == NULL)
    {
        return newnode;
    }
    newnode->next = last->next;
    last->next = newnode;
    return last;
}

NODE insert_end(NODE last, int item)
{
    NODE newnode = create();
    newnode->data = item;
    if (last == NULL)
    {
        return newnode;
    }
    newnode->next = last->next;
    last->next = newnode;
    return newnode;
}

NODE del_beg(NODE last)
{
    if (last == NULL)
    {
        printf("\nEmpty list!");
        return last;
    }
    if (last->next == last)
    {
        last = NULL;
        return last;
    }
    NODE temp = last->next;
    last->next = last->next->next;
    free(temp);
    return last;
}
NODE del_end(NODE last)
{
    if (last == NULL)
    {
        printf("\nEmpty list!");
        return last;
    }
    if (last->next == last)
    {
        last = NULL;
        return last;
    }
    NODE temp = last;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    return temp;
}
NODE insert_pos(NODE last, int pos, int key)
{
    NODE newnode = create(), prev = NULL, curr = last;
    newnode->data = key;
    int i = 0;
    while (i <= pos)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    newnode->next = curr;
    prev->next = newnode;
    count++;
    return last;
}
NODE reverse(NODE last){
	NODE cur,temp,t=NULL,first=last->link;
	cur=last;
	temp=last->link;
	while(t!=first){
		t=temp->link;
		temp->link=cur;
		cur=temp;
		temp=t;
	}
	return first;
}
NODE copy(NODE last){
	NODE temp,cur,newNode,second=NULL;
	temp=last->link;
	if(last==NULL){
		printf("Empty list!......");
	}
	do{
		newNode=create();
		newNode->data=temp->data;
		if(second==NULL){
			second=newNode;
		}
		else{
			cur->link=newNode;
		}
		cur=newNode;
		temp=temp->link;
	}while(temp!=last->link);
	newNode->link=second;
	return newNode;
}
NODE search(NODE last,int val){
    NODE temp;
    if(last==NULL){
        printf("Empty list!....");
        return last;
    }
    temp=last->link;
    int i=0;  
    if(temp->data==val){
        printf("The key found at postion 1");
        return last;
    }
    do{
        i++;
        if(temp->data==val){
            printf("The key found at postion %d",i);
            return last;
        }
        temp=temp->link;
        
    }while(temp!=last->link);
    printf("Key not found!....");
    return last;
}
int display(NODE last)
{
    printf("\n");
    if (last == NULL)
    {
        printf("\nEmpty list!");
        return 0;
    }
    NODE temp = last->next;
    while (temp != last)
    {

        printf("<%d>", temp->data);
        temp = temp->next;
    }
    printf("<%d>\n", last->data);
    return 0;
}

int main()
{
    int data, n;
    NODE last = NULL;
    while (1)
    {

        printf("\n Enter the choice \n1.Insert at the beginning\n 2. Insert at the end\n");
        scanf("%d", &n);
        switch (n)
        {
        /* case 0:
            display(last);
            break; */
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &data);
            last = insert_beg(last, data);
            break;
        case 2:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &data);
            last = insert_end(last, data);
            break;
        case 3:
            last = del_beg(last);
            break;
        case 4:
            last = del_end(last);
            break;
        case 5:
            printf("insert pos and ele");
            scanf("%d%d", &n, &data);
            last = insert_pos(last, n, data);
            break;

        default:
            exit(0);
        }
        display(last);
    }
}
