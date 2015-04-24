// week 23.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

void readFile(char *fileName);
void highAverage();
void highMonth();

typedef struct
{
	int year;
	double price[12];
	double average;
} electricity;

electricity records[30];

void main()
{
	char fileName[] = "c:\\users\\user\\documents\\electricity.txt";
	int choice = 1;

	readFile(fileName);
	while (choice != 0)
	{
		printf("0 - quit\n1 - find the month with the highest price\n2 - find the year with the highest average price\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			return;
		case 1:
			highMonth();
			break;
		case 2:
			highAverage();
			break;
		default:
			break;
		}
	}
}

void readFile(char *fileName)
{
	FILE *fptr;
	char *token;
	double total = 0.0;
	char temp[200];
	int i = 0, j = 0;
	char line[9999] = "";

	fptr = fopen(fileName, "r");
	if (fptr == NULL)
	{
		printf("file not found\n");
		return;
	}

	else
	{
		fgets(line, 9999, fptr);
		fgets(line, 9999, fptr);
		fgets(line, 9999, fptr);
		fgets(line, 9999, fptr);

		while ((strncmp(line, "0", 1)) != 0)
		{
			total = 0.0; //reset total
			fgets(line, 9999, fptr);
			token = strtok(line, ",");
			if (token != NULL)
			{
				strcpy(temp, token);
				records[i].year = atoi(temp);
			}
			for (j = 0; j < 12; j++)
			{
				token = strtok(NULL, ",");
				if (token != NULL)
				{
					strcpy(temp, token);
					records[i].price[j] = atof(temp);
					total = total + records[i].price[j];
				}
			}
			records[i].average = (total / 12);
			i++;
		}
	}
}

void highAverage()
{
	int i, k;
	double highest = 0.0;

	for (i = 0; i < 17; i++)
	{
		if (records[i].average > highest)
		{
			highest = records[i].average;
			k = i;
		}
	}

	printf("The highest annual average price was %lf in %d\n", records[k].average, records[k].year);
}

void highMonth()
{
	int i = 0;
	int j, k, l;
	double highest = 0.0;
	char months[12][81] = { "Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	while (i < 17)
	{
		for (j = 0; j < 12; j++)
		{
			if (records[i].price[j] > highest)
			{
				highest = records[i].price[j];
				k = i;
				l = j;
			}
		}
		i++;
	}
	printf("highest price price was %lf in %s of %d\n", records[k].price[l], months[l], records[k].year);
}