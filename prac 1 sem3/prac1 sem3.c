#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#pragma warning(disable:4996)

//q1
struct attendance {
	char studentName[25];
	char programmeCode[4];
	int yearOfStudy;
	int groupNo;
	int daysAbsent;
};

void main()
{
	struct attendance att;

	/*strcpy(att.studentName, "Samuel");
	strcpy(att.programmeCode, "DFT");
	att.yearOfStudy = 1;
	att.groupNo = 11;
	att.daysAbsent = 3;*/

	printf("Student Name:");
	scanf("%[^\n]", &att.studentName);
	rewind(stdin);
	printf("Enter programme code:");
	scanf("%[^\n]", &att.programmeCode);
	printf("year of study:");
	scanf("%d", &att.yearOfStudy);
	printf("Group no:");
	scanf("%d", &att.groupNo);
	printf("Days Absent:");
	scanf("%d", &att.daysAbsent);

	printf("Name      Programme     Group   Days  Absent  Action \n");
	printf("---------------------------------------------------------------\n");
	printf("%-25s     %3s%d   %02d   %2d", att.studentName, att.programmeCode, att.yearOfStudy, att.groupNo, att.daysAbsent);

	switch (att.daysAbsent)
	{
	case 0:break;
	case 1:;
	case 2:printf("\t\twarning to student.\n"); break;
	case 3:;
	case 4:printf("\t\tInform parents.\n"); break;
	default:printf("\t\tBar from exam.\n"); break;
	}
}

//q2a
typedef struct {
	char bookId[10];
	char author[40];
	char title[60];
	char publisher[40];
	int year;
	int quantityInStock;
}BookInventory;

void q2a()
{
	BookInventory book = { "BK-2044","JK Rowling","Harry Potter and the Prisoner of Azkaban","Bloomsbury",1999,25 };

	printf("\nBook details\n");
	printf("------------------");
	printf("Book ID                     :%s\n", book.bookId);
	printf("Author                      :%s\n", book.author);
	printf("Title                       :%s\n", book.title);
	printf("Publisher                   :%s\n", book.publisher);
	printf("Year of publication         :%d\n", book.year);
	printf("Quantity in stock           :%d\n", book.quantityInStock);
}

//q2b
typedef struct {
	char bookId[10];
	char author[40];
	char title[60];
	char publisher[40];
	int year;
	int quantityInStock;
}BookInventory;

struct Transaction {
	char transactioncode;
	int quantity;
};

void q2b()
{
	BookInventory book = { "BK-2044","JK Rowling","Harry Potter and the Prisoner of Azkaban","Bloomsbury",1999,25 };

	struct Transaction txn;

	printf("\nBook details\n");
	printf("------------------");
	printf("Book ID                     :%s\n", book.bookId);
	printf("Author                      :%s\n", book.author);
	printf("Title                       :%s\n", book.title);
	printf("Publisher                   :%s\n", book.publisher);
	printf("Year of publication         :%d\n", book.year);
	printf("Quantity in stock           :%d\n", book.quantityInStock);
}

//q2c
typedef struct {
	char bookId[10];
	char author[40];
	char title[60];
	char publisher[40];
	int year;
	int quantityInStock;
}BookInventory;

struct Transaction {
	char transactioncode;
	int quantity;
};

void q2c()
{
	BookInventory book = { "BK-2044","JK Rowling","Harry Potter and the Prisoner of Azkaban","Bloomsbury",1999,25 };

	struct Transaction txn;

	printf("\nBook details\n");
	printf("------------------");
	printf("Book ID                     :%s\n", book.bookId);
	printf("Author                      :%s\n", book.author);
	printf("Title                       :%s\n", book.title);
	printf("Publisher                   :%s\n", book.publisher);
	printf("Year of publication         :%d\n", book.year);
	printf("Quantity in stock           :%d\n", book.quantityInStock);

	printf("Key in the transaction code here:");
	printf("Transaction code (S=sold,P=purchased,X=exit):");
	rewind(stdin);
	scanf("%c", txn.transactioncode);
	printf("Transaction quantity:");
	scanf("%d", txn.quantity);

	if (toupper(txn.transactioncode) == 'S')
	{
		book.quantityInStock = book.quantityInStock - txn.quantity;
	}
	else if (toupper(txn.transactioncode) == 'P')
	{
		book.quantityInStock = book.quantityInStock + txn.quantity;
	}
	else
		printf("\nInvalid transaction code.\n");
}

//q2d
typedef struct {
	char bookId[10];
	char author[40];
	char title[60];
	char publisher[40];
	int year;
	int quantityInStock;
}BookInventory;

struct Transaction {
	char transactioncode;
	int quantity;
};

void q2d()
{
	BookInventory book = { "BK-2044","JK Rowling","Harry Potter and the Prisoner of Azkaban","Bloomsbury",1999,25 };

	struct Transaction txn;

	printf("\nBook details\n");
	printf("------------------");
	printf("Book ID                     :%s\n", book.bookId);
	printf("Author                      :%s\n", book.author);
	printf("Title                       :%s\n", book.title);
	printf("Publisher                   :%s\n", book.publisher);
	printf("Year of publication         :%d\n", book.year);
	printf("Quantity in stock           :%d\n", book.quantityInStock);

	printf("Key in the transaction code here:");
	printf("Transaction code (S=sold,P=purchased,X=exit):");
	rewind(stdin);
	scanf("%c", txn.transactioncode);
	printf("Transaction quantity:");
	scanf("%d", txn.quantity);

	if (toupper(txn.transactioncode) == 'S')
	{
		book.quantityInStock = book.quantityInStock - txn.quantity;
		printf("Sold : %d copies of \"%s\" by %s\n", txn.quantity, book.title, book.author);
		printf("There are now %d in stock\n", book.quantityInStock);
	}
	else if (toupper(txn.transactioncode) == 'P')
	{
		book.quantityInStock = book.quantityInStock + txn.quantity;
		printf("Purchased : %d copies of \"%s\" by %s\n", txn.quantity, book.title, book.author);
		printf("There are now %d in stock\n", book.quantityInStock);
	}
	else
		printf("\nInvalid transaction code.\n");
}

//q2e
typedef struct {
	char bookId[10];
	char author[40];
	char title[60];
	char publisher[40];
	int year;
	int quantityInStock;
}BookInventory;

struct Transaction {
	char transactioncode;
	int quantity;
};

void q2e()
{
	BookInventory book = { "BK-2044","JK Rowling","Harry Potter and the Prisoner of Azkaban","Bloomsbury",1999,25 };

	struct Transaction txn;

	printf("\nBook details\n");
	printf("------------------");
	printf("Book ID                     :%s\n", book.bookId);
	printf("Author                      :%s\n", book.author);
	printf("Title                       :%s\n", book.title);
	printf("Publisher                   :%s\n", book.publisher);
	printf("Year of publication         :%d\n", book.year);
	printf("Quantity in stock           :%d\n", book.quantityInStock);

	printf("Key in the transaction code here:");
	printf("Transaction code (S=sold,P=purchased,X=exit):");
	rewind(stdin);
	scanf("%c", txn.transactioncode);

	while ((toupper(txn.transactioncode) != 'X'))
	{
		printf("Transaction quantity:");
		scanf("%d", txn.quantity);

		if (toupper(txn.transactioncode) == 'S')
		{
			book.quantityInStock = book.quantityInStock - txn.quantity;
			printf("Sold : %d copies of \"%s\" by %s\n", txn.quantity, book.title, book.author);
			printf("There are now %d in stock\n", book.quantityInStock);
		}
		else if (toupper(txn.transactioncode) == 'P')
		{
			book.quantityInStock = book.quantityInStock + txn.quantity;
			printf("Purchased : %d copies of \"%s\" by %s\n", txn.quantity, book.title, book.author);
			printf("There are now %d in stock\n", book.quantityInStock);
		}
		else
			printf("\nInvalid transaction code.\n");

		printf("Transaction code (S=sold,P=purchased,X=exit):");
		rewind(stdin);
		scanf("%c", txn.transactioncode);
	}
}

//q3
struct Time {
	int hour;
	int minute;
};

void q3()
{
	struct Time current, nextMin;

	printf("Enter the current time:-\n");
	printf("\tHours:\n");
	scanf("%d", &current.hour);
	printf("\tHours:\n");
	scanf("%d", &current.minute);

	while (current.hour < 0 || current.hour>12 || current.minute < 0 || current.minute >= 60)
	{
		printf("Invalid time,please enter again!\n");
		printf("Enter the current time:-\n");
		printf("\tHours:");
		scanf("%d", &current.hour);
		printf("\tMinute:");
		scanf("%d", &current.minute);
	}

	nextMin.hour = current.hour;
	nextMin.minute = current.minute + 1;
	if (nextMin.minute >= 60)
	{
		nextMin.minute -= 60;
		nextMin.hour = current.hour + 1;
		if (nextMin.hour > 12)
		{
			nextMin.hour -= 12;
		}
	}

	printf("This is now %2d:%02d.Next minute it will be %2d:%02d\n", current.hour, current.minute, nextMin.hour, nextMin.minute);
}