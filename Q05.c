
#include<stdio.h>

int main()
{
    double costPrice, sellPrice, quantity, totalCost, totalSell, profitLoss, profitPercentage;
    double *costPtr, *sellPtr, *quantityPtr, *totalCostPtr, *totalSellPtr, *profitLossPtr, *profitPercentagePtr, *largerPtr;

    costPtr = &costPrice;
    sellPtr = &sellPrice;
    quantityPtr = &quantity;
    totalCostPtr = &totalCost;
    totalSellPtr = &totalSell;
    profitLossPtr = &profitLoss;
    profitPercentagePtr = &profitPercentage;

    printf("Enter cost price: \n");
    scanf("%lf", costPtr);

    printf("\nEnter sell price: \n");
    scanf("%lf", sellPtr);

    printf("\nEnter quantity: \n");
    scanf("%lf", quantityPtr);

    *totalCostPtr = (*costPtr) * (*quantityPtr);
    *totalSellPtr = (*sellPtr) * (*quantityPtr);

    *profitLossPtr = *totalSellPtr - *totalCostPtr;

    if(*profitLossPtr > 0)
    {
        printf("Profit.\n");
    }

    else if(*profitLossPtr < 0)
    {
        printf("Loss.\n");
    }

    else
    {
        printf("No profit no loss.\n");
    }

    if(*totalCostPtr > 0)
    {
        *profitPercentagePtr = ((*profitLossPtr) / (*totalCostPtr)) * 100;
        printf("Profit Percentage: %.2lf%%\n", *profitPercentagePtr);
    }

    if(*costPtr > *sellPtr)
    {
         largerPtr = &costPrice;
         printf("Larger value is Cost Price.\n");
    }

    else
    {
        largerPtr = &sellPrice;
        printf("Larger value is Sell Price.\n");
    }

    printf("Value: %.2lf\n", *largerPtr);

    printf("\n----- ADDRESS TABLE -----\n");

    printf("Cost Price: %p\n", &costPrice);
    printf("Sell Price: %p\n", &sellPrice);
    printf("Quantity: %p\n", &quantity);
    printf("Total Cost: %p\n", &totalCost);
    printf("Total Sales: %p\n", &totalSell);
    printf("Profit/Loss: %p\n", &profitLoss);
    printf("Profit Percentage: %p\n", &profitPercentage);

    printf("\n----- POINTER ADDRESSES -----\n");

    printf("Cost Pointer: %p\n", &costPtr);
    printf("Sell Pointer: %p\n", &sellPtr);
    printf("Quantity Pointer: %p\n", &quantityPtr);
    printf("Total Cost Pointer: %p\n", &totalCostPtr);
    printf("Total Sales Pointer: %p\n", &totalSellPtr);
    printf("Profit/Loss Pointer: %p\n", &profitLossPtr);
    printf("Profit Percentage Pointer: %p\n", &profitPercentagePtr);
    printf("Larger Pointer: %p\n", &largerPtr);
    return 0;
}
