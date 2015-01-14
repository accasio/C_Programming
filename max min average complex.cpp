#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"
#define SIZE 10

char custName[SIZE][30]; // array of customer names
float custBal[SIZE]; // array of customer balances

void initArrays(); // use any method you think useful to put sample data in the customer name and balance arrays
void printCustomer(int i); // prints the name and balance of customer[i]
int findHighest(); // finds the index of the customer with the highest balance
int findLowest(); // finds the index of the customer with the lowest balance
float findAverage(); // finds the average of all customer balances

void main()
{
	int i = 0;
	float avg;

	initArrays();

	i = findHighest();
	printCustomer(i);
	i = findLowest();
	printCustomer(i);
	avg = findAverage();
	printf("\nAverage Balance = %.2f \n\n", avg);
}

void initArrays()
{
	int i = 0;

	for (i = 0; i < SIZE; i++)
	{
		sprintf_s(custName[i], "Customer:%d", i);
		custBal[i] = rand() % 100;

	}

}

int findHighest()
{
	int i=0;
	int j;
	int max;

	max = custBal[0];

	for (j = 0; j < SIZE; j++)
	{
		if (custBal[j] > max)
		{
			i = j;
			max = custBal[j];
		}

	}

	return i;
}

void printCustomer(int i)
{
	printf("Customer%d's Balance is %.2f\n", i, custBal[i]);

}

int findLowest()
{
	int i=0;
	int j;
	int min;

	min = custBal[0];

	for (j = 0; j < SIZE; j++)
	{
		if (custBal[j] < min)
		{
			i = j;
			min = custBal[j];
		}
	}
	return i;
}

float findAverage()
{
	int i=0;
	float total = 0;
	float average;

	for (i = 0; i < SIZE; i++)
	{
		total = total + custBal[i];
	}

	average = (total) / (SIZE);

	return average;
}
