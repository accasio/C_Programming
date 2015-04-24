#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include <stddef.h>
#include <ctype.h>
#pragma once

typedef struct Item{
	int lotNum;
	char name[200];
	char description[2000];
	float price1;
	float price2;
}item;

typedef struct Item_inv{
	int lotNum;
	char name[200];
	char description[2000];
	float price1;
	float price2;
	int price_paid;
}inv_item;

typedef struct vals{
	int num_items;
	item *return_item;
} values;

int getOption();
void search(int n, item *items);
int lotSearch(int n, item *items, int searchNum, int toPrint);
void searchPrice(int n, item *items, float low, float high);
void nameSearch(int n, item *items);
void descSearch(int n, item *items);

int readFile(char *fileName, item *items);
int countLines(char *fileName);
int removeStock(char *fileName, int n, item *items);
values add(char *fileName, int n, item *items);
values remove(char *fileName, int n, item *items);
item* deleteNode(item *front, int id);

void print(int n, item *items);
void printAll(int n, item *items);
int menu();

void sortMenu(int num_items, item *items);
void mergeSort(int num_items, item *A, int offset, int order);
void mergeInt(item *A, int a, item *B, int b, item *C, int offset, int order);
void mergeString(item *A, int a, item *B, int b, item *C, int offset, int order);
void mergeFloat(item *A, int a, item *B, int b, item *C, int offset, int order);
int order();//decide whether sort will be ascending or descending

int auction(int num_items, item *items, char *filename, int n, inv_item *inv_items, int num_inv, int cash);
int ai_prob_get(int A_Num, int num_items, item *items);
int descSearch2(int n, int anum, item *items, char *desc);
int wallet(int cash, int change);
void inventory(int paid, item *items, int n, inv_item *inv_items, int num_inv);
void auto_remove(char *fileName, int n, item *items, int lot_Num);
void printAll_inv(int n, inv_item *inv_items);
void print_inv(int n, inv_item *inv_items);
int sale(inv_item *inv_items, int num_inv, int cash);
int inv_readFile(char *fileName, inv_item *inv_item);