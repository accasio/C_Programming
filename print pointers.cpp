#include "stdafx.h"
#include <stdio.h>
#include <string.h>

void charAddresses(char *string); // 1st function to do
void commaToSpace(char *str); // 2nd function to do
void printWord(char *start); //3rd function to do
char *nextWord(char *start); // 4th function to do


void main()
{
	int i = 0;
	char location[200] = "7825,CREEK VALLEY,SACRAMENTO,95828,CA";
	char *ptr;

	// 1. call function to print out the address and content of each character in the input array
	charAddresses(location);

	// 2. call function to replace all the commas in the input string with tabs
	commaToSpace(location);

	puts("Without commas:");
	puts(location);
	puts("");

	// 3. instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
	puts("First Word");
	printWord(location);

	puts("Second Word");
	printWord(location + 5);

	puts("Third Word");
	printWord(location + 11);
	puts("");

	// starting from the first character in the input string, each call to "nextWord" should return the next word in the string
	// e.g. if the input string is "Hi there everyone" :
	// first call to nextWord should return the address of the letter 't' of "there"
	// second call to nextWord should return the address of the first letter 'e'of "everyone"
	// third call to nextWord should return NULL
	ptr = location;
	while (ptr)
	{
		// instead of printing characters (using putchar) until a '\0', printWord prints characters until a space ' '
		printWord(ptr);
		printf("\n");
		ptr = nextWord(ptr);
	}


}

void charAddresses(char *string)
{
	int i = 0;
	printf("Charater\tAddress\n");

	while( *(string+i) != '\0')
	{
		printf("%c\t\t%p\n", *(string+i), (string+i));
		i++;
	}
}
void commaToSpace(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		if (*(str + i) == ',')
		{
			*(str + i) = ' ';
		}
			
		i++;
	}

}

void printWord(char *start)
{
	char *ip = start;

	while(*ip != '\0')
	{
		printf("%c", *ip);

		if (*ip == ' ')
		{
			printf("\n");
			break;
		}

		ip++;
	}

}

char *nextWord(char *start)
{
	char *ip = start;

	while(*ip != '\0')
	{
		if (*ip == ' ')
		{
			return (ip + 1);
		}

		ip++;
	}
	
	return NULL;
}