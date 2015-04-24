// auction2.cpp : Defines the entry point for the console application.

#include "neil.h"

void main()
{
	item *items;
	inv_item *inv_items;
	values answer;
	int cash = 5000;
	int num_items, choice = 1, subChoice = 0,loop = 0;
	int num_inv;
	char fileName[] = "ant - Copy.txt";//file is stored in stored in same folder (found the txt file from the website: http://www.auctionsneapolitan.com/auctions/120208/upload.txt)

	num_items = countLines(fileName);
	num_inv = countLines("inv.txt");
	items = (item *)calloc(num_items, sizeof(item));
	inv_items = (inv_item *)calloc(num_inv, sizeof(inv_item));

	if (!readFile(fileName, items))
	{
		printf("File could not be opened !!\n");
		return;
	}
	if (!inv_readFile("inv.txt", inv_items))
	{
		printf("File could not be opened !!\n");
		return;
	}
	while (choice != 0)
	{
		choice = menu();
		loop = 0;
		switch (choice)
		{
		case 1:
			search(num_items, items);
			printf("\n");
			break;
		case 2:
			cash = auction(num_items, items, fileName, num_items, inv_items, num_inv, cash);
			num_inv = countLines("inv.txt");
			num_items = countLines(fileName);//update the number of inventory items
			break;
		case 3:
			while (loop != 1)
			{
				printf("\n01 ADD ITEM\n02 REMOVE ITEM\n03 QUIT\n\n> ");
				fflush(stdin);
				scanf("%d", &subChoice);
				printf("\n------------------------------------\n");

				if (subChoice == 1)
				{
					answer = add(fileName, num_items, items);
					num_items = answer.num_items;//update new values from return structures
					items = answer.return_item;
				}

				else if (subChoice == 2)
				{
					answer = remove(fileName, num_items, items);
					num_items = answer.num_items;
					items = answer.return_item;
				}

				else if (subChoice == 3)
				{ 
					loop = 1;
					break; 
				}

				else { printf("That's not an option, try again\n"); continue; }
			}
			break;

		case 4:
			printAll(num_items, items);
			break;

		case 5:
			sortMenu(num_items, items);
			break;

		case 6:
			while (loop != 1)
			{
				printf("\n01 View Inventory\n02 Sell item\n03 Quit\n");
				printf("\n-------------------------------------\n\n>");
				fflush(stdin);
				scanf("%d", &subChoice);
				printf("\n-------------------------------------\n");

				if (subChoice == 1)
				{
					num_inv = 0;
					num_inv = countLines("inv.txt");//update number 
					inv_items = (inv_item *)calloc(num_inv, sizeof(inv_item));/*alloc new number of memory for inv_items*/
					if (!inv_readFile("inv.txt", inv_items))
					{
						printf("File could not be opened !!\n");
						return;
					}
					printAll_inv(num_inv, inv_items);
				}
				else if (subChoice == 2)
				{
					num_inv = 0;
					num_inv = countLines("inv.txt");
					inv_items = (inv_item *)calloc(num_inv, sizeof(inv_item));
					if (!inv_readFile("inv.txt", inv_items))
					{
						printf("File could not be opened !!\n");
						return;
					}
					cash = sale(inv_items, num_inv, cash);
				}
				else if (subChoice == 3)
				{
					loop = 1;
					break;
				}
				else
				{
					printf("That's Not An Option!\n\n");
				}
			}
			break;
		case 0:
			break;
		
		default:
			printf("That's not an option, try again!\n");
			continue;
		}
	}
	free(items);/*free dynamically allocated memory*/
	free(inv_items);
}