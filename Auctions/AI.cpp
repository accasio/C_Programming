#include "neil.h"

int ai_prob_get(int A_Num, int num_items, item *items)
{
	char desc[3][20] = { "Painting", "Statue", "Furniture" };//key words, each ai has a key word and if it's in the description it will increase the probability of the ai to bet
	int i;
	char temp[200];//will hold the description
	int found;

	for (i = 0; i < 3; i++)
	{
		strcpy(temp, desc[i]);
		found = descSearch2(num_items, A_Num, items, temp);
		if (found)
		{
			break;
		}
	}

	switch (i)
	{
	case 0:
		return 1;
	case 1:
		return 2;
	case 2:
		return 3;
	default:
		return 0;
	}
}

int descSearch2(int n, int anum, item *items, char *desc)
{
	int i = 0;//counter
	char temp[1000], search[1000];
	strcpy(search, desc);
	_strlwr(search);
	for (i = 0; i < n; i++)
	{
		if (anum == (items + i)->lotNum)
		{
			break;//exit search loop
		}
	}

	strcpy(temp, (items + i)->name);
	_strlwr(temp);

	if (strstr(temp, search) != NULL)
	{
		return 1;
	}
	return 0;
}