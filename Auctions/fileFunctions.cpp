#include "neil.h"

int countLines(char *fileName)
{
	char line[9999];
	FILE *fptr = fopen(fileName, "r+");
	int nLines = 0;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return 0;
	}

	fgets(line, 9999, fptr);
	fgets(line, 9999, fptr);
	while (!feof(fptr))
	{
		fgets(line, 9999, fptr);
		nLines++;
	}
	fclose(fptr);
	return nLines;
}

int readFile(char *fileName, item *items)
{
	char line[9999];
	FILE *fptr = fopen(fileName, "r+");
	char *token = line;
	char temp[9999];
	int n = 0, i = 0, check, tempLot;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return 0;
	}
	// use fgets to skip first 2 lines
	fgets(line, 9999, fptr);
	fgets(line, 9999, fptr);
	while (!feof(fptr))
	{
		check = 0;
		fgets(line, 9999, fptr);
		token = strtok(line, "\t");
		if (token != NULL)
		{
			strcpy(temp, token);
			tempLot = atoi(temp);
			check = lotSearch(n, items, tempLot, 0); // last num sent 0 because do not want to print multiple lots of same number
			if (check) continue; // check will be 1 if already exists
			(items + n)->lotNum = tempLot; // if a lot num exists already with same value will keep first entry and skip any others that might exist
		}
		token = strtok(NULL, "\t");
		if (token != NULL) strcpy((items + n)->name, token);
		token = strtok(NULL, "\t");
		if (token != NULL) strcpy((items + n)->description, token);
		token = strtok(NULL, "\t");
		if (token != NULL)
		{
			strcpy(temp, token);
			(items + n)->price1 = (float)atof(temp);
		}
		token = strtok(NULL, "\t");
		if (token != NULL)
		{
			strcpy(temp, token);
			(items + n)->price2 = (float)atof(temp);
		}
		n++;
	}
	mergeSort(n, items, 0, 1); // sort items in lotNum (offset = 0) in ascending order (order = 1)
	fclose(fptr);
	return 1;
}

int inv_readFile(char *fileName, inv_item *inv_items)
{
	char line[9999];
	FILE *fptr = fopen(fileName, "r+");
	char *token = line;
	char temp[9999];
	int n = 0, i = 0, check, tempLot;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return 0;
	}
	// use fgets to skip first 2 lines
	fgets(line, 9999, fptr);
	fgets(line, 9999, fptr);
	while (!feof(fptr))
	{
		check = 0;
		fgets(line, 9999, fptr);
		token = strtok(line, "\t");
		if (token != NULL)
		{
			strcpy(temp, token);
			tempLot = atoi(temp);
			(inv_items + n)->lotNum = tempLot;
		}
		token = strtok(NULL, "\t");
		if (token != NULL) strcpy((inv_items + n)->name, token);
		token = strtok(NULL, "\t");
		if (token != NULL) strcpy((inv_items + n)->description, token);
		token = strtok(NULL, "\t");
		if (token != NULL)
		{
			strcpy(temp, token);
			(inv_items + n)->price1 = (float)atof(temp);
		}
		token = strtok(NULL, "\t");
		if (token != NULL)
		{
			strcpy(temp, token);
			(inv_items + n)->price2 = (float)atof(temp);
		}
		token = strtok(NULL, "\t");
		if (token != NULL)
		{
			strcpy(temp, token);
			(inv_items + n)->price_paid = (int)atoi(temp);
		}
		n++;
	}
	fclose(fptr);
	return 1;
}

