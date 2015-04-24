#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

struct contact
{
	char firstName[50];
	char lastName[50];
	char companyName[50];
	char address[50];
	char city[50];
	char county[50];
	char state[50];
	char zip[50];
	char phone1[50];
	char phone2[50];
	char email[50];
	char web[50];
};

int numContacts = 0;
struct contact *contacts;
int readFile(char *fileName);
int findContact(char *string);
void printContact(struct contact *theContact);
int countLines(char *fileName);
int findCity(char *string);
int findCompany(char *string);
int findState(char *string);
int findZip(char *string);
int findCounty(char *string);

void main()
{
	char string[20];
	char fileName[] = "C:\\Users\\User\\Documents\\us-500b.txt";
	int i = 0;
	int option;

	numContacts = countLines(fileName);

	contacts = (struct contact *)malloc(numContacts*sizeof(struct contact));

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return;
	}

	while (i == 0) //loop until user imputs something that can be found
	{
		puts("Options:\n1-search by name\n2-search by company\n3-search by sity\n4-search by county\n5-search by state\n6-search by zip\n0-Exit\n"); //0 to exit added
		fflush(stdin);
		scanf("%d", &option);

		if (option == 0) break;

		puts("Enter all \(or part\) of what you are looking for:");
		fflush(stdin);
		gets(string);

		switch (option)
		{
		case 1:
			i = findContact(string);
			if (i == 0) printf("Nothing found, please retry!\n");
			break;
		case 2:
			i = findCompany(string);
			if (i == 0) printf("Nothing found, please retry!\n");
			break;
		case 3:
			i = findCity(string);
			if (i == 0) printf("Nothing found, please retry!\n");
			break;
		case 4:
			i = findCounty(string);
			if (i == 0) printf("Nothing found, please retry!\n");
			break;
		case 5:
			i = findState(string);
			if (i == 0) printf("Nothing found, please retry!\n");
			break;
		case 6:
			i = findZip(string);
			if (i == 0) printf("Nothing found, please retry!\n");
			break;
		default:
			break;
		}
	}

	free(contacts); //clear up memory assigned to contacts 
}

void printContact(struct contact *theContact) //changed to be j from inital "struct contact *theContact" that was in the skeleton
{
	printf("First Name: %s\n", theContact->firstName);
	printf("Last Name: %s\n", theContact->lastName);
	printf("Company Name: %s\n", theContact->companyName);
	printf("Address: %s\n", theContact->address);
	printf("City: %s\n", theContact->city);
	printf("County: %s\n", theContact->county);
	printf("State: %s\n", theContact->state);
	printf("Zip: %s\n", theContact->zip);
	printf("Phone 1: %s\n", theContact->phone1);
	printf("Phone 2: %s\n", theContact->phone2);
	printf("Email: %s\n", theContact->email);
	printf("Web: %s\n\n", theContact->web);
}

int countLines(char *fileName)
{
	char line[200];
	FILE *fptr = fopen(fileName, "r");
	int nLines = 0;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return 0;
	}

	// use fgets to skip first line
	fgets(line, 200, fptr);
	fgets(line, 200, fptr);
	while (!feof(fptr))
	{
		nLines++;
		fgets(line, 200, fptr);
	}

	fclose(fptr);

	return nLines;
}

int readFile(char *fileName)
{
	char line[200];
	FILE *fptr = fopen(fileName, "r");
	char *token;
	char delim[6] = ",";
	int n = 0, i = 0;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return 0;
	}

	// use fgets to skip first line
	fgets(line, 200, fptr);

	//first data line
	fgets(line, 200, fptr);
	while (!feof(fptr))
	{
		if ((token = strtok(line, delim)) != NULL) strcpy((contacts + n)->firstName, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->lastName, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->companyName, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->address, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->city, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->county, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->state, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->zip, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->phone1, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->phone2, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->email, token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy((contacts + n)->web, token);
		//printContact((contacts+n));
		n++;
		//next data line
		fgets(line, 200, fptr);

	}

	fclose(fptr);

	return 1;
}

int findContact(char *string)
{
	int i, j = 0;
	char temp1[81];

	_strlwr(string);

	for (i=0;i<numContacts; i++)
	{
		_strlwr(strcpy(temp1, (contacts + i)->firstName));
		
		if (strstr(temp1, string) != NULL)
		{
			printContact(contacts+i);
			j = 1;
			continue;
		}

		_strlwr(strcpy(temp1, (contacts + i)->lastName));

		if (strstr(temp1, string) != NULL)
		{
			printContact(contacts + i);
			j = 1;
		}

	}
	return j;
}

int findCity(char *string)
{
	int i, j = 0;
	char temp1[81];

	_strlwr(string);

	for (i = 0; i<numContacts; i++)
	{
		_strlwr(strcpy(temp1, (contacts + i)->city));

		if (strstr(temp1, string) != NULL)
		{
			printContact(contacts + i);
			j = 1;
		}
	}
	return j;
}

int findCompany(char *string)
{
	int i, j = 0;
	char temp1[81];

	_strlwr(string);

	for (i = 0; i<numContacts; i++)
	{
		_strlwr(strcpy(temp1, (contacts + i)->companyName));

		if (strstr(temp1, string) != NULL)
		{
			printContact(contacts + i);
			j = 1;
		}
	}
	return j;
}

int findState(char *string)
{
	int i, j = 0;
	char temp1[81];

	_strlwr(string);

	for (i = 0; i<numContacts; i++)
	{
		_strlwr(strcpy(temp1, (contacts + i)->state));

		if (strstr(temp1, string) != NULL)
		{
			printContact(contacts + i);
			j = 1;
		}
	}
	return j;
}

int findCounty(char *string)
{
	int i, j = 0;
	char temp1[81];

	_strlwr(string);

	for (i = 0; i<numContacts; i++)
	{
		_strlwr(strcpy(temp1, (contacts + i)->county));

		if (strstr(temp1, string) != NULL)
		{
			printContact(contacts + i);
			j = 1;
		}
	}
	return j;
}

int findZip(char *string)
{
	int i, j = 0;
	char temp1[81];

	_strlwr(string);

	for (i = 0; i<numContacts; i++)
	{
		_strlwr(strcpy(temp1, (contacts + i)->zip));

		if (strstr(temp1, string) != NULL)
		{
			printContact(contacts + i);
			j = 1;
		}
	}
	return j;
}