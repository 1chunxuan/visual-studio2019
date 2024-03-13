#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct {
	char facId[4], types, description, venue;
	int maxUser, password, openTime, closeTime;
}Facility;


struct Student {
	char id[11], name[30];
	double cGpa;
};

void eg()
{
	printf("I am baka");
}

void useless()
{
	int num;
	printf("enter 1 to stop print:");
	scanf("%d",&num);
	while (num != 1)
	{
		printf("HAHA\n");
		printf("enter 1 to stop print:");
		scanf("%d", &num);
	}
}

void password()
{
	int password;
	do {
		printf("Enter password:");
		scanf("%d",&password);
	} while (password != 123);
	printf("\n%d",password);
}

void password1()
{
	char password, ans = "haha";
	int count = 0;
	printf("enter password:");
	scanf("%s",&password);
	while (strcmp(ans, password) != 0)
	{
		printf("Enter again:");
		scanf("%s",&password);
		count++;
	}
	printf("\n%d", count);
}

void addRecords()
{
	struct Student stud;
	char answer;

	FILE* fp;

	fp = fopen("Student.txt", "w");

	if (fp == NULL)
	{
		printf("cannot open file\n");
		exit(-1);
	}

	printf("Any more records(Y/y for yes)?");
	rewind(stdin);
	scanf("%c", &answer);

	while (toupper(answer) == 'Y')
	{
		printf("Id :");
		rewind(stdin);
		scanf("%s", stud.id);
		printf("Name :");
		rewind(stdin);
		scanf("%[^\]", stud.name);
		printf("CGPA :");
		rewind(stdin);
		scanf("%lf", &stud.cGpa);

		fprintf(fp, "%s|%s|%.2lf\n", stud.id, stud.name, stud.cGpa);

		printf("Any more records(Y/y for yes)?");
		rewind(stdin);
		scanf("%c", &answer);
	}
	fclose(fp);
}

void addFunc()
{
	Facility facility;
	char reply;
	int count = 0;
	FILE* fptr;
	fptr = fopen("Text.txt", "r");
	if (fptr == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}

	fscanf(fptr, "%s %[^\] %[^\] %[^\] %d %d %d", &facility.facId, &facility.types, &facility.description, &facility.venue, &facility.maxUser, &facility.openTime, &facility.closeTime);
	while (!feof(fptr))
	{
		printf("%s|%s|%s|%s|%d|%d|%d\n",facility.facId,facility.types,facility.description,facility.venue,facility.maxUser,facility.openTime,facility.closeTime);
		fscanf(fptr,"%s %[^\] %[^\] %[^\] %d %d %d",&facility.facId,&facility.types,&facility.description,&facility.venue,&facility.maxUser,&facility.openTime,&facility.closeTime);
	}

	fclose(fptr);
}



void main()
{
	addFunc();
}