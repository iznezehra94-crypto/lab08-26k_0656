
#include<stdio.h>

void readMarks(int *m1, int *m2, int *m3)
{
    printf("Enter marks of subject 1: ");
    scanf("%d", m1);

    printf("Enter marks of subject 2: ");
    scanf("%d", m2);

    printf("Enter marks of subject 3: ");
    scanf("%d", m3);

    while(*m1<0 || *m1>100 || *m2<0 || *m2>100 || *m3<0 || *m3>100)
    {
        if(*m1<0 || *m1>100)
        {
            printf("Invalid marks for subject 1. Try again: ");
            scanf("%d", m1);
        }

        if(*m2<0 || *m2>100)
        {
            printf("Invalid marks for subject 2. Try again: ");
            scanf("%d", m2);
        }

        if(*m3<0 || *m3>100)
        {
            printf("Invalid marks for subject 3. Try again: ");
            scanf("%d", m3);
        }
    }
}


void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest)
{
    *highest=m1;
    *lowest=m1;

    *total=m1+m2+m3;
    *average=(double)*total/3;

    if(*highest<m2)
    {
        *highest=m2;
    }

    if(*highest<m3)
    {
        *highest=m3;
    }

    if(*lowest>m2)
    {
        *lowest=m2;
    }

    if(*lowest>m3)
    {
        *lowest=m3;
    }
}


void swapMarks(int *a, int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}


void addGraceMarks(int *mark, int grace)
{
    if(*mark>=35 && *mark<=39)
    {
        *mark+=grace;
    }
}


void findGrade(double avg, char *grade, char *remarks)
{
    int i;

    if(avg>=80)
    {
        *grade='A';

        char temp[]="Excellent";

        for(i=0; temp[i]!='\0'; i++)
        {
            remarks[i]=temp[i];
        }

        remarks[i]='\0';
    }
    else if(avg>=60)
    {
        *grade='B';

        char temp[]="Good";

        for(i=0; temp[i]!='\0'; i++)
        {
            remarks[i]=temp[i];
        }

        remarks[i]='\0';
    }
    else
    {
        *grade='C';

        char temp[]="Needs Improvement";

        for(i=0; temp[i]!='\0'; i++)
        {
            remarks[i]=temp[i];
        }

        remarks[i]='\0';
    }
}


void incrementByValue(int x)
{
    x++;
}


void incrementByReference(int *x)
{
    (*x)++;
}


int main()
{
    int m1, m2, m3;
    int total, highest, lowest;
    int grace, choice;
    int student;
    double average;
    char grade;
    char remarks[30];

    printf("========== STUDENT RESULT SYSTEM ==========\n");

    printf("\nSTUDENT\tM1\tM2\tM3\tTOTAL\tAVERAGE\tHIGHEST\tLOWEST\tGRADE\tREMARK\n");

    for(student=1; student<=5; student++)
    {
        printf("\n========== Student %d ==========\n", student);

        readMarks(&m1, &m2, &m3);

        if(m1>=35 && m1<=39)
        {
            printf("Subject 1 is eligible for grace marks. Award grace? (1=Yes, 0=No): ");
            scanf("%d", &choice);

            if(choice==1)
            {
                grace=40-m1;
                addGraceMarks(&m1, grace);
            }
        }

        if(m2>=35 && m2<=39)
        {
            printf("Subject 2 is eligible for grace marks. Award grace? (1=Yes, 0=No): ");
            scanf("%d", &choice);

            if(choice==1)
            {
                grace=40-m2;
                addGraceMarks(&m2, grace);
            }
        }

        if(m3>=35 && m3<=39)
        {
            printf("Subject 3 is eligible for grace marks. Award grace? (1=Yes, 0=No): ");
            scanf("%d", &choice);

            if(choice==1)
            {
                grace=40-m3;
                addGraceMarks(&m3, grace);
            }
        }

        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);

        if(m1<m2)
        {
            swapMarks(&m1, &m2);
        }

        if(m1<m3)
        {
            swapMarks(&m1, &m3);
        }

        if(m2<m3)
        {
            swapMarks(&m2, &m3);
        }

        findGrade(average, &grade, remarks);

        printf("%d\t%d\t%d\t%d\t%d\t%.2f\t%d\t%d\t%c\t%s\n",
               student, m1, m2, m3, total, average, highest, lowest, grade, remarks);
    }

    printf("\n========== PASS BY VALUE AND REFERENCE ==========\n");

    int num=10;

    printf("Original value: %d\n", num);

    incrementByValue(num);

    printf("After incrementByValue: %d\n", num);

    incrementByReference(&num);

    printf("After incrementByReference: %d\n", num);

    // Pass by value changes only a copy of the variable.
    // Pass by reference changes the original variable using its address.

    return 0;
}
