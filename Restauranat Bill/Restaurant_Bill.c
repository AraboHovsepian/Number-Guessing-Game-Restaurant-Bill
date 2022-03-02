/*
Meal cost would be displayed plus an option to add tax and tip (both as percentage)
then the program will display the meal cost, tax amount, tip amount, and total bill
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int r;
    double mealPrice[4] = {9.95, 4.55, 13.25, 22.35};
    char mealName[4][9];
    double tax, tip;
    time_t t;

    strcpy(mealName[0], "Salad");
    strcpy(mealName[1], "Soup");
    strcpy(mealName[2], "Sandwich");
    strcpy(mealName[3], "Pizza");
    
    srand((unsigned) time(&t));

    r = rand() % 4;

    printf("Enter tax amount (percentage): ");
    scanf("%lf", &tax);

    printf("Enter tip amount (percentage): ");
    scanf("%lf", &tip);

    printf("Meal Cost: %s $%0.2lf", mealName[r],mealPrice[r]);
    printf("\nTax Amount: %0.2lf%%", tax);
    printf("\nTip Amount: %0.2lf%%", tip);
    printf("\nTotal: $%0.2lf", mealPrice[r] + mealPrice[r] * tax / 100 + mealPrice[r] * tip / 100);

    return (0);
}