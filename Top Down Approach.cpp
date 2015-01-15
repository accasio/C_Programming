// Top Down Approach.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdio.h"

#define costlitre 0.85;

double calcOil(float litresOil);

void main()
{
	float eBill = 0.0;
	float eKWh = 0.0;
	float fuel_Cost = 0.0;
	float oilBill = 0;
	double oilKWh = 0.0;
	float total = 0.0;


	printf("***Welcome to the kWHr Top Down Approach Calculator***\n");
	printf("------------------------------------------------------\n\n");
	
	printf("-Part 1-\nPlease enter your annual electricity bill in Euro: E ");
	scanf_s("%f", &eBill);
	eKWh = (eBill)/ (0.17);
	printf("Annual usage for your electricity in your home is: %.2fkWh\n", eKWh);

	printf("\n-Part 2-\nPlease enter how much you pay on oil a year: E ");
	scanf_s("%f", &oilBill);
	oilKWh = calcOil(oilBill);
	printf("Annual usage for oil in your home is: %.2lfkWh\n", oilKWh);
	
	total = oilKWh + eKWh;
	printf("\nYour total energy usage is: %fkWh\n", total);
	total = (23000 - total) / 23000;
	total = total * 100;
	
	
	if (total > 0)
	{
		printf("You are %.2f%% below average.\n", total);
	}

	else if (total < 0)
	{
		total = -total;
		printf("You are %.2f%% above average.\n");
	}

	else
	{
		printf("You are exactly average.\n");
	}

}

double calcOil (float bill)
{
	double oilLitre;
	double oilKJ;
	double kWh;

	oilLitre = bill / costlitre;
	oilKJ = oilLitre * 35000;
	kWh = oilKJ / 3600;
	return kWh;
}

//annual fuel bill is 1045 and elect is 1739
//21723 is annual energy usage