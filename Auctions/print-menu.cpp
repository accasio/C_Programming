#include "neil.h"


void print(int n, item *items)
{
	printf("\n%d\t%s\t%s\t%.2f\t%.2f\n", (items + n)->lotNum, (items + n)->name, (items + n)->description, (items + n)->price1, (items + n)->price2);
}

void printAll(int n, item *items)
{
	int i;
	if (n == 0)
	{
		printf("Nothing in Auction House\n\n");
		return;
	}
	printf("Lot Number\tTitle\tDescription\tLowEst\tHighEst\n");
	for (i = 0; i < n; i++)
	{
		print(i, items);
	}
	printf("\n");
}

void printAll_inv(int n, inv_item *inv_items)
{
	int i;
	if (n == 0)
	{
		printf("Nothing in inventory\n\n");
		return;
	}
	printf("Lot Number\tTitle\tDescription\tLowEst\tHighEst\n");

	for (i = 0; i < (n); i++)
	{
		print_inv(i, inv_items);
	}
}

void print_inv(int n, inv_item *inv_items)
{
	printf("\n%d\t%s\t%s\t%.2f\t%.2f\t%d\n", (inv_items + n)->lotNum, (inv_items + n)->name, (inv_items + n)->description, (inv_items + n)->price1, (inv_items + n)->price2), (inv_items + n)->price_paid;
}

int menu()
{
	int option;
	printf("-------------------------------------\n");
	printf("***Welcome To Our Auctineers***\n");
	printf("-------------------------------------\n\n");
	printf("What would you like to do?\n\n");
	printf("01 Search for through our stock.\n");
	printf("02 Enter the auction house.\n");
	printf("03 Add/Remove an item from our stock.\n");
	printf("04 View our entire stock.\n");
	printf("05 Sort stock.\n");
	printf("06 For inventory functions\n");
	printf("00 Quit.\n\n> ");
	fflush(stdin);
	scanf("%d", &option);
	printf("\n-------------------------------------\n");
	return option;
}