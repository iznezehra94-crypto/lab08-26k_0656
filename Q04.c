#include<stdio.h>

void displayInfo()
{
    printf("-----Fare Rules-----\n");
    printf("Base Fare: Rs.150\n");
    printf("Rs.60/km after first 10km\n");
    printf("Rs.45/km after that\n");
}

float distance()
{
    float distance;

    printf("Enter distance in km(more than 0, upto 200): ");
    scanf("%f", &distance);

    while(distance<=0 || distance>200)
    {
        printf("\nInvalid distance.Try again!");
        scanf("%f", &distance);
    }

    return distance;
}

int waitingTime()
{
    int minute;

    printf("\nEnter waiting time in minutes(0-120): ");
    scanf("%d", &minute);

    while(minute<0 || minute>120)
    {
        printf("\nInvalid time. Try again!");
        scanf("%d", &minute);
    }

    return minute;
}
float distanceCharge(float distance)
{
    float charge;

    if(distance<=10)
    {
        charge=150+(distance*60);
    }
    else
    {
        charge=150+(10*60)+((distance-10)*45);
    }

    return charge;
}

int WaitingCharge(int time)
{
    int charge;

    if(time<=5)
    {
        charge=0;
    }
    else
    {
        charge=(time-5)*10;
    }

    return charge;
}

float nightCharge(int time, float fare)
{
    float nightCharge;

    if(time>=22 || time<6)
    {
        nightCharge=0.25*fare;
        fare+=nightCharge;
    }

    return fare;
}

void tripReceipt(float distance, int time, float fare)
{
    printf("\n-----Trip Receipt-----\n");
    printf("Distance=%.2f\n", distance);
    printf("Waiting Time: %d\n", time);
    printf("Final Fare: %.2f\n", fare);
}

int main()
{

    int i, time, waitCharge, hour;
    float totalEarning=0, highestFare=0, Distance, disCharge, fare;

   for(i=0; i<3; i++)
{
    printf("\n-----Trip %d-----\n", i+1);

    displayInfo();

    Distance=distance();

    time=waitingTime();

    disCharge=distanceCharge(Distance);

    waitCharge=WaitingCharge(time);

    fare=disCharge+waitCharge;

    printf("\nEnter trip hour (0-23): ");
    scanf("%d", &hour);

    while(hour<0 || hour>23)
    {
       printf("\nInvalid hour. Try again!");
       scanf("%d", &hour);
    }

    fare=nightCharge(hour,fare);

    totalEarning+=fare;

    if(fare>highestFare)
    {
        highestFare=fare;
    }

    tripReceipt(Distance,time,fare);
}

printf("\nTotal Earnings: Rs.%.2f", totalEarning);
printf("\nHighest Fare: Rs.%.2f\n", highestFare);

    return 0;
}