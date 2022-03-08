#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[20];
    int rn, m1, m2, m3;
    float avg;
} STD;

void read(STD *s, int n)
{
    printf("\nEnter the student details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of student %d:\n", (i + 1));
        printf("\nEnter name:");
        scanf("%s", (s + i)->name);
        printf("\nEnter roll no:");
        scanf("%d", &(s + i)->rn);
        printf("\nEnter marks 1:");
        scanf("%d", &(s + i)->m1);
        printf("\nEnter marks 2:");
        scanf("%d", &(s + i)->m2);
        printf("\nEnter marks 3:");
        scanf("%d", &(s + i)->m3);
    }
}

void avg(STD *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((s + i)->m1 >= (s + i)->m3 && (s + i)->m2 >= (s + i)->m3)
        {
            (s + i)->avg = ((s + i)->m1 + (s + i)->m2) / 2.0;
        }
        if ((s + i)->m2 >= (s + i)->m1 && (s + i)->m3 >= (s + i)->m1)
        {
            (s + i)->avg = ((s + i)->m2 + (s + i)->m3) / 2.0;
        }
        if ((s + i)->m3 >= (s + i)->m2 && (s + i)->m1 >= (s + i)->m2)
        {
            (s + i)->avg = ((s + i)->m3 + (s + i)->m1) / 2.0;
        }
    }
}

void sort(STD *s, int n)
{
    STD t;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            if ((s + j)->rn > (s + j + 1)->rn)
            {
                t = *(s + j);
                *(s + j) = *(s + j + 1);
                *(s + j + 1) = t;
            }
        }
    }
}

void disp(STD *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n %s \t %d \t %d \t %d \t %d \t %.2f \t ", (s + i)->name, (s + i)->rn, (s + i)->m1, (s + i)->m2, (s + i)->m3, (s + i)->avg);
    }
}

int main()
{
    int ch, n;
    STD *s;
    STD t;
    s = &t;

    while (1)
    {
        printf("\nEnter the choice\n1.Read\n2.Display\n3.Sort\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the no. of students");
            scanf("%d", &n);
            if ((s = (STD *)calloc(n, sizeof(STD))) == NULL)
            {
                printf("/nMemory error");
                exit(0);
            }
            read(s, n);
            avg(s, n);
            break;

        case 2:
            disp(s, n);
            break;
        case 3:
            sort(s, n);
            disp(s, n);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
