#include<stdio.h>

void displayPacks()
{
    printf("The four recharge packages are: \n");
    printf("1. Rs.100\n");
    printf("2. Rs.200\n");
    printf("3. Rs.500\n");
    printf("4. Rs.1000\n");
}

int getPackNum()
{
    int num;

    printf("Enter pack number: ");
    scanf("%d", &num);

    return num;
}

long long getNum()
{
    long long mobile;

    printf("Enter mobile number(11 digit): ");
    scanf("%lld", &mobile);

    return mobile;
}

int getAmount(int pack)
{
    int amount;

    switch(pack)
    {
        case 1: amount=100;
        break;

        case 2: amount=200;
        break;

        case 3: amount=500;
        break;

        case 4: amount=1000;
        break;

        default: amount=0;
    }
    return amount;
}

float taxAmount(int amount)
{
    float tax;

    tax= amount * (0.15);

    return tax;
}

float bonus(int amount)
{
    float bonus;

    if(amount>=500)
    {
        bonus = amount * 0.1;
    }
    else
    {
        bonus = 0;
    }
    return bonus;
}

void rechargeSlip(long long mobile, int amount, float tax, float total)
{
    printf("----------Recharge Slip----------\n");
    printf("Mobile Number: %lld", mobile);
    printf("\nAmount: %d", amount);
    printf("\nTax: %.2f", tax);
    printf("\nTotal Balance: %.2f",total);
}

int main()
{ 
    int totalSpent=0;
    int i;
    int pacNum;
    long long mobile;
    int amount;
    float tax, bonuss, totalBalance;

    for(i=0; i<3; i++)
    {
        displayPacks();
        pacNum=getPackNum();
        mobile=getNum();
        amount=getAmount(pacNum);
        tax=taxAmount(amount);
        bonuss=bonus(amount);
        totalBalance=amount+bonuss;
        rechargeSlip(mobile, amount, tax, totalBalance);
        totalSpent+=amount;
    }
    printf("Total spent: %d", totalSpent);

    return 0;
}