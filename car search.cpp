// week 12.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int year;
	char county[3];
	int number;
} registration;

typedef struct
{
	char make[40];
	char model[40];
	int year;
	double price;
	registration reg;
	int sold;  // 0 = for sale; 1 = sold
} car;

// this function is already written
int printMenu();

// complete the code in these functions
int addCar(car stock[], int num, car newCar);
void displayCarsForSale(car stock[], int num);
void displayAllCars(car stock[], int num);
void displayCar(car car1);
void sellCar(car stock[], int num, registration reg);



void main()
{
	car stock[200];
	int numCars = 0;
	int option;
	car newCar;
	registration reg1;

	printf("Welcome to the Universal Car Sales \n");
	printf("------------------------------------\n");

	option = printMenu();
	while (option != 0)
	{
		switch (option)
		{
		
		case 1:

			displayCarsForSale(stock, numCars);
			break;
		
		
		case 2:
			printf("Enter car make: \n");
			scanf("%s", newCar.make);
			printf("Enter model number: \n");
			scanf("%s", newCar.model);
			printf("Enter year of make: \n");
			scanf("%d", &newCar.year);
			printf("Enter Price: \n");
			scanf("%lf", &newCar.price);
			printf("Enter reg (e.g. '13 G 1423')\n");
			scanf("%d %s %d", &newCar.reg.year, newCar.reg.county, &newCar.reg.number);
			printf("Availibility (0 - yes; 1 - no)\n");
			scanf("%d", &newCar.sold);

			numCars = addCar(stock, numCars, newCar);
			
			break;
		

		case 3:
			// get the user to enter the reg that is sold
			// call sellCar(stock, numCars, reg1);
			// it sets  'sold' to 0 for this car
			printf("Enter reg (e.g. '13 G 1423')\n");
			scanf("%d %s %d", &reg1.year, reg1.county, &reg1.number);
			sellCar(stock, numCars, reg1);
			break;
	

		case 4:
			// call displayAllCars if there are any in stock
			displayAllCars(stock, numCars);
			break;
	
		
		default:
			puts("Illegal Option!\n");
		
		}
		
		option = printMenu();
	}


}

int printMenu()
{
	int option = 0;
	printf("\n1 - Display Stock for Sale\n");
	printf("2 - Add Car \n");
	printf("3 - Sell Car \n");
	printf("4 - Display All Stock \n");
	printf("0 - Exit\n");
	printf("------------------------------------\n");
	printf("Choose your option:\n");
	scanf("%d", &option);
	printf("------------------------------------\n");
	return option;

}

int addCar(car stock[], int num, car newCar)
{
	stock[num] = newCar;
	num = num +1;
	return(num);
}




void displayCar(car car1)
{
	printf("Make: %s\nModel: %s\nYear: %d\nPrice: %lf\n%d %s %d\n", car1.make, car1.model, car1.year, car1.price, car1.reg.year, car1.reg.county, car1.reg.number);
}

void displayCarsForSale(car stock[], int num)
{
	int i;
	
	for (i = num; i >= 0; i--)
	{
		if (stock[i].sold == 0)
		{
			displayCar(stock[i]);
		}
	}
	printf("------------------------------------\n");

}

void displayAllCars(car stock[], int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		displayCar(stock[i]);
	}
}

void sellCar(car stock[], int num, registration reg)
{
	int i;

	// set sold=1 for the car with this reg
	// print "Car Not Found\n" if it is not in stock

	for (i = num; i >= 0; i--)
	{
		if (reg.year == stock[i].reg.year && !strcmp(reg.county, stock[i].reg.county) && reg.number == stock[i].reg.number)
		{
			stock[i].sold = 1;
			return;
		}
		
	}
	printf("car not found\n");
}