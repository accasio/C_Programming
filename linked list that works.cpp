#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct node
{
	int  id;
	char name[MAX];
	struct node *next;
};


struct node *insert(struct node *front, int id, char name[])
{
	struct node *newnode;

	newnode = (struct node*)malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("\n Allocation failed \n");
		exit(2);
	}
	newnode->id = id;
	strcpy(newnode->name, name);
	newnode->next = front;
	front = newnode;
	return(front);
}

void printNode(struct node *p)
{
	printf("\n node Details...\n");
	printf("\n Emp No       : %d", p->id);
	printf("\n Name           : %s", p->name);
	printf("-------------------------------------\n");
}

struct node* deleteNode(struct node *front, int id)
{
	struct node *ptr;
	struct node *bptr;

	if (front->id == id)
	{
		ptr = front;
		printf("\n Node deleted:");
		printNode(front);
		front = front->next;
		free(ptr);
		return(front);
	}
	for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next, bptr = bptr->next)
	{
		if (ptr->id == id)
		{
			printf("\n Node deleted:");
			printNode(ptr);
			bptr->next = ptr->next;
			free(ptr);
			return(front);
		}
	}
	printf("\n node ID %d not found ", id);
	return(front);
}

void search(struct node *front, int ID)
{
	struct node *ptr;

	for (ptr = front; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->id == ID)
		{
			printf("\n Key found:");
			printNode(ptr);
			return;
		}
	}
	printf("\n node ID %d not found ", ID);
}

void display(struct node  *front)
{
	struct node *ptr;

	for (ptr = front; ptr != NULL; ptr = ptr->next)
	{
		printNode(ptr);
	}
}

void menu()
{
	printf("---------------------------------------------\n");
	printf("Press 1 to INSERT a node into the list       \n");
	printf("Press 2 to DELETE a node from the list       \n");
	printf("Press 3 to DISPLAY the list                 \n");
	printf("Press 4 to SEARCH the list                   \n");
	printf("Press 5 to EXIT                              \n");
	printf("---------------------------------------------\n");
}

char option()
{
	char choice;

	printf("\n\n>> Enter your choice: ");
	fflush(stdin);
	switch (choice = getchar())
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':   return(choice);
	default:   printf("\n Invalid choice.");
	}
	return choice;
}

void main()
{
	struct node *linkList;
	char name[21];
	char choice;
	int id;

	linkList = NULL;
	printf("\n Welcome to demonstration of singly linked list \n");
	menu();
	do
	{

		choice = option();
		switch (choice)
		{
		case '1':
			printf("\n Enter the node ID      : ");
			scanf("%d", &id);
			printf("Enter the node name        : ");
			fflush(stdin);
			gets(name);
			linkList = insert(linkList, id, name);
			break;
		case '2':
			printf("\n\n Enter the ID of node to be deleted: ");
			scanf("%d", &id);
			linkList = deleteNode(linkList, id);
			break;
		case '3':
			if (linkList == NULL)
			{
				printf("\n List empty.");
				break;
			}
			display(linkList);
			break;
		case '4':
			printf("\n\n Enter the node ID to be searched for: ");
			scanf("%d", &id);
			search(linkList, id);
			break;
		case '5': break;
		}
	} while (choice != '5');
}
