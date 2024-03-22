#include<stdio.h>
#pragma warning(disable:4996)

struct Student {
	char id[11], name[30];
	double cGpa;
};

//q3
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

//q4
void displayRecords()
{
	struct Student stud;

	FILE* fp;

	fp = fopen("Student.txt", "r");

	if (fp == NULL)
	{
		printf("cannot open file\n");
		exit(-1);
	}

	printf("\t\t\tList of Students\n\n");
	printf("%-10s\t%-30s\t%s\n","Student","Name","CGPA");
	printf("%-10s\t%-30s\t%s\n","=======","====","====");

	while (fscanf(fp, "%[^|]|%[^|]|%lf\n",stud.id, stud.name, &stud.cGpa) != EOF)
	{
		printf("%-10s \t %-30s \t %.2lf", stud.id, stud.name, stud.cGpa);
	}
	fclose(fp);
}

void p4q5()
{
	struct Student stud;

	int count = 0;
	FILE* fp,*fp1;

	fp = fopen("Student.txt", "r");
	fp1 = fopen("BookPrize.txt", "w");

	if (fp == NULL||fp1==NULL)
	{
		printf("cannot open file\n");
		exit(-1);
	}

	while (fscanf(fp, "%[^|]|%[^|]|%lf\n", stud.id, stud.name,&stud.cGpa) != EOF)
	{
		if (stud.cGpa >= 3.50)
		{
			fprintf(fp1, "%s|%s|%.3lf\n", stud.id, stud.name, stud.cGpa);
			count++;
		}
	}
	printf("%d records copied to BookPrize.txt\n", count);

	fclose(fp);
	fclose(fp1);
}

void main()
{
	/*addRecords();*/
	displayRecords();
}