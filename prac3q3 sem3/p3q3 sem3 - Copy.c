#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//q3
void displayRecord()
{
	char name[20];
	int mark,count=0;

	FILE* fp;

	fp = fopen("mixed.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot open mixed.txt\n");
		exit(-1);
	}

	printf("LIST OF RECORDS - mixed.txt\n");
	printf("\t Name \t \tMark\n");
	printf("\t ==== \t \t====\n");

	while (fscanf(fp, "%[^\n] %d\n", name, &mark) != EOF)
	{
		printf("%-23s %d\n", name, mark);
		count++;
	}

	printf("\n\nNumber of records=%d\n\n", count);

	fclose(fp);
}

//q4
void addRecords()
{
	char name[20],another;
	int mark, count = 0;

	FILE* fp;

	fp = fopen("mixed.txt", "a");

	if (fp == NULL)
	{
		printf("Cannot open mixed.txt\n");
		exit(-1);
	}

	printf("Add records\n");
	printf("-----------\n");
	printf("Add another records(Y=yes)?");
	rewind(stdin);
	scanf("%c", &another);

	while (toupper(another)=='Y')
	{
		printf("\tName:");
		rewind(stdin);
		scanf("%[^\n]",name);
		printf("\tMark:");
		scanf("%d", &mark);

		fprintf(fp, "%s \n%d\n", name, mark);
		printf("\nRecords successfully added...\n");
		count++;

		printf("Add another records(Y=yes)?");
		rewind(stdin);
		scanf("%c", &another);
	}
	printf("\n%d records have been added to mixed.txt\n",count);

	fclose(fp);
}

//q5
void main()
{
	int letter[27] = {0},i;
	char fileName[25],ch;

	FILE* fp;

	printf("Enter file name:");
	rewind(stdin);
	scanf("%s", fileName);

	fp = fopen(fileName, "r");

	if (fp == NULL)
	{
		printf("File open error\n");
		exit(-1);
	}

	while (fscanf(fp, "%c", &ch) != EOF)
	{
		ch = toupper(ch);

		if (isalpha(ch))
			letter[ch - 'A']++;
		else if (ch == ' ')
			letter[26]++;
	}

	printf("\nLetter : - ");

	for (i = 0; i < 26; i++)
	{
		printf("\n\t %c = %d", 'A' + i, letter[i]);
	}

	printf("\n\n No of words : %d\n\n", letter[26] + 1);

	fclose(fp);
}

void q3q4()
{
	displayRecord();
	addRecords();
}