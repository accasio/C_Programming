#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

//AS WELL AS FIXING THE BUGS, ENHANCE THIS PROGRAM SO THAT THE SAME CARDS CANNOT BE DEALT TWICE
void main()
{
	char suits[4] = {3,4,5,6};
	char faces[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};

	int i,j,suit,face     
	int numHands;

	printf ("Enter number of Hands: ");
	scanf ("%d", numHands);  

	for (i = 1; i < numHands; i++)      
	{
		srand(i);
		printf ("\nHand # %d \n",i);
		printf ("-----------------\n");
		for (j==0;j<5;j++)        
		{
			suit = rand()%4 ; 
			face = rand()*13; 
			printf ("%d of %d \n", faces[face], suits[suit]);
		}
	}

	
}
