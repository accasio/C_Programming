#include "stdafx.h"
#include <stdio.h>
#include "string.h"

FILE *openFile(char *fileName, char *mode);
void closeFile(FILE *fptr);
void readData(FILE *fptr);
void addData(FILE *fptr);

void main(void)
{
	FILE *fptr;
	char fileName[] = "C:\\Users\\User\\Downloads\\Compressed\\week 13 examples\\cars_tabs.txt";

	fptr = openFile(fileName, "r");
	readData(fptr);
	closeFile(fptr);

	printf("\n\n");

	fptr = openFile(fileName, "a");
	addData(fptr);
	closeFile(fptr);

	fptr = openFile(fileName, "r");
	readData(fptr);
	closeFile(fptr);
}
void readData(FILE *fptr)
{
	char make[41], model[41];
	int year, mileage;
	float price;

	while (!feof(fptr))
	{
		fscanf(fptr, "%d\t%s\t%s\t%d\t%f\n", &year, make, model, &mileage, &price);
		printf("%d\t%s\t%s\t%d\t%.2f\n", year, make, model, mileage, price);
	}

}

void addData(FILE *fptr)
{

	char make[41], model[41];
	int year, mileage;
	float price;

	strcpy(make, "Audi");
	strcpy(model, "A8");
	year = 2012;
	mileage = 150;
	price = 120538.00;

	fprintf(fptr, "%d\t%s\t%s\t%d\t%.2f\n", year, make, model, mileage, price);

}

FILE * openFile(char *fileName, char *mode)
{

	FILE *fptr = fopen(fileName, mode);

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
	}

	return fptr;
}

void closeFile(FILE *fptr)
{
	fclose(fptr);
}
