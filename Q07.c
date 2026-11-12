#include<stdio.h>

int findMax(int *p, int n)
{
    int  max, i;

    max = p[0];

    for(i=1; i<n; i++)
    {
        if(max<p[i])
        {
            max=p[i];
        }
    }

    return max;
}


int findMin(int *p, int n)
{
    int  min, i;

    min = p[0];

    for(i=1; i<n; i++)
    {
        if(min>p[i])
        {
            min=p[i];
        }
    }

    return min;
}

double findAverage(int *p, int n)
{
    double avg;
    int sum=0, i;

    for(i=0; i<n; i++)
    {
        sum+=p[i];
    }
    avg=(double)sum/n;

    return avg;
}

int countAbove(int *p, int n, double avg)
{
    int i, count=0;

    for(i=0; i<n; i++)
    {
        if(p[i]>avg)
        {
            count++;
        }
    }
    return count;
}

void reverseArray(int *p, int n)
{
    int *start=&p[0], *end=&p[n-1];
    int  temp;

    while(start<end)
    {
        temp=*start;
        *start=*end;
        *end=temp;

        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key)
{
    int i;

    for(i=0; i<n; i++)
    {
        if(p[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{

    int marks[10];
    int i, pass=0, max, min, key, count, search;
    double avg;

    printf("Enter marks of 10 students: \n");

    for(i=0; i<10; i++)
    {
        scanf("%d", &marks[i]);

        while(marks[i]<0 || marks[i]>100)
        {
            printf("Invalid marks. Try again: \n");
            scanf("%d", &marks[i]);
        }
    }

    printf("-----Original Marks-----\n");

    for(i=0; i<10; i++)
    {
        printf("%d ",marks[i]);
    }
    printf("\n");

    reverseArray(marks, 10);

    printf("-----Reversed Marks-----\n");

    for(i=0; i<10; i++)
    {
        printf("%d ",marks[i]);
    }
    printf("\n");

    for(i=0; i<10; i++)
    {
        if(marks[i] >= 40)
        {
            pass++;
        }
    }

    printf("\nPass count: %d\n", pass);

    max=findMax(marks, 10);
    min=findMin(marks, 10);
    avg=findAverage(marks, 10);
    count=countAbove(marks, 10, avg);

    printf("Enter key: ");
    scanf("%d", &key);

    search=searchMark(marks, 10, key);

    printf("Highest marks: %d\n", max);
    printf("Lowest marks: %d\n", min);
    printf("Average: %.2lf\n", avg);
    printf("Students above average: %d\n", count);

    if(search == -1)
    {
        printf("Mark was not found.\n");
    }
    else
    {
        printf("Search result: %d\n", search);
    }
    return 0;
}