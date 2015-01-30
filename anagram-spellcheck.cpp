#include "stdafx.h"
#include <stdio.h>
#include "string.h"


int countCharOccurence(char *string, char c);
int getOption();
int checkSpelling();
int findWord();

long int nwords = 0;
char dictionary[80000][20];

void main(void)
{
	FILE *fptr;
	char fileName[] = "C:\\Users\\User\\Documents\\webster.txt";
	int option = 0;

	fptr = fopen(fileName, "r");

	if (fptr == NULL)
	{
		printf("File could not be opened !!\n");
		return;
	}
	else
	{
		while (!feof(fptr))
		{

			fscanf(fptr, "%s\n", dictionary[nwords]);
			nwords++;
		}
		fclose(fptr);
	}

	printf("%ld words read from file \n\n", nwords);

	option = getOption();
	while (option != 0)
	{
		if (option == 1) checkSpelling();
		if (option == 2) findWord();
		if (option == 0) return;
		option = getOption();
	}
}

int getOption()
{
	int option = 0;

	puts("Options: 1=check spelling, 2=find words, 0=quit\n");
	fflush(stdin);
	scanf("%d", &option);
	return option;
}

int checkSpelling()
{
	int i = 0;
	char temp[20];

	puts("Enter word to check");
	fflush(stdin);
	gets(temp);

	while (nwords >= 0)
	{
		if (!(strcmp(temp, dictionary[nwords])))
		{
			puts("Correct!");
			return 0;
		}

		nwords--;
	}

	puts("Wrong");
	return 0;
}

int findWord()
{
	char bestFit[20] = "";
	int numMatches = 0;
	int highestMatch = 0;
	int i = 0, j = 0, len = 0, len2 = 0;
	char temp[20];
	int tempCount = 0, wordCount = 0;

	puts("Enter letters you have");

	scanf("%s", temp);
	len = strlen(temp);

	nwords--;
	j = nwords;

	while (nwords >= 0)
	{

		len2 = strlen(dictionary[nwords]);

		if (len >= len2) //cant make words longer than itself
		{

			for (i = 0; i < len2; i++)
			{
				tempCount = countCharOccurence(temp, dictionary[nwords][i]);
				wordCount = countCharOccurence(dictionary[nwords], dictionary[nwords][i]);

				if (wordCount <= tempCount)
				{
					numMatches++;
				}

				else
				{
					numMatches = 0;
					break;
	
				}
			}

			if (numMatches > highestMatch)
			{
				strcpy(bestFit, dictionary[nwords]);
				highestMatch = numMatches;
			}
			if (nwords == 0)
			{
				nwords = j;
				break;
			}

		}

		wordCount = 0;
		numMatches = 0;
		tempCount = 0;

		nwords--;
	}


	printf("Best Fit for \"%s\" is \"%s\"  [%d]\n", temp, bestFit, highestMatch);

	return numMatches;
}

int countCharOccurence(char *string, char c)
{
	int i = 0, count = 0, len = 0;
	len = strlen(string);

	for (i = 0; i<len; i++)
	{
		if (string[i] == c)
		{
			count++;
		}
	}
	return count;
}
