#include "neil.h"

int ai_paint(int prev_bid, int prob, int low);
int ai_furniture(int prev_bid, int prob, int low);
int ai_sculpture(int prev_bid, int prob, int low);

int auction(int num_items, item *items, char *filename, int num_itm, inv_item *inv_items, int num_inv, int cash)
{
	int A_Num = 1;
	int i, found = 0, low_price, j = 2; // j used as modulus for use in getting probability of whether ai will bet
	int user_bid = 1;
	int ai_bid = 0, ai_bid_p, ai_bid_f, ai_bid_s; //ai bid will hold latest ai bid, for comparison with what the user will bid
	int x, y, z; // x,y,z are variables to hold the probabilites of each ai (x for painter, y for furniture, z for sculptor)
	int a = 0,b = 0,c = 0; // a,b,c are variables which will hold whether or not the ai bidded last round, if they are 1 the ai will be knocked out
	int count = 0;
	num_inv = countLines("inv.txt");

	while (A_Num != 0)
	{
		printf("\n\nEnter, the lot number for auction (0 to end): ");
		fflush(stdin);
		scanf("%d", &A_Num);
		printf("\n");
		found = 0;

		if (A_Num == 0) return num_items;

		for (i = 0; i < num_items; i++)
		{
			if ((items + i)->lotNum == A_Num)
			{
				found = 1;//exit search
				break;
			}
		}

		if (!found)
		{
			printf("This item does not exist\n");
			return cash;
		}
		printf("%d\t%s\t%s\t%.2f\t%.2f\n", (items + i)->lotNum, (items + i)->name, (items + i)->description, (items + i)->price1, (items + i)->price2);

		low_price = ((int)((items + i)->price1) + ((int)(items + i)->price2)) / 2;
		printf("Starting price =	%d\n", low_price);
		fflush(stdin);

		while (user_bid != 0)
		{
			fflush(stdin);
			printf("Enter Bid (0 for no bid): ");
			fflush(stdin);
			if ((scanf("%d", &user_bid)) != 1)
			{
				printf("Sorry, that's not an option\n");
				return cash;
			}
			if (user_bid == 0)//user gives up
			{
				printf("Counter bidder wins, item removed.\n");
				auto_remove(filename, num_items, items, A_Num);
				return cash;
			}
			else if (user_bid < low_price)
			{
				//can't bid less low price
				printf("You must bid higher than the starting price\n");
				continue;
			}
			else if (user_bid <= ai_bid)
			{
				//can't bid lower or equal to what the ai bid
				printf("You must bid higher than your opponents\n");
				continue;
			}
			printf("Your bid = %d\n", user_bid);

			switch (ai_prob_get(A_Num, num_items, items))
			{
			
			case 0://case 0 each will have equal probability - it will be 50/50
				x = 2; // probability variable for painter
				y = 2; // probability variable for furniture
				z = 2; // probability variable for sculptor
				if (a == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_p = ai_paint(user_bid, x, low_price); // get ai's probability from another function
					ai_bid = ai_bid_p;
					if (ai_bid == user_bid)
					{
						a = 1; // if ai didn't bet a will be set to 1
					}
				}

				if (b == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_f = ai_furniture(ai_bid, y, low_price); // get ai's probability from another function
					ai_bid = ai_bid_f;
					if (ai_bid_f == ai_bid_p)
					{
						b = 1;// if ai didn't bet a will be set to 1
					}
				}

				if (c == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_s = ai_sculpture(ai_bid, z, low_price); // get ai's probability from another function
					ai_bid = ai_bid_s;
					if (ai_bid_s == ai_bid_f)
					{
						c = 1;// if ai didn't bet a will be set to 1
					}
				}
				break;
			
			case 1://painting case will have the painter be more likely to bet
				x = 2; // painter will be 50/50
				y = 3; // furniture probability will be 33%
				z = 4; // sculptor probability will be 25%
				
				if (a == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_p = ai_paint(user_bid, x, low_price); // get ai's probability from another function
					ai_bid = ai_bid_p;
					if (ai_bid == user_bid)
					{
						a = 1; // if ai didn't bet a will be set to 1
					}
				}

				if (b == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_f = ai_furniture(ai_bid, y, low_price); // get ai's probability from another function
					ai_bid = ai_bid_f;
					if (ai_bid_f == ai_bid_p)
					{
						b = 1; // if ai didn't bet a will be set to 1
					}
				}

				if (c == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_s = ai_sculpture(ai_bid, z, low_price); // get ai's probability from another function
					ai_bid = ai_bid_s;
					if (ai_bid_s == ai_bid_f)
					{
						c = 1; // if ai didn't bet a will be set to 1
					}
				}

				break;
			case 2: // statue case will have the sculptor be more likely to bet
				x = 3; // paint ai probability will be 33%
				y = 2; // statue ai will be the most likely to bet at 50%
				z = 4; // furniture ai will be least likely 
				
				if (a == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_p = ai_paint(user_bid, x, low_price); // get ai's probability from another function
					ai_bid = ai_bid_p;
					if (ai_bid == user_bid)
					{
						a = 1; // if ai didn't bet a will be set to 1
					}
				}

				if (b == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_f = ai_furniture(ai_bid, y, low_price); // get ai's probability from another function
					ai_bid = ai_bid_f;
					if (ai_bid_f == ai_bid_p)
					{
						b = 1; // if ai didn't bet a will be set to 1
					}
				}

				if (c == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_s = ai_sculpture(ai_bid, z, low_price); // get ai's probability from another function
					ai_bid = ai_bid_s;
					if (ai_bid_s == ai_bid_f)
					{
						c = 1; // if ai didn't bet a will be set to 1
					}
				}
				break;
			
			case 3://furniture case will make the furniture collector more likely to bet
				x = 4;
				y = 3;
				z = 2;
				
				if (a == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_p = ai_paint(user_bid, x, low_price); // get ai's probability from another function
					ai_bid = ai_bid_p;
					if (ai_bid == user_bid)
					{
						a = 1; // if ai didn't bet a will be set to 1
					}
				}

				if (b == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_f = ai_furniture(ai_bid, y, low_price); // get ai's probability from another function
					ai_bid = ai_bid_f;
					if (ai_bid_f == ai_bid_p)
					{
						b = 1; // if ai didn't bet a will be set to 1
					}
				}

				if (c == 0) // if equal to one then ai didn't bet last round and they will be skipped
				{
					ai_bid_s = ai_sculpture(ai_bid, z, low_price); // get ai's probability from another function
					ai_bid = ai_bid_s;
					if (ai_bid_s == ai_bid_f) 
					{
						c = 1; // if ai didn't bet a will be set to 1
					}
				}
				break;
			}

			if (ai_bid > user_bid) // if the ai did will restart the betting
			{
				continue;// start back at the beginning of the auction, prompting the user if they want 
			}

			else//if the ai didn't bet at all, you won
			{
				printf("You win the auction\n");
				fflush(stdin);
				cash = cash - user_bid;

				printf("Your balance is now %d\n\n", cash);
				printf("You now have\n");
				num_inv++;
				inventory(user_bid, (items + i), num_items, inv_items, num_inv);
				printf("\nIn your inventory\n");
				auto_remove(filename, num_items, items, A_Num);
				num_items--;//one item less in items
				return cash;
			}
		}
	}
	return cash;

}

int ai_paint(int prev_bid, int prob, int low)
{
	int low_price = low, j;
	int ai_bid;

	j = prob;

	srand((unsigned int)time(NULL));
	ai_bid = rand() % j;//ai will be based on a 

	if (ai_bid == 1)
	{
		ai_bid = low_price;
		if (ai_bid >= low_price)
		{
			ai_bid = prev_bid + (low_price / (j + 4));
		}
		printf("Painter bid= %d\n", ai_bid);
	}

	else if (ai_bid != 1)
	{
		return prev_bid;//will return user's or previous ai's bid
	}

	return ai_bid;
}

int ai_furniture(int prev_bid, int prob, int low)
{
	int low_price = low, j;
	int ai_bid;
	j = prob;

	srand((unsigned int)time(NULL));
	ai_bid = rand() % j;

	if (ai_bid == 1)
	{
		ai_bid = low_price;
		if (ai_bid >= low_price)
		{
			ai_bid = prev_bid + (low_price / (j + 4));
		}
		printf("Furniture collector bid= %d\n", ai_bid);
	}
	else if (ai_bid != 1)//if ai didn't bet will return user bid 
	{
		return prev_bid;
	}
	return ai_bid;
}

int ai_sculpture(int prev_bid, int prob, int low)
{
	int low_price = low, j;
	int ai_bid;
	j = prob;

	srand((unsigned int)time(NULL));
	ai_bid = rand() % j;

	if (ai_bid == 1)
	{
		ai_bid = low_price;
		if (ai_bid >= low_price)
		{
			ai_bid = prev_bid + (low_price / (j + 4));
		}
		printf("Sculptor bid= %d\n", ai_bid);
	}
	else if (ai_bid != 1)
	{
		return prev_bid;
	}
	return ai_bid;
}