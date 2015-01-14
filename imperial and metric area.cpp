// week 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

float squareMetres(float width, float length);
float feetAndInchesToMetres(float squareFeet);
float squareFeetFunction(float feet1, float feet2);

void main()
{
	int choice =0;
	float squareMetre;
	float squareFeet;
	float length = 0.0;
	float width = 0.0;
	char c1, c2, c3, c4, c5;
	char line[81];
	float feet1, feet2, inch1, inch2;

	printf("Welcome to the Universal Converter\n");
	printf("----------------------------------\n");
	printf("1 - Metric Area Calculator\n2 - Imperial Area Calculator\n");
	printf("Enter choice: ");
	scanf_s("%d", &choice);
	
		if (choice == 1)
		{
			puts("Enter dimensions.");
			puts("Example: 3.4x6.7 \n");
			fflush(stdin);
			gets_s(line);
			sscanf_s(line, "%f%c%f", &width, &c1, 1, &length);
			squareMetre = squareMetres(width, length);
			printf("Area In Square Metres: %.2f\n", squareMetre);
		}

		if (choice == 2)
		{
			puts("Enter dimensions.\n");
			puts("Example:5'4\"x8'3\" \n");
			fflush(stdin);
			gets_s(line);
			sscanf_s(line, "%f%c%f%c%c%f%c%f%c \n", &feet1, &c1, 1, &inch1, &c2, 1, &c3, 1, &feet2, &c4, 1, &inch2, &c5, 1);
			inch1 = (float) inch1 * (0.0833333333333); //1/12 - convert inches to feet first
			inch2 = (float) inch2 * (0.0833333333333);
			feet1 = feet1 + inch1;//add the inches now in feet to the original feet
			feet2 = feet2 + inch2;
			squareFeet = squareFeetFunction(feet1, feet2);
			printf("Area In Square Feet = %f\n", squareFeet);
			squareMetre = feetAndInchesToMetres(squareFeet);
			printf("Area In Square Metres = %f\n", squareMetre);
		}
}

float squareMetres(float width, float length)
{
	float  squareMetre;
	squareMetre = width*length;
	
	return squareMetre;

}

float squareFeetFunction(float feet1, float feet2)
{
	float area;

	area = feet1 * feet2; //area in sq feet

	return area;

}

float feetAndInchesToMetres(float squareFeet)
{
	float aream;
	aream = squareFeet * 0.3048 * 0.3048;//convert area in feet to sq metres - two 0.3048's cause of the square
	return aream;
}