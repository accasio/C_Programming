#include "stdafx.h"
#include <stdio.h>
#include <string.h>

typedef enum  the_days { monday, tuesday, wednesday, thursday, friday, saturday, sunday, noday } day;

// ENHANCE THESE 2 FUNCTIONS SO THAT THEY GIVE THE CORRECT ANSWER FOR ALL DAYS OF THE WEEK
day yesterday(day today);
day tomorrow(day today);

char thedays[][10] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

day findDay(char string1[]);

void main(void)
{
	day today;
	char theDay[10];

	puts("Type the day (e.g. 'monday')");
	gets_s(theDay);

	today = findDay(theDay);

	if (today == noday)
	{
		puts("Error - invalid input - exiting");
		return;
	}

	printf("today\t    yesterday  \ttomorrow\n"
		"============================================\n");
	printf("%s\t %s\t %s\n", thedays[today], thedays[yesterday(today)], thedays[tomorrow(today)]);
}

day findDay(char string1[])
{
	int i = 0;
	day thisday;

	for (i = 0; i<7; i++)
	{
		if (!strcmp(thedays[i], string1))
		{
			break;
		}
	}

	thisday = (day)i;
	return thisday;
}

day yesterday(day today)
{
	day before;

	before = (day)(today - 1);

	if (before == -1)
	{
		before = (day)6;
	}
	return before;
}

day tomorrow(day today)
{
	day after;
	after = (day)(today + 1);
	
	if (after == 7)
	{	
		after = (day)0;
	}
	return after;
}
