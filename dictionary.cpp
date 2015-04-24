#include "stdafx.h"
#include <stdio.h>
#include "string.h"


int countCharOccurence(char *string, char c);
int getOption();
int checkSpelling();
int findWord();

int nwords = 0;
char dictionary[80000][20];

void main(void)
{
	FILE *fptr;
	char fileName[] = "C:\\webster.txt";
	int option = 0;

	fptr = fopen(fileName, "r");

	if ( fptr  == NULL ) 
	{
		printf( "File could not be opened !!\n" );
		return;
	} 
	else 
	{ 
		while (!feof( fptr)) 
		{ 
			
			fscanf(fptr,"%s\n",dictionary[nwords]);
			nwords++;
		} 
			fclose(fptr);
	}

	printf ("%ld words read from file \n\n", nwords);
			
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
	int i=0;
	char temp[20];

	puts ("Enter word to check");
	fflush(stdin);
	gets (temp);

	for (i=0;i<nwords;i++)
	{
		if (!strcmp(temp,dictionary[i]))
		{
			puts("Spelling Correct!");
			return 1;
		}
	}
	puts("Word not found");
	return 0;
}

int findWord()
{
	char bestFit[20];
	int numMatches = 0;
	int highestMatch = 0;
	int i=0, j=0, len=0;
	char temp[20];
	int tempCount=0, wordCount=0;

	puts ("Enter letters you have");

	scanf("%s",temp);

	for (i=0;i<nwords;i++)
	{
		numMatches = 0;
		len = strlen(dictionary[i]);
		
		for (j=0;j<len;j++)
		{
			tempCount = 0;
			wordCount = 0;
			tempCount = countCharOccurence(temp, dictionary[i][j]);
			wordCount = countCharOccurence(dictionary[i], dictionary[i][j]);

			if ((tempCount > 0) && (tempCount == wordCount))
			{
				numMatches = numMatches + 1;
			}
			else
			{
				numMatches = 0;
				break;
			}
		}

		if (numMatches > highestMatch) 
		{
			strcpy(bestFit, dictionary[i]);
			highestMatch = numMatches;
		}
	}

	printf ("Best Fit for \"%s\" is \"%s\"  [%d]\n", temp, bestFit, highestMatch);

	return numMatches;
}

int countCharOccurence(char *string, char c)
{
	int i=0,count=0,len=0;
	len = strlen(string);
	for(i=0;i<len;i++)
	{
		if (string[i] == c) count++;
	}
	return count;
}