values add(char *fileName, int n, item *items)
{
	FILE *fptr = fopen(fileName, "a+"); // append mode plus in order to add newest item to end of the original file, array will be sorted at the end 
	int loop = 1, tryAgain = 1, check = 0;
	item newItem = {0, "", "", 0,0};
	values temp = { 0, NULL };

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return temp;
	}
	while (loop == 1)
	{
		check = 0;
		printf("\nEnter lot number: ");
		fflush(stdin);
		if ((scanf("%d", &newItem.lotNum) == 1))
		{
			if (newItem.lotNum == 0) break;
			tryAgain = lotSearch(n, items, newItem.lotNum, 1);
			if (tryAgain)
			{
				printf("\nLot Number Already exists, please try again\n");
				printf("\n------------------------------------\n");
			}
			else
			{
				printf("Enter name: ");
				fflush(stdin);
				gets(newItem.name);
				printf("Enter description: ");
				fflush(stdin);
				gets(newItem.description);
				while (check==0) // loop until user enters in numbers that the low est is lower than the high est
				{
					printf("Enter low estimate: ");
					fflush(stdin);
					if ((scanf("%f", &(newItem.price1))) == 1)
					{
						printf("Enter high estimate: ");
						fflush(stdin);
						if ((scanf("%f", &(newItem.price2))) == 1)
						{
							if (newItem.price2 < newItem.price1) // number enter was lower or was the same
							{
								printf("High estimate must be larger than low estimate!\n");
								continue; // return back to loop of getting
							}
							else
							{
								check = 1; // low and high are numbers and low is less than high
								fprintf(fptr, "\n%d\t%s\t%s\t%.2f\t%.2f", newItem.lotNum, newItem.name, newItem.description, newItem.price1, newItem.price2);
								n++;
								items = (item *)realloc(items, n * sizeof(item));
								(items + (n - 1))->lotNum = newItem.lotNum;
								strcpy((items + (n - 1))->name, newItem.name);
								strcpy((items + (n - 1))->description, newItem.description);
								(items + (n - 1))->price1 = newItem.price1;
								(items + (n - 1))->price2 = newItem.price2;
								printf("\nContinue(1-Yes 0-No)? ");//insert error check 
								fflush(stdin);
								scanf("%d", &loop);
								
							}
						}
						else  // no number entered
						{
							printf("\nHigh estimate must be a number!\n");
							check = 0;
							continue; // go back to start of while loop which reads prices 
						}
					}

					else // no number entered
					{
						printf("\nLow estimate must be a number!\n");
						check = 0;
						continue;
					}
				}
			}
		}
		else
		{
			printf("\nInvalid Input!\n");
		}
	}
	temp.num_items = n;
	temp.return_item = items;
	fclose(fptr);
	mergeSort(n, items, 0, 1); // sort items in lotNum (offset = 0) in ascending order (order = 1)
	return temp;
}

values remove(char *fileName, int n, item *items)
{
	FILE *fptr = fopen(fileName, "w"); // write mode because file will be wiped and rewritten
	int loop = 1, i = 0, removing; 
	int flag = 0; // flag if item doesn't exist
	item holding = { 0, "", "", 0, 0};
	values temp = { n, items };

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return temp;
	}
	while (loop == 1)
	{
		flag = 0;
		printf("\nEnter lot number: ");
		fflush(stdin);
		if ((scanf("%d", &removing) == 1))
		{
			for (i = 0; i < n; i++)
			{
				if (removing == ((items + i)->lotNum))
				{
					printf("DELETED: ");
					print(i, items);
					holding = *(items + (n - 1));
					*(items + (n - 1)) = *(items + i);
					*(items + i) = holding;
					n--;
					items = (item *)realloc(items, n * sizeof(item)); // realloc one less than origianl
					flag = 1;
					break;
				}
			}
			if (!flag) printf("That lot number doesnt exist.\n");
			printf("\n\nWould you like to delete another (1-Yes 0-No)?");
			scanf("%d", &loop);
		}
	}

	mergeSort(n, items, 0, 1); // sort items in lotNum (offset = 0) in ascending order (order = 1)
	fprintf(fptr, "LotNum	Title	Description	LowEst	HighEst\n");
	for (i = 0; i < n; i++)
	{
		fprintf(fptr, "\n%d\t%s\t%s\t%.2f\t%.2f", (items + i)->lotNum, (items + i)->name, (items + i)->description, (items + i)->price1, (items + i)->price2);
	}
	temp.num_items = n;
	temp.return_item = items;
	fclose(fptr);
	return temp;
}