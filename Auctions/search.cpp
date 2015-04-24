#include "neil.h"

void search(int num_items, item *items)
{
	int choice, searchNum, check;
	float low = 0, high = 0;
	choice = getOption();
	switch (choice)
	{
	case 1:
		printf("\nEnter lot number: ");
		scanf("%d", &searchNum);
		check = lotSearch(num_items, items, searchNum, 1);
		if(!check) printf("\nNo item found.");
		break;
	case 2:
		nameSearch(num_items, items);
		break;
	case 3:
		descSearch(num_items, items);
		break;
	case 4:
		printf("\nEnter price range (e.g 25 - 100): ");
		scanf("%f - %f", &low, &high);
		searchPrice(num_items, items, low, high);
		break;
	case 0:
		break;
	default:
		printf("You didn't enter one of the options on the list.\n");
		break;
	}
	printf("\n");
}

int getOption()
{
	int choice = 0;

	printf("What would you like to search by?\n\n");
	printf("01 - Lot Number\n");
	printf("02 - Name\n");
	printf("03 - Description\n");
	printf("04 - Price Range\n");
	printf("00 - Quit\n\n");
	printf("> ");
	fflush(stdin);
	scanf("%d", &choice);
	printf("\n------------------------------------\n");

	return choice;
}

int lotSearch(int num_items, item *items, int searchNum, int toPrint)
{
	int i;
	if (num_items == 0) return 0;
	for (i = 0; i < num_items; i++)
	{
		if (searchNum == (items + i)->lotNum)
		{
			if(toPrint) print(i, items); //variable decides if lotSearch prints already existing lot
			return 1;
		}
	}
	return 0;
}

void nameSearch(int n, item *items)
{
	int i, found = 0;
	char temp[1000], search[1000];
	printf("\nEnter the name or part of the name you wish to search for: ");
	fflush(stdin);
	gets(search);
	_strlwr(search);
	for (i = 0; i < n; i++)
	{
		strcpy(temp, (items + i)->name);
		_strlwr(temp);
		if (strstr(temp, search) != NULL)
		{
			print(i, items);
			found = 1;
		}
	}
	if (!found) printf("No item found.\n");
}

void descSearch(int n, item *items)
{
	int i, found=0;
	char temp[1000], search[1000];
	printf("\nEnter a part of the description you wish to search for: ");
	fflush(stdin);
	gets(search);
	_strlwr(search);
	for (i = 0; i < n; i++)
	{
		strcpy(temp, (items + i)->name);
		_strlwr(temp);
		if (strstr(temp, search) != NULL)
		{
			print(i, items);
			found = 1;
		}
	}
	if (!found) printf("No item found.\n");
}

void searchPrice(int n, item *items, float low, float high)
{
	int i, found = 0;
	for (i = 0; i < n; i++)
	{
		if (((items + i)->price1) >= low)
		{
			if (((items + i)->price2) <= high)
			{
				print(i, items);
				found = 1;
			}
		}
	}
	if (!found) printf("No item found.\n");
}