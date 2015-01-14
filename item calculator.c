#include "stdafx.h"
#include <stdio.h>
void main()
{
double total = 0.0;
double item_price = 0.0;
int item_quantity = 0;
int total_quantity = 0;
int more = 1;
int item_number = 0;
while (more == 1)
{
total = 0.0;
item_price = 0.0;
item_quantity = 0;
total_quantity = 0;
item_number = 0;
do
{
item_number++;
printf("\n");
printf("ITEM #%d price (0 to stop entering items):\t", item_number);
scanf ("%lf", &item_price);
if (item_price > 0.0)
{
printf ("ITEM #%d quantity:\t\t\t\t", item_number);
scanf("%d", &item_quantity);
total =total + item_price * item_quantity;
total_quantity = total_quantity + item_quantity;
}
} while (item_price > 0.0);
printf("--------------------------------------------------------------\n");
printf("Total = \t\t\t\t\t%.2lf\n", total);
printf("==============================================================\n");
printf("\n");
printf("\n");
printf("Enter 1 to do new calculation, 0 to exit: ");
scanf("%d", &more);
}
}