#include <stdio.h>

// clientData structure definition 
struct book {
	char title[20];
	char author[20];
	int year;
	int ISBN;
	float wholesale_price;
	float retail_price;
};

// prototypes 
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void setup();

int main()
{
	FILE *cfPtr; 
	int choice;  
	setup();

	// fopen opens the file; exits if file cannot be opened 
	if ((cfPtr = fopen("C:\\Users\\User\\Documents\\credit.dat", "rb+")) == NULL) 
	{
		printf("File could not be opened.\n");
	} 
	else 
	{
		while ((choice = enterChoice()) != 5) 
		{

			switch (choice) 
			{

			case 1:
				textFile(cfPtr);
				break;

			case 2:
				updateRecord(cfPtr);
				break;

				// create record 
			case 3:
				newRecord(cfPtr);
				break;

				// delete existing record 
			case 4:
				deleteRecord(cfPtr);
				break;

				// display message if user does not select valid choice 
			default:
				printf("Incorrect choice\n");
				break;
			} 
		} 
		fclose(cfPtr); 
	} 
	return 0; 
} 

void textFile(FILE *readPtr)
{
	FILE *writePtr; // books.txt file pointer 

	// create clientData with default information 
	struct book temp = { "", "", 0, 0, 0.0, 0.0 };

	// fopen opens the file; exits if file cannot be opened 
	if ((writePtr = fopen("C:\\Users\\User\\Documents\\book.txt", "w")) == NULL)
	{
		printf("File could not be opened.\n");
	} 
	else
	{
		rewind(readPtr); // sets pointer to beginning of file
		fprintf(writePtr, "Title\tAuthor\tYear\tISBN\tWholesle Price\tRetail Price\n");

		// copy all records from random-access file into text file
		while (!feof(readPtr)) 
		{
			fread(&temp, sizeof(struct book), 1, readPtr);
			if (temp.ISBN != 0) 
			{
				//fprintf(writePtr, "%-s%-16s%-11s%10.2f\n",client.isbn, client.lastName, client.firstName, client.balance);
				fprintf(writePtr, "%s\t%s\t%d\t%d\t%f\t%f\t\n", temp.title, temp.author, temp.year, temp.ISBN, temp.wholesale_price, temp.retail_price);
			}
		} 
		fclose(writePtr); 
	} 
}  

void updateRecord(FILE *fPtr)
{
	int isbn;        
	double newPrice; 

	// create clientData with no information 
	struct book client = { "", "", 0, 0, 0.0, 0.0 };

	// obtain number of account to update 
	printf("Enter account to update ( 1 - 100 ): ");
	scanf("%d", &isbn);

	// move file pointer to correct record in file 
	fseek(fPtr, (isbn - 1) * sizeof(struct book),SEEK_SET);

	// read record from file 
	fread(&client, sizeof(struct book), 1, fPtr);

	
	if (client.ISBN == 0)
	{
		printf("Acount #%d has no information.\n", isbn);
	} 
	else
	{  
		printf("%s\t%s\t%d\t%d\t%f\t%f\n\n", client.title, client.author, client.year, client.ISBN, client.wholesale_price, client.retail_price);
		// request transaction amount from user 
		printf("Enter add to ( + ) or take away ( - ) from retail price: ");
		scanf("%lf", &newPrice);
		client.retail_price += newPrice; // update record balance 

		printf("%s\t%s\t%d\t%d\t%f\t%f \n\n", client.title, client.author, client.year, client.ISBN, client.wholesale_price, client.retail_price);

		// move file pointer to correct record in file 
		fseek(fPtr, (isbn - 1) * sizeof(struct book),SEEK_SET);

		// write updated record over old record in file 
		fwrite(&client, sizeof(struct book), 1, fPtr);
	} 

} 

void deleteRecord(FILE *fPtr)
{

	struct book client; // stores book read from file 
	struct book blankBook = { "", "", 0, 0, 0.0, 0.0 };

	int isbn; // account number 

	printf("Enter account number to delete ( 1 - 100 ): ");
	scanf("%d", &isbn);

	// move file pointer to correct record in file 
	fseek(fPtr, (isbn - 1) * sizeof(struct book), SEEK_SET);

	// read record from file 
	fread(&client, sizeof(struct book), 1, fPtr);

	if (client.ISBN == 0) 
	{
		printf("Account %d does not exist.\n", isbn);
	} 
	else
	{ 
		// move file pointer to correct record in file 
		fseek(fPtr, (isbn - 1) * sizeof(struct book),SEEK_SET);
		// replace existing record with blank record 
		fwrite(&blankBook, sizeof(struct book), 1, fPtr);
	} 

} 

void newRecord(FILE *fPtr)
{
	struct book client = { "", "", 0, 0, 0.0, 0.0 };
	int isbn; // account number 

	printf("Enter new account number ( 1 - 100 ): ");
	scanf("%d", &isbn);

	// move file pointer to correct record in file 
	fseek(fPtr, (isbn - 1) * sizeof(struct book),SEEK_SET);

	// read record from file 
	fread(&client, sizeof(struct book), 1, fPtr);

	if (client.ISBN != 0)
	{
		printf("ISBN #%d already contains information.\n", client.ISBN);
	} 
	else
	{ 
		printf("Enter book title, author, year, wholesale price and retail price\n? ");
		scanf("%s %s %d %f %f", client.title, client.author, &client.year, &client.wholesale_price, &client.retail_price);

		client.ISBN = isbn;

		// move file pointer to correct record in file 
		fseek(fPtr, (client.ISBN - 1) *sizeof(struct book), SEEK_SET);
		fwrite(&client,sizeof(struct book), 1, fPtr);
	} 

} 

int enterChoice(void)
{
	int menuChoice; 
	printf("\nEnter your choice\n"
		"1 - store a formatted text file of acounts called\n"
		"    \"books.txt\" for printing\n"
		"2 - update an account\n"
		"3 - add a new account\n"
		"4 - delete an account\n"
		"5 - end program\n? ");

	scanf("%d", &menuChoice); 

	return menuChoice;

} 

void setup()
{
	FILE *fPtr;
	int i;
	struct book blankBook = { "", "", 0, 0, 0.0, 0.0 };

	if ((fPtr = fopen("C:\\Users\\User\\Documents\\credit.dat", "ab+")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		for (i = 1; i <= 100; i++)
		{
			fwrite(&blankBook, sizeof(struct book), 1, fPtr);
		}

		fclose(fPtr);
	}
}