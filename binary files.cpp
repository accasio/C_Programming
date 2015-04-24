#include "stdafx.h"
#include <stdio.h>
#include "string.h"

struct date
{
	int day;
	int month;
	int year;
};

struct weather
{
	struct date date;
	float minTemp;
	float maxTemp;
	float rainfall;
	char description[81];
};

struct weather day;

int menu();
void enterReading(FILE *cfPtr);
void findOne(FILE *cfPtr);
void listAll();

void main()
{
	int choice = 1;
	FILE *cfPtr = NULL;

	while (choice != 0)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			enterReading(cfPtr);
			break;
		case 2:
			findOne(cfPtr);
			break;
		case 3:
			listAll();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

	fclose(cfPtr);
}

int menu()
{
	int choice;

	puts("1. Enter reading");
	puts("2. Find a day's weather");
	puts("3. List All");
	puts("0. Quit");
	fflush(stdin);
	printf("Option: ");
	scanf("%d", &choice);
	return choice;
}

void enterReading(FILE *cfPtr)
{
	cfPtr = fopen("C:\\Users\\User\\Documents\\weather.dat", "ab+");

	printf("Date (dd mm yy)? ");
	scanf("%d %d %d", &day.date.day, &day.date.month, &day.date.year);
	printf("Min Temp? ");
	scanf("%f", &day.minTemp);
	printf("Max Temp? ");
	scanf("%f", &day.maxTemp);
	printf("Rainfall? ");
	scanf("%f", &day.rainfall);
	printf("Description? ");
	scanf("%s", day.description);
	fwrite(&day, sizeof(day), 1, cfPtr);
	printf("\n");
	
}

void findOne(FILE *cfPtr)
{
	int day;
	int month;
	int year;

	FILE *readPtr;

	readPtr = fopen("C:\\Users\\User\\Documents\\weather.dat", "rb");
	struct weather temp = { { 0, 0, 0, }, 0.0, 0.0, 0.0, "" };

	printf("Enter date <dd mm yyyy>: ");
	scanf("%d %d %d", &day, &month, &year);

	while (!(feof(readPtr)))
	{
		fread(&temp, sizeof(temp), 1, readPtr);
		if ((temp.date.day == day) && (temp.date.month == month) && (temp.date.year == year))
		{
			printf("Weather for %d/%d/%d:\n------------------------\nMin Temp: %f\nMax Temp: %f\nRainfall: %f\nDescription: %s\n\n", temp.date.day, temp.date.month, temp.date.year, temp.minTemp, temp.maxTemp, temp.rainfall, temp.description);
			break;
		}

	}

}

void listAll()
{
	FILE *readPtr;
	readPtr = fopen("C:\\Users\\User\\Documents\\weather.dat", "rb");
	//rewind(readPtr);
	while (!(feof(readPtr)))
	{
		fread(&day, sizeof(struct weather), 1, readPtr);
		printf("Weather for %d/%d/%d:\n------------------------\nMin Temp: %f\nMax Temp: %f\nRainfall: %f\nDescription: %s\n\n", day.date.day, day.date.month, day.date.year, day.minTemp, day.maxTemp, day.rainfall, day.description);
	}
}
