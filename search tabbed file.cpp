// week 16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <stdlib.h>

int getChoice();
void region(int counter);
void rep(int counter);
void item(int counter);
void year(int counter);

struct Data{
	char date[20];
	char region[20];
	char rep[20];
	char item[20];
	int units;
	float cost;
	float total;
};

struct Data entry[200];

void main()
{
	int option = 0, i = 0, num = 0;
	char line[200];
	char temp[20]; //temp before converting strings to nums
	FILE *fptr;
	char fileName[] = "C:\\Users\\User\\Documents\\SampleData.txt";
	char *token;

	fptr = fopen(fileName, "r");

	if (fptr == NULL)
	{
		printf("File could not be opened !!\n");
		return;
	}
	else
	{
		fgets(line, 200, fptr); //skip first line

		while (!feof(fptr))
		{
			fgets(line, 200, fptr);

			if ((token = strtok(line, "\t")) != NULL){
				//strcpy(whatever, token)
				strcpy(entry[i].date, token);
			}
			if ((token = strtok(NULL, "\t")) != NULL){
				strcpy(entry[i].region, token);
			}
			if ((token = strtok(NULL, "\t")) != NULL){
				strcpy(entry[i].rep, token);
			}
			if ((token = strtok(NULL, "\t")) != NULL){
				strcpy(entry[i].item, token);
			}
			if ((token = strtok(NULL, "\t")) != NULL){
				strcpy(temp, token);
				entry[i].units = atoi(temp);
			}
			if ((token = strtok(NULL, "\t")) != NULL){
				strcpy(temp, token);
				entry[i].cost = atof(temp);
			}
			if ((token = strtok(NULL, "\t")) != NULL){
				strcpy(temp, token);
				entry[i].total = atof(temp);
			}
			
			i++;
		}
		fclose(fptr);
	}
	option = getChoice();

	while (option != 0)
	{
		if (option == 1) region(i);
		if (option == 2) rep(i);
		if (option == 3) item(i);
		if (option == 4) year(i);

		option = getChoice();
	}
}

int getChoice()
{
	int choice;

	printf("Get Total By? \n");
	printf("Options: 1=Region 2=Rep 3=Item 4=Year 0=Quit\n");
	fflush(stdin);
	scanf("%d", &choice);
	return choice;
}

void region(int counter)
{
	int i;
	float total=0.0;
	char region[20];
	printf("Enter Your Region: ");
	fflush(stdin);
	gets(region);

	for (i = 0; i < counter; i++)
	{
		if (!(strcmp(entry[i].region, region)))
		{
			total += entry[i].total;
		}
	}

	printf("Total in the region %s is %.2f\n\n", region, total);
}

void rep(int counter)
{
	int i = 0;
	float total = 0.0;
	char rep[20];
	printf("Enter Your Rep: ");
	fflush(stdin);
	gets(rep);

	for (i = 0; i < counter; i++)
	{
		if (!(strcmp(entry[i].rep, rep)))
		{
			total += entry[i].total;
		}
	}

	printf("Total for the rep %s is %.2f\n\n", rep, total);
}

void item(int counter)
{
	int i = 0;
	float total = 0.0;
	char item[20];
	printf("Enter Your Item: ");
	fflush(stdin);
	gets(item);

	for (i = 0; i < counter; i++)
	{
		if (!(strcmp(entry[i].item, item)))
		{
			total += entry[i].total;
		}
	}

	printf("Total for the rep %s is %.2f\n\n", item, total);
}

void year(int counter)
{
	int i = 0, j=0, k=0;
	float total = 0.0;
	char year[20], temp[20];
	printf("Enter Your Year: ");
	fflush(stdin);
	gets(year);

	for (i = 0; i < counter; i++)
	{
		while (entry[i].date[j] != '\0')
		{
			if (entry[i].date[j] == '/')
			{
				k++;

				if (k == 2)
				{
					temp[0] = entry[i].date[j + 1];
					temp[1] = entry[i].date[j + 2];
					temp[2] = '\0';

					break;
				}
			}
			j++;
		}

		if (!(strcmp(temp, year)))
		{
			total += entry[i].total;
		}

		k = 0;
		j = 0;
	
	}
	printf("Total for the year %s is %.2f\n\n", year, total);
}