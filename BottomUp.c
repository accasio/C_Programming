// BottomUp.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "myHeader.h"

void main()
{
	float total_lights = 0;
	float total_comp = 0;
	float total_app = 0;
	float TOTAL = 0;
	float percent = 0.0;

	printf("**** Hello & Welcome to The Bottom-Up Approach Calculator ****\n------------------------------------------------------------\n");
	printf("1.Lighting");
	total_lights = calcLights();
	total_lights = total_lights / 1000;
	//printf("%f", total_lights);
	printf("\n2. TVs & Computers");
	total_comp = calcComp();
	total_comp = total_comp / 1000;
	//printf("%f\n", total_comp);
	printf("\n3. Appliances");
	total_app = calcApps();
	total_app = total_app / 1000;
	
	TOTAL = total_app + total_comp + total_lights;
	printf("Total accounted for: %.2f kWh\n", TOTAL);

	percent = TOTAL / top_down;
	percent = percent * 100;

	printf("Percentage accounted for: %.2f%%\n\n", percent);
	
}

float calcLights()
{
	int cont = 1;
	int i = 0;
	struct Lights room[90];
	float total = 0.0;
	float daily = 0.0;

	while (cont != 0)
	{
		printf("\nEnter name of the room: ");
		fflush(stdin);
		gets(room[i].name);
		//scanf("%s", room[i].name);
		printf("\nEnter wattage of the lights in this room: ");
		scanf_s("%f", &room[i].wattage);
		printf("\nEnter hours that the lights left on (daily): ");
		scanf_s("%f", &room[i].hours);
		daily = room[i].wattage * room[i].hours;
		total += (daily * 365);

		i++;

		printf("\nWould you like to continue? \n1 - Yes or 0 - No \n");
		scanf_s("%d", &cont);
		if (cont) printf("----------------------------------");
	}
	return total;
}

float calcComp()
{
	int cont = 1;
	int i = 0;
	struct  comp_tv comps[90];
	float total = 0.0;
	float daily = 0.0;

	while (cont != 0)
	{
		printf("\nEnter name of the device: ");
		fflush(stdin);
		gets(comps[i].name);
		//scanf("%s", comps[i].name);
		printf("\nEnter wattage of the device: ");
		scanf_s("%f", &comps[i].wattage);
		printf("\nEnter hours that the device is left on (daily): ");
		scanf_s("%f", &comps[i].hours);
		daily = comps[i].wattage * comps[i].hours;
		total += (daily * 365);

		i++;

		printf("\nWould you like to continue? \n1 - Yes or 0 - No \n");
		scanf_s("%d", &cont);
		if (cont) printf("----------------------------------");
	}
	return total;
}

float calcApps()
{
	int cont = 1;
	int i = 0;
	struct  Appliances apps[90];
	float total = 0.0;
	float daily = 0.0;

	while (cont != 0)
	{
		printf("\nEnter name of the appliance: ");
		fflush(stdin);
		gets(apps[i].name);
		//scanf("%s", apps[i].name);
		printf("\nEnter wattage the appliance: ");
		scanf_s("%f", &apps[i].wattage);
		printf("\nEnter hours that the appliance is left on (daily): ");
		scanf_s("%f", &apps[i].hours);
		daily = apps[i].wattage * apps[i].hours;
		total += (daily * 365);

		i++;

		printf("\nWould you like to continue? \n1 - Yes or 0 - No \n");
		scanf_s("%d", &cont);
		if (cont) printf("----------------------------------");
	}
	return total;
}