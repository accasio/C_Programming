#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "string.h"
#include <ctype.h>

void main()
{
	int ctr = 0;	/* loop counter */
	int search = 0;   /* customer ID to look for */
	int found = 0;  /* will set to 1(true) of customer found */
	char choice;
	int stuID[10] = { 101, 102, 103, 104, 105, 106 };
	int stuScore[10] = { 45, 67, 23, 91, 54, 31 };
	char searchName[20];
	char name[10][20] = { "Smith", "Jones", "Murphy", "Martin", "Reilly", "Quinn" };

	printf("*****Enter Choice*****\nI/i - Search by ID \nS/s - Search by Surname\nQ/q - Quit\n\n");
	choice = getch();
	//putch(choice);

	while (toupper(choice) != 'Q') 
	{
		if (toupper(choice) == 'I') //allows capitals and lowercase
		{
			//the search is on
			printf("Enter ID\t");
			scanf_s("%d", &search);

			for (ctr = 0; ctr < 10; ctr++)
			{
				if (search == stuID[ctr])
				{
					found = 1;  /* found the student */
					break;      /* can stop looking now */
				}
			}

			if (found) printf("Score:\t\t%d\n", stuScore[ctr]);

			printf("========================================\n\n");
			printf("*****Enter Choice*****\nI/i - Search by ID \nS/s - Search by Surname\nQ/q - Quit\n\n");
			fflush(stdin);
			choice = getch();
			//putch(choice);
		}

		//surname option
		else if (toupper(choice) == 'S')
		{
			printf("Enter Surname:\t");
			fflush(stdin);
			gets(searchName);

			/* Now look for the Score */
			for (ctr = 0; ctr < 10; ctr++)
			{
				if (!strcmp(searchName, name[ctr])) //want to get found = 1
				{
					found = 1;  // found the student
					break;      //can stop looking now
				}
			}

			if (found) printf("Score:\t\t%d\n", stuScore[ctr]);

			fflush(stdin);
			printf("========================================\n\n");
			printf("*****Enter Choice*****\nI/i - Search by ID \nS/s - Search by Surname\nQ/q - Quit\n\n");
			choice = getch();
			//putch(choice);
		}

	}
}
