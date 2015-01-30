// week13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

FILE *fptr;

int openFile();
void closeFile();

void main()
{
	char vehicle[81];
	int reg[81];
	char type = 'a';
	char fileLine[200];
	char temp[81];
	char month[12][81] = {"Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	int i, j;

	int openOK = 0; //check file there
	 openOK = openFile();
	 /*if (openOK) 
	 { 
		 while (!feof(fptr)) 
		 { 
			 fgets(fileLine, 81, fptr); 
			 puts(fileLine); 
		 } 
	 }*/
	

	 if (openOK)
	 {
		fgets(fileLine, 200, fptr);
		fgets(fileLine, 200, fptr);

		while (strcmp(vehicle, "END"))
		 {
			fscanf(fptr, "%s\t%s", vehicle, reg);
			
			if (strcmp(vehicle, "END"))
			{

				for (i = 0; i < 12; i++)
				{
					fscanf(fptr, "\t%c", &type);

					switch (type)
					{
					case 'I': strcpy(temp, "Inspection");
						printf("%s registration %s, in %s has %s due.\n", vehicle, reg, month[i], temp);
						break;

					case 'S': strcpy(temp, "Inspection Service");
						printf("%s registration %s, in %s has %s due.\n", vehicle, reg, month[i], temp);
						break;

					case 'C': strcpy(temp, "Commercial Vehicle Test Due");
						printf("%s registration %s, in %s has %s due.\n", vehicle, reg, month[i], temp);
						break;

					case 'T': strcpy(temp, "2 Year Tacho Check");
						printf("%s registration %s, in %s has %s due.\n", vehicle, reg, month[i], temp);
						break;

					default: break;
					}//switch
				}//for 12
			}
		 }
	 }
	
	 closeFile();
}

int openFile() 
{ 
	fptr = fopen("C:\\Users\\User\\Documents\\MaintenanceSchedule.txt", "r");
	if (fptr == NULL) 
	{ 
		printf("Error opening file ! \n"); 
		return 0; } 
	
	else
	{ 
		return 1;
	}
}

void closeFile() 
{ 
	fclose(fptr); 
}
