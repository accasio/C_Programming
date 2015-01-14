// Project 2.cpp : Defines the entry point for the console application.
//

#include "stdio.h"


void main()
{
	int hours = 0;
	float rate = 25;
	float pay = 0.0;

	printf ("Enter hourse worked: ");
	scanf_s("%d", &hours);
	pay = hours*rate;

	printf ("Pay = %.2f \n", pay);
}

