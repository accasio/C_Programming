#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

int readResults(char *inPath);
int writeRange(char *start, char *end, int toFile, char *outPath);
int writeSingle(char *firstName, char *lastName, int toFile, char *outPath);

typedef struct
{
	int ID;
	char firstName[25];
	char lastName[25];
	char english, french, maths, philosophy;
} student;

student students[100];
int ns;

void main(int argc, char *argv[])
{
	char *firstName, *lastName;
	char *start, *end;
	char *inPath, *outPath = NULL;
	int toFile = 0, i;
	ns = 0;
	int ret;

	inPath = argv[1];
	readResults(inPath);
	firstName = argv[3];
	lastName = argv[4];
	outPath = argv[6];

	if (!strcmp("/o", argv[5])) toFile = 1;
	
	if (!strcmp("/s", argv[2])) writeSingle(firstName, lastName, toFile, outPath);

	else if (!strcmp("/r", argv[2])) writeRange(firstName, lastName, toFile, outPath);

	else printf("You entered something wrong\n");
}

int readResults(char *inPath)
{
	char temp[200];
	FILE *fptr;
	fptr = fopen(inPath, "r");

	if (fptr == NULL)
	{
		printf("Error in readResults opening data file: %s \n", inPath);
		return 0;
	}

	fgets(temp, 200, fptr);
	fscanf(fptr, "%d %s %s %c %c %c %c", &students[ns].ID, students[ns].firstName, students[ns].lastName, &students[ns].english,
		&students[ns].maths, &students[ns].french, &students[ns].philosophy);

	while (!feof(fptr))
	{
		ns++;
		fscanf(fptr, "%d %s %s %c %c %c %c", &students[ns].ID, students[ns].firstName, students[ns].lastName, &students[ns].english,
			&students[ns].maths, &students[ns].french, &students[ns].philosophy);
	}
	fclose(fptr);
	return 1;
}
int writeSingle(char *firstName, char *lastName, int toFile, char *outPath)
{
	FILE *fptr = NULL;
	if (outPath != NULL) fptr = fopen(outPath, "a+");

	int i;
	{
		for (i = 0; i < ns; i++)
		{
			if (!(strcmp(students[i].firstName, firstName)) && !(strcmp(students[i].firstName, firstName)))
			{
				printf("%d %s %s %c %c %c %c\n", students[i].ID, students[i].firstName, students[i].lastName, students[i].english, students[i].maths, students[i].french, students[i].philosophy);

				if (toFile)
				{
					fprintf(fptr, "%d %s %s %c %c %c %c\n", students[i].ID, students[i].firstName, students[i].lastName, students[i].english, students[i].maths, students[i].french, students[i].philosophy);
				}
			}
		}
	}

	return 1;
}
int writeRange(char *start, char *end, int toFile, char *outPath)
{
	FILE *fptr = NULL;
	if (outPath != NULL) fptr = fopen(outPath, "a+");

	int i;
	for (i = 0; i < ns; i++)
	{
		if (!(strcmp(students[i].lastName, start)))
		{
			while (strcmp(students[i - 1].lastName, end))
			{
				printf("%d %s %s %c %c %c %c\n", students[i].ID, students[i].firstName, students[i].lastName, students[i].english, students[i].maths, students[i].french, students[i].philosophy);
				if (toFile)
				{
					fprintf(fptr, "%d %s %s %c %c %c %c\n", students[i].ID, students[i].firstName, students[i].lastName, students[i].english, students[i].maths, students[i].french, students[i].philosophy);
				}
				i++;
			}
			i = ns;
		}
	}
	return 1;
}