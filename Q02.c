
#include<stdio.h>

void displayInfo()
{
    printf("Naeem Hospital\n");
    printf("General Ward: Rs.1500/day\n");
    printf("Semi-Private: Rs.3500/day\n");
    printf("Private: Rs.6000/day\n");
}

int roomType()
{
    int type;

    printf("Enter room type (1, 2 or 3): ");
    scanf("%d", &type);

    while(type<1 || type>3)
    {
        printf("Invalid room type. Enter again (1, 2 or 3): ");
        scanf("%d", &type);
    }

    return type;
}

int daysStayed()
{
    int stayed;

    printf("Enter number of days stayed (1-30): ");
    scanf("%d", &stayed);

    while(stayed<1 || stayed>30)
    {
        printf("Invalid days. Enter again (1-30): ");
        scanf("%d", &stayed);
    }

    return stayed;
}

int roomCharges(int type, int days)
{
    int charge;

    if(type==1)
    {
        charge=1500*days;
    }

    else if(type==2)
    {
        charge=3500*days;
    }

    else
    {
        charge=6000*days;
    }

    return charge;
}

float medicineCharge(float bill)
{
    float charge;

    charge=bill*0.05;
    bill+=charge;

    return bill;
}

float discount(int days, float bill)
{
    float discount;

    if(days>=7)
    {
        discount=bill*0.08;
        bill-=discount;
    }

    return bill;
}

void finalBill(int type, int days, int room, float medicine, float total)
{
    printf("\n------ FINAL HOSPITAL BILL ------\n");

    if(type==1)
    {
        printf("Room: General Ward\n");
    }

    else if(type==2)
    {
        printf("Room: Semi-Private\n");
    }

    else
    {
        printf("Room: Private\n");
    }

    printf("Days stayed: %d\n", days);
    printf("Room charges: Rs.%d\n", room);
    printf("Medicine charges: Rs.%.2f\n", medicine);
    printf("Final amount: Rs.%.2f\n", total);
}

int main()
{
    int type, stayed, charges;
    float bill, medCharge, total;
    char senior;

    displayInfo();

    type=roomType();

    stayed=daysStayed();

    charges=roomCharges(type, stayed);

    printf("Enter medicine bill: ");
    scanf("%f", &bill);

    medCharge=medicineCharge(bill);

    total=charges+medCharge;

    total=discount(stayed, total);

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);

    if(senior=='y' || senior=='Y')
    {
        total-=1000;

        if(total<0)
        {
            total=0;
        }
    }

    finalBill(type, stayed, charges, medCharge, total);

    return 0;
}
