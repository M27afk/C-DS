#include <stdio.h>
#include <stdlib.h>
typedef struct time
{
    int hr, mn, s;
} T;
void check(T *t)
{
    if (t->s > 59)
    {
        t->mn += t->s / 60;
        t->s = t->s % 60;
    }
    if (t->mn > 59)
    {
        t->hr += t->mn / 60;
        t->mn = t->mn % 60;
    }
    if (t->hr >= 24)
    {
        t->mn = 0;
        t->s = 0;
        t->hr = 0;
    }
}
void display(T *t)
{
    printf("\nThe time is\n %.2d : %.2d : %.2d", t->hr, t->mn, t->s);
}

void read(T *t)
{
    printf("\nEnter hr:");
    scanf("%d", &(t->hr));
    printf("\nEnter min:");
    scanf("%d", &(t->mn));
    printf("\nEnter s:");
    scanf("%d", &(t->s));
    check(t);
}

void update(T *t)
{
    t->s += 1;
    check(t);
    display(t);
}

void addTime(T *t1, T *t2)
{
    read(t1);
    read(t2);
    t1->hr += t2->hr;
    t1->mn += t2->mn;
    t1->s += t2->s;
    check(t1);
    display(t1);
}

int main()
{
    T *t, *t1, *t2;
    T t3, t4, t5;
    t = &t3, t1 = &t4, t2 = &t5;

    int c;
    while (1)
    {
        printf("\nEnter the choice\n1.Read time\n2.Update time\n3.Add two time\n4. Display main time\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            read(t);
            break;
        case 2:
            update(t);
            break;
        case 3:
            addTime(t1, t2);
            break;
        case 4:
            display(t);
            break;
        default:
            exit(0);
        }
    }
}