#include "neil.h"


void inventory(int paid, item *items, int n, inv_item *inv_items, int num_inv)
{
	FILE *ptr;
	inv_item newItem = { 0, "", "", 0, 0, 0 };//setup blank new item 
	ptr = fopen("inv.txt", "a+");

	if (ptr == NULL)
	{
		printf("File doesn't exist, creating file\n");
		fopen("inv.txt", "a");
	}

	newItem.lotNum = items->lotNum;
	strcpy(newItem.name, items->name);
	strcpy(newItem.description, items->description);
	newItem.price1 = items->price1;
	newItem.price2 = items->price2;
	newItem.price_paid = paid;
	printf("%d\t%s\t%s\t%.2f\t%.2f\t%d\n", newItem.lotNum, newItem.name, newItem.description, newItem.price1, newItem.price2, newItem.price_paid);
	fprintf(ptr, "\n%d\t%s\t%s\t%.2f\t%.2f\t%d", newItem.lotNum, newItem.name, newItem.description, newItem.price1, newItem.price2, newItem.price_paid);
	
	num_inv = countLines("inv.txt");
	inv_items = (inv_item *)calloc(num_inv, sizeof(inv_item));
	
	if (!inv_readFile("inv.txt", inv_items))
	{
		printf("File could not be opened !!\n");//leave function if inv txt empty
		return;
	}
	fclose(ptr);
}

void auto_remove(char *fileName, int n, item *items, int lot_num)
{
	FILE *fptr = fopen(fileName, "w");
	int loop = 1, i = 0, removing;
	item holding = { 0, "", "", 0, 0 };
	removing = lot_num;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
	}

	for (i = 0; i < n; i++)
	{
		if (removing == ((items + i)->lotNum))
		{

			holding = *(items + (n - 1));//holding will hold the item to be removed
			*(items + (n - 1)) = *(items + i);//put bought one to be removed at the end
			*(items + i) = holding;//original last one put in place where removed one is
			n--;
			items = (item *)realloc(items, n * sizeof(item));//assign less memory
			break;
		}
	}

	fprintf(fptr, "LotNum	Title	Description	LowEst	HighEst\n");
	mergeSort(n, items, 0, 1);//sort array by lot number
	for (i = 0; i < n; i++)
	{
		fprintf(fptr, "\n%d\t%s\t%s\t%.2f\t%.2f", (items + i)->lotNum, (items + i)->name, (items + i)->description, (items + i)->price1, (items + i)->price2);
	}
	fclose(fptr);
}

void inv_remove(char *fileName, int n, inv_item *inv_items, int lot_num)
{
	FILE *fptr = fopen(fileName, "w");//double check append mode 
	int loop = 1, i = 0, removing;
	inv_item holding = { 0, "", "", 0, 0, 0 };
	values temp = { 0, NULL };
	removing = lot_num;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
	}

	for (i = 0; i < n; i++)
	{
		if (removing == ((inv_items + i)->lotNum))
		{
			//same logic as previous removing
			holding = *(inv_items + (n - 1));
			*(inv_items + (n - 1)) = *(inv_items + i);
			*(inv_items + i) = holding;
			n--;
			inv_items = (inv_item *)realloc(inv_items, n * sizeof(inv_item));
			break;
		}
	}

	fprintf(fptr, "LotNum	Title	Description	LowEst	HighEst\n");
	for (i = 0; i < n; i++)
	{
		fprintf(fptr, "\n%d\t%s\t%s\t%.2f\t%.2f\t%d", (inv_items + i)->lotNum, (inv_items + i)->name, (inv_items + i)->description, (inv_items + i)->price1, (inv_items + i)->price2, (inv_items + i)->price_paid);
	}
	fclose(fptr);
}

int sale(inv_item *inv_items, int num_inv, int cash)
{
	int sel;
	int i, found = 0, profit=0;

	printf("Enter the Number of the item you want to sell: ");
	scanf("%d", &sel);

	for (i = 0; i < num_inv; i++)
	{
		if ((inv_items + i)->lotNum == sel)
		{
			found = 1;
			break;
		}
	}

	if (!found)
	{
		printf("Item not found\n\n");
		return cash;
	}

	cash = cash + (int)(inv_items + i)->price2;
	profit = (int)(inv_items + i)->price2 - (int)(inv_items + i)->price_paid;
	inv_remove("inv.txt", num_inv, inv_items, sel);
	num_inv = num_inv - 1;
	printf("\n\nYour current inventory now contains: \n");
	printAll_inv(num_inv, inv_items);

	printf("\n>> Thank you your item will be kept in holding.\n>> You ");
	if (profit > 0) printf("gained %d from this sale.", profit);
	else if (profit < 0)  printf("lost %d from this sale.", profit);
	else printf("broke even from this sale.");
	printf("\n>> Your balance is now %d\n", cash);
	printf("\n-------------------------------------\n");
	return cash;
}