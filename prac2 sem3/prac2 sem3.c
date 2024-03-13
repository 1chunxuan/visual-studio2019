#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define MAX_SIZE 20


typedef struct {
	char performerName[50];
	char song[50];
	int year;
	int playTime;
}Songs;

//q1
void q1()
{
		//a
		Songs songList[10] = {
			{"Ed Sheeran","Perfect Place", 2019,253},
			{"Taylor Swift", "Love Story", 2008, 260},
			{"Taylor Swift", "September", 2016,225},
			{"Bruno Mars", "24K Magic", 2018,249},
			{"Taylor Swift", "Style", 2014,94},
			{"Ed Sheeran", "Happier", 2018,203},
			{"Taylor Swift", "You belong with me", 2008,235},
			{"Bruno Mars", "Just the way you are", 2010, 190},
			{"Ed Sheeran", "Lego home", 2011, 193},
			{"Bruno Mars", "It will rain", 2011, 195}
		};

		//b
		int totalPlayTime = 0, count = 0;
		int searchTimeMin, searchTimeMax;
		char searchName[30];

		printf("\tMy collection of songs\n");
		printf("--------------------------------------------------------\n");
		printf("\n%-30s %-30s %s \t %s\n ","Performer"  ," Song ","Year" ,"Playing Time");
		printf("\n%-30s %-30s %s \t %s\n ", "Performer");
		
		for (int i = 0; i < 10; i++)
		{
			totalPlayTime += songList[i].playTime;
			printf("%-30s  %-30s  %d  %3d\n", songList[i].performerName, songList[i].song, songList[i].year, songList[i].playTime);
		}

		printf("\n-------------------------------------------------\n");
		printf("\tTotal Playing Time =%d seconds (=%d min %d sec)\n", totalPlayTime, totalPlayTime / 60, totalPlayTime % 60);

		//c
		printf("List of songs – 2015 and earlier\n");
		for (int i = 0; i < 10; i++)
		{
			if (songList[i].year <= 2015)
			{
				count++;
				printf("\n%-30s  %-30s  %d  %3d\n", songList[i].performerName, songList[i].song, songList[i].year, songList[i].playTime);
			}
		}
		printf("\n-------------------------------------------------\n");
		printf("\n%d total songs listed", count);

		//d
		count = 0;
		printf("Performer's Name to search:");
		rewind(stdin);
		scanf("%[^\n]", &searchName);

		printf("\nSong     Year released      Playing Time\n");
		printf("------------------------------------------------");
		for (int i = 0; i < 10; i++)
		{
			if (strcmp(searchName, songList[i].performerName) == 0)
			{
				printf("% -30s % d % 3d\n", songList[i].song, songList[i].year, songList[i].playTime);
				count++;
			}
		}
		printf("\n-------------------------------------------------\n");
		printf("%d records found for Performer's Name =%s", count, searchName);

		//e
		totalPlayTime = 0;
		printf("\nSearching based on 2 criteria:");
		printf("1. Performer’s Name > ");
		rewind(stdin);
		scanf("%[^\n]", &searchName);
		printf("2. Playing Time range(seconds) - from >");
		scanf("%d", &searchTimeMin);
		printf("\n                             - To >");
		scanf("%d", &searchTimeMax);

		printf("\n%-30s ");

		for (int i = 0; i < 10; i++)
		{
			if (strcmp(searchName, songList[i].performerName) == 0 && songList[i].playTime >= searchTimeMin && songList[i].playTime <= searchTimeMin)
			{
				printf("% -30s % d % 3d\n", songList[i].song, songList[i].year, songList[i].playTime);
				totalPlayTime += songList[i].playTime;
			}
		}
		printf("\n-------------------------------------------------\n");
		printf("\tTotal Playing Time =%d seconds (=%d min %d sec)\n", totalPlayTime, totalPlayTime / 60, totalPlayTime % 60);
}

//q2a(i)
struct DATE {
	int day;
	int month;
	int year;
};

//(ii)
typedef struct {
	char ID[4];
	char name[21];
	struct DATE dateJoined;
	char department[15];
}Employee;

//(iv)
Employee emp[MAX_SIZE] = { {"E01", "Alice Chin", 5, 12, 2008, "R&D"},
	{"E02", "John", 9, 12, 2011, "IT"},
	{"E03", "Vivian", 3, 3, 2015, "HR"},
	{"E04", "Alice Chin", 4, 4, 2011, "IT"},
	{"E05", "Vivien Tan", 5, 3, 2015, "HR"} };

int nEmployee = 5;

//q2b
void displayAll()
{
	int i, count = 0;
	printf("\n\tEmployee Details\t\n");
	printf("%-s \t %-20s  %11s \t %-s\n", "ID", "name","Date Joined","Department");
	printf("%-s \t %-20s  %11s \t %-s\n","==","====","==========","==========");

	for (i = 0; i < nEmployee; i++)
	{
		printf("%-s \t %-20s %02d%02d%d \t %-s\n",emp[i].ID,emp[i].name,emp[i].dateJoined.day,emp[i].dateJoined.month,emp[i].dateJoined.year,emp[i].department);
		count++;
	}
	printf("\n\t %d records listed.\n",count);
}

//q2c
void search()
{
	int i, searchMonth,searchYear,count;
	char cont;

	do {
		count = 0;

		printf("Enter the month to search:");
		scanf("%d", &searchMonth);
		printf("Enter the year to search:");
		scanf("%d", &searchYear);

		printf("%-s \t %-20s  %11s \t %-s\n", "ID", "name", "Date Joined", "Department");
		printf("%-s \t %-20s  %11s \t %-s\n", "==", "====", "==========", "==========");

		for (i = 0; i < nEmployee; i++)
		{
			if (searchMonth == emp[i].dateJoined.month && searchYear == emp[i].dateJoined.year)
			{
				printf("%-s \t %-20s %02d%02d%d \t %-s\n", emp[i].ID, emp[i].name, emp[i].dateJoined.day, emp[i].dateJoined.month, emp[i].dateJoined.year, emp[i].department);
				count++;
			}
		}
		printf("\n\t%D employee(s) joined in %02d/%d\n",count,searchMonth,searchYear);

		printf("Search for another(Y==yes): ");
		rewind(stdin);
		scanf("%c",&cont);
	} while (toupper(cont) == 'Y');
}

void addRecord()
{

}

//q2d
void viewRecord()
{
	int i,found;
	char viewId[4],cont;

	do {
		found = 0;
		printf("Enter ID of Employee to view :");
		rewind(stdin);
		scanf("%[^\n]",&viewId);

		printf("%-s \t %-20s  %11s \t %-s\n", "ID", "name", "Date Joined", "Department");
		printf("%-s \t %-20s  %11s \t %-s\n", "==", "====", "==========", "==========");

		for (i = 0; i < nEmployee; i++)
		{
			if (strcmp(viewId, emp[i].ID) == 0)
			{
				printf("%-s \t %-20s %02d%02d%d \t %-s\n", emp[i].ID, emp[i].name, emp[i].dateJoined.day, emp[i].dateJoined.month, emp[i].dateJoined.year, emp[i].department);
				found = 1;
			}
		}

		if (!found)//!found = (found=0)
		{
			printf("---Record not found!---\n");
		}
	
		printf("View for another(Y==yes): ");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'Y');
}

//q2e
void editRecord()
{
	int i, editIndex;
	char editId[4],confirmedUpd,cont;
	Employee temp;

	do {
		editIndex = -1;

		printf("Enter id of employee to edit :");
		rewind(stdin);
		scanf("%s",&editId);

		i = 0;
		while (i < nEmployee)
		{
			if(strcmp(editId, emp[i].ID) == 0)
			{
				editIndex = i;
			}
			i++;
		}
		if (editIndex == -1)
		{
			printf("\n\tERROR:Employee not found!\n\n");
		}
		else
		{
			printf("\nRecord found :-\n");
			printf("%-s \t %-20s  %11s \t %-s\n", "ID", "name", "Date Joined", "Department");
			printf("%-s \t %-20s  %11s \t %-s\n", "==", "====", "===========", "==========");
			printf("%-s \t %-20s %02d%02d%d \t %-s\n", emp[editIndex].ID, emp[editIndex].name, emp[editIndex].dateJoined.day, emp[editIndex].dateJoined.month, emp[editIndex].dateJoined.year, emp[editIndex].department);
			printf("\nEnter update details here:");
			printf("ID :%d\n",emp[editIndex].ID);
			printf("Name : ");
			rewind(stdin);
			scanf("%[^\n]",&temp.name);
			printf("Date joined (dd/mm/yyyy) :");
			scanf("%d/%d/%d", &temp.dateJoined.day, &temp.dateJoined.month, &temp.dateJoined.year);
			printf("Department :");
			rewind(stdin);
			scanf("%s", temp.department);

			printf("Confirm to update(Y=yes)?");
			rewind(stdin);
			scanf("%c", &confirmedUpd);

			if (toupper(confirmedUpd) == 'Y')
			{
				strcpy(temp.ID, editId);
				emp[editIndex] = temp;
			}
			else
			{
				printf("No change made!\n");
			}

			printf("\nCurrent details -\n");
			i--;
			printf("%-s \t %-20s  %11s \t %-s\n", "ID", "name", "Date Joined", "Department");
			printf("%-s \t %-20s  %11s \t %-s\n", "==", "====", "==========", "==========");
			printf("%-s \t %-20s %02d%02d%d \t %-s\n", emp[editIndex].ID, emp[editIndex].name, emp[editIndex].dateJoined.day, emp[editIndex].dateJoined.month, emp[editIndex].dateJoined.year, emp[editIndex].department);
		}

		printf("View for another(Y==yes): ");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'Y');
}


void main()
{
	int choice;
	do {
		printf("\n EMPLOYEE MENU\n\n");
		printf("1.Search employee(s)\n");
		printf("2.Add employee\n");
		printf("3.View employee\n");
		printf("4.Edit employee\n");
		printf("5.Display ALL employees");
		printf("6.EXIt\n\n");
		printf("Choose from 1,2,3,4,5,6 :");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:search(); break;
		case 2:addRecord(); break;
		case 3:viewRecord(); break;
		case 4:editRecord(); break;
		case 5:displayAll(); break;
		case 6:printf("Exiting Menu...\n\n"); break;
		default:printf("Invalid choice,please key in again.\n\n"); break;
		}
	} while (choice != 6);
	printf("END OF PROCESSING...\n\n");
}