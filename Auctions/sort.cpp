#include "neil.h"

void sortMenu(int num_items, item *items)
{
	int sortSwitch = 1, offset, Order;
	printf("01 Lot Number\n02 Name\n03 Description\n04 Low Estimate\n05 High Estimate\n00 Quit\n\n> ");
	scanf("%d", &sortSwitch);
	printf("\n------------------------------------\n");
	switch (sortSwitch)
	{
	case 1:
		offset = offsetof(item, lotNum);
		Order = order();
		mergeSort(num_items, items, offset, Order);
		printf("\nThe list of items in the auction house has been sorted by Lot Number in ");
		(Order) ? (printf("ascending")) : (printf("descending"));
		printf(" order.\n");
		break;
	case 2:
		offset = offsetof(item, name);
		Order = order();
		mergeSort(num_items, items, offset, Order);
		printf("\nThe list of items in the auction house has been sorted by Name in ");
		(Order) ? (printf("ascending")) : (printf("descending"));
		printf(" order.\n");
		break;
	case 3:
		offset = offsetof(item, description);
		Order = order();
		mergeSort(num_items, items, offset, Order);
		printf("\nThe list of items in the auction house has been sorted by Description in ");
		(Order) ? (printf("ascending")) : (printf("descending"));
		printf(" order.\n");
		break;
	case 4:
		offset = offsetof(item, price1);
		Order = order();
		mergeSort(num_items, items, offset, Order);
		printf("\nThe list of items in the auction house has been sorted by Low Estimate in ");
		(Order) ? (printf("ascending")) : (printf("descending"));
		printf(" order.\n");
		break;
	case 5:
		offset = offsetof(item, price2);
		Order = order();
		mergeSort(num_items, items, offset, Order);
		printf("\nThe list of items in the auction house has been sorted by High Estimate in ");
		(Order) ? (printf("ascending")) : (printf("descending"));
		printf(" order.\n");
		break;

	case 0:
		break;

	default:
		printf("Try that again.\n");
		break;
	}
	//printf("-------------------------------------\n");
}

void mergeSort(int num_items, item *A, int offset, int order)
{
	int i;
	item *A1, *A2;
	int n1, n2;

	if (num_items < 2) return; // the array is sorted if there is only one item


	// divide A into two array A1 and A2 
	n1 = num_items / 2;   // the number of elements in A1 
	n2 = num_items - n1;  // the number of elements in A2 
	A1 = (item*)malloc(sizeof(item) * n1);
	A2 = (item*)malloc(sizeof(item) * n2);

	//move the first n/2 elements to A1 
	for (i = 0; i < n1; i++) 
	{
		A1[i] = A[i];
	}
	// move the rest to A2 
	for (i = 0; i < n2; i++) 
	{
		A2[i] = A[i + n1];
	}
	// calling the function again in order to break down the longer array
	mergeSort(n1, A1, offset, order);
	mergeSort(n2, A2, offset, order);

	// once mergeSort has returned(n1=1 and n2=1) call merge function 
	if (offset == 0) mergeInt(A1, n1, A2, n2, A, offset, order);
	else if (offset == 4 || offset == 204) mergeString(A1, n1, A2, n2, A, offset, order);
	else if (offset == 2204 || offset == 2208) mergeFloat(A1, n1, A2, n2, A, offset, order);//offset is 2204 because 4(int) + 200(name) +2000(decription)
	else { printf("Error reading offset!\n"); return; }
	free(A1);
	free(A2);
}

void mergeInt(item *A1, int a, item *A2, int b, item *A, int offset, int order)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (i < a && j < b) 
	{
		if (*(int *)(char *)((A1 + i) + offset) <= *(int *)(char *)((A2 + j) + offset) && order == 1)
		{//casting A1 as a char as it needs to be shifted by offset*sizeof(char)
			A[k] = A1[i];
			i++;
			k++;
		}

		else if (*(int *)(char *)((A1 + i) + offset) >= *(int *)(char *)((A2 + j) + offset) && order == 0)
		{
			A[k] = A1[i];
			i++;
			k++;
		}

		else 
		{
			/* put A2[j] to A[k] and move the pointer j and k forward */
			A[k] = A2[j];
			j++;
			k++;
		}
	}
	/* move the remaining elements in A1 into A */
	while (i < a) 
	{
		A[k] = A1[i];
		i++;
		k++;
	}
	/* move the remaining elements in A2 into A */
	while (j < b)  //while j less than num elements 
	{
		A[k] = A2[j];
		j++;
		k++;
	}
}

void mergeString(item *A1, int a, item *A2, int b, item *A, int offset, int order)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (i < a && j < b)
	{
		if ((strcmp((char *)(A2 + j) + offset, (char *)(A1 + i) + offset) >= 1)&& order == 1)
		{
			A[k] = A1[i];
			i++;
			k++;
		}
		else if ((strcmp((char *)(A1 + i) + offset, (char *)(A2 + j) + offset) >= 1) && order == 0)
		{
			A[k] = A1[i];
			i++;
			k++;
		}

		else
		{
			/* put A2[j] to A[k] and move the pointer j and k forward */
			A[k] = A2[j];
			j++;
			k++;
		}
	}
	/* move the remaining elements in A1 into A */
	while (i < a)
	{
		A[k] = A1[i];
		i++;
		k++;
	}
	/* move the remaining elements in A2 into A */
	
	while (j < b)  //while j less than num elements, it will be emptied in here
	{
		A[k] = A2[j];
		j++;
		k++;
	}
}

void mergeFloat(item *A1, int a, item *A2, int b, item *A, int offset, int order)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	/*char temp = *((char *)(A1 + i) + offset);
	float temf = *(float)(temp);*/

	while (i < a && j < b)
	{
		if (*(float *)((char *)(A1 + i) + offset) <= *(float *)((char *)(A2 + j) + offset) && order == 1)
		{
			A[k] = A1[i];
			i++;
			k++;
		}
		else if (*(float *)((char *)(A1 + i) + offset) >= *(float *)((char *)(A2 + j) + offset) && order == 0)
		{
			A[k] = A1[i];
			i++;
			k++;
		}
		else
		{
			/* put A2[j] to A[k] and move the pointer j and k forward */
			A[k] = A2[j];
			j++;
			k++;
		}
	}
	/* move the remaining elements in A1 into A */
	while (i < a)
	{
		A[k] = A1[i];
		i++;
		k++;
	}
	/* move the remaining elements in A2 into A */
	while (j < b)  //while j less than num elements 
	{
		A[k] = A2[j];
		j++;
		k++;
	}
}

int order()
{
	int asc = 2;
	do
	{
		printf("Would you like to sort ascending (1) or decending (0)? ");
		if (!scanf("%d", &asc))
		{
			printf("That wasn't an option\n");
			asc = 2;
		}
	} while (asc < 0 || asc > 1);
	return asc;
}