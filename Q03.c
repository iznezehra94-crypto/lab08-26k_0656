#include<stdio.h>

void displayInfo()
{
    printf("-----Route and Price-----\n");
    printf("1. Karachi to Hyderabad: Rs.800\n");
    printf("2. Karachi to Sukkur: Rs.2200\n");
    printf("3. Karachi to Multan: Rs.3500\n");
}

int routeNum()
{
    int num;

    printf("Enter route number(1-3): ");
    scanf("%d", &num);

    return num;
}

int numOfSeat()
{
    int seat; 

    printf("\nEnter number of seats(1-6): ");
    scanf("%d", &seat);

    return seat;
}

int fare(int routeNum)
{
    int fare;

    if(routeNum==1)
    {
        fare=800;
    }

    else if(routeNum==2)
    {
        fare=2200;
    }

    else
    {
        fare=3500;
    }

    return fare;
}

int totalFare(int fare, int seats)
{
    int total;

    total=fare*seats;

    return total;
}

float seatCharge(int total, char type)
{

    float extra; 

    if(type == 'E' || type == 'e')
    {
        extra=0;
        total+=extra;
    }

    else if(type == 'B' || type == 'b')
    {
        extra=total*0.30;
        total+=extra;
    }

    return total;
}

void printTicket(int routeNum,int numOfSeat, char type, float totalFare)
{
    printf("-----Ticket Details-----\n");
    if(routeNum==1)
    {
        printf("Karachi to Hyderabad\n");
    }

    else if(routeNum==2)
    {
        printf("Karachi to Sukkur\n");
    }

    else
    {
        printf("Karachi to Multan\n");
    }

    printf("Number of Seats: %d\n", numOfSeat);
    printf("Seat Type: %c\n", type);
    printf("Final Fare: %.2f\n", totalFare);
}

int main()
{

    int i, route, seats, Fare, total;
    char type;
    float charge, finalTotal=0;

    for(i=0; i<2; i++)
    {
     
        displayInfo();
        route=routeNum();
        seats=numOfSeat();
        Fare=fare(route);
        total=totalFare(Fare,seats);
  
        printf("Enter seat type (E for Economy / B for Business): ");
        scanf(" %c", &type);

        charge=seatCharge(total, type);
        printTicket(route, seats, type, charge);

        finalTotal+=charge;
    }

    printf("Final total=%.2f", finalTotal);

    return 0;
}