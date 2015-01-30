// parseInt Test.cpp : Defines the entry point for the console application.
//note: this is a work in project 

#include "stdafx.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int findX(int i);
int findPower(int i);
void fixPowers(int base, int power);

char fn[81];
char differ[81];

void main()
{
	char *pch;
	char temp[81], operations[81];
	int base[81], power[81];
	int i = 0, j = 0, p1 = 0, p2 = 0, len = 0, compLen = 0;
	
	gets(fn);
	printf("Splitting string \"%s\" into tokens:\n\n", fn);
	compLen = strlen(fn);
	while (fn[i] != '\0')
	{
		i++; //needed so not reading in #'s backwards
	} //find end point of string
	pch = strtok(fn, " ");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ");
	}

	while (i >= 0)
	{
		if (fn[i] == '^')
		{
			base[p1] = findX(i);
			power[p1] = findPower(i);

			base[p1] = base[p1] * power[p1];
			power[p1]--;
			p1++;
		}

		else if (fn[i] == '+' || fn[i] == '-')
		{
			operations [p2] = fn[i];
			p2++;
		}

		i--;
	}

	p2--;
	printf("\nDifferentiated:\n-----------------------\n\n");
	for (p1--; p1 >= 0; p1--)
	{
		sprintf(temp, "%d", base[p1]);
		strcat(temp, "x^");
		strcat(differ, temp);
		sprintf(temp, "%d", power[p1]);
		strcat(differ, temp);
		strcat(differ, " ");
		len = strlen(differ);

		if (len < compLen)
		{
			differ[len] = operations[p2];
			strcat(differ, " ");
			p2--;
		}
		
	}
	printf("%s\n", differ);
}

int findX(int i)
{
	char temp[81];
	int j = 0;
	int base;

	while(fn[i] != '\0')
	{
		i--;  //needed so not reading in #'s backwards
	}

	for (i++; fn[i] != 'x'; i++)
	{
		temp[j] = fn[i];
		j++;
	}

	base = atoi(temp);

	return base;
}

int findPower(int i)
{
	int j = 0;
	char temp[81];
	int power;

	i++; //go forward one after the ^ 

	while (fn[i] != '\0')
	{
		temp[j] = fn[i];
		j++;
		i++;
	}

	power = atoi(temp);

	return power;

}

