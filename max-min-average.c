// week 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

void main()
{
	int num[30];
	int i=0;
	float total = 0.0;
	float average = 0.0;
	int size = 0;
	int max = 0;
	int min = 0;
	int sum = 0;

	printf("Enter numbers <999 to stop>\n");

	/*this is getting average*/

	for(i=0; i<30; i++)
	{
		
		printf("#%d \t", i+1);
		scanf("%d", &num[i]);
		
		if(i==0)
		{
			max = num[0];
			min = num[0];
		}
		
		if(num[i] == 999)
		{
			break;
		}

		if(num[i] > max)
			max = num[i];
		
		if(num[i] < min)
			min = num[i];

		total = total + num[i];

		
	}

printf("\n============================\n");	

printf("Total: %f \n", total);

average = (float) total/ (float) i;

printf("============================\n");

printf("Average: %f \n", average);

printf("============================\n");

printf("Max: %d \n", max);

printf("============================\n");

printf("Min: %d \n", min);

printf("============================\n\n");

printf("List of input backwards\n");

printf("----------------------------\n");

i = i -1;

while(i >= 0)
	{
		printf("%d\n", num[i]);
		i = i - 1;
	}

}

