#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

//q1a & q3a
void printArray(char arrName[], int arr[], int size)
{
	printf("Contents of : %s\n",arrName);

	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//q1b
int totalArray(const int arr[], int size)
{
	int total=0,i;
	for (i = 0; i < size; i++)
	{
		total+=arr[i];
	}
	return total;
}

//q1c
void getArray(int arr[], int size)
{
	printf("Enter array elements: \n");

	for (int i = 0; i < size; i++)
	{
		printf("Array[%d]:",i);
		scanf("%d",&arr[i]);
	}
}

//q2a
int convertDay(int day, char* dayName)
{
	int r = 1;
	switch (day)
	{
	case 0:strcpy(dayName,"Sunday"); break;
	case 1:strcpy(dayName, "Monday"); break;
	case 2:strcpy(dayName, "Tuesday"); break;
	case 3:strcpy(dayName, "Wednesday"); break;
	case 4:strcpy(dayName, "Thursday"); break;
	case 5:strcpy(dayName, "Friday"); break;
	case 6:strcpy(dayName, "Saturday"); break;
	default:strcpy(dayName, "???"); r = 0;
	}
	return r;
}

//q3a
void profit(int sell[], int cost[], int prof[], int size)
{
	for (int i = 0; i < size; i++)
	{
		prof[i] = sell[i] - cost[i];
	}
}

//q4
typedef struct {
	int hour, min, sec;
}Time;

Time elapsedTime(Time start, Time end)
{
	Time diff;

	if (end.sec >= start.sec)
		diff.sec = end.sec - start.sec;
	else
	{
		diff.sec = end.sec + 60 - start.sec;
		end.min--;
	}

	if (end.min >= start.min)
		diff.min = end.min - start.min;
	else
	{
		diff.min = end.min + 60 - start.min;
		end.hour--;
	}

	if (end.hour >= start.hour)
		diff.hour = end.hour - start.hour;
	else
	{
		diff.hour = end.hour + 24 - start.hour;
	}

	return diff;
}

//q5i
typedef struct {
	int day, month, year;
}Date;

typedef struct {
	char id[15],name[30];
	Date dob;
}Student;

void getDOB(Date* d)
{
	printf("Enter date of birth:\n");
	printf("\tDay:");
	scanf("%d",&d->day);
	printf("\tMonth:");
	scanf("%d",&d->month);
	printf("\tYear:");
	scanf("%d",&d->year);
}

//q5ii
void getStudentRec(Student* s)
{
	printf("Student ID: ");
	rewind(stdin);
	scanf("%s",s->id);
	printf("Name: ");
	rewind(stdin);
	scanf("%[^\n]", s->name);

	getDOB(&(s->dob));
}

void main()
{
	////q1
	/*int myArray[10];

	getArray(myArray, 10);
	printArray("My Array", myArray, 10);
	printf("\n\nTotal = %d\n",totalArray(myArray,10));*/

	////q2b
	//int today,tomorrow;
	//char todayName[10], tomorrowName[10];

	//printf("What is the day number of today(0-6):");
	//scanf("%d", &today);

	//tomorrow = today + 1;

	//if (tomorrow == 7)
	//	tomorrow == 0;
	//
	//if (!convertDay(today, todayName))
	//	printf("Error in conversion-Invalid day\n");
	//else
	//{
	//	convertDay(today, todayName);
	//	convertDay(tomorrow, tomorrowName);

	//	printf("Today is %s,tomorrow is %s\n",todayName,tomorrowName);
	//}

	////q3b
	//int s[5] = { 5,6,7,8,9 }, c[5] = { 3,2,1,4,5 }, p[5];

	//profit(s,c,p,5);

	//printArray("Sell",s,5);
	//printArray("Cost", c, 5);
	//printArray("Profit", p, 5);

	////q4
	//Time startTime, endTime;

	//printf("\n\nStart Time (hh:mm:ss):");
	//scanf("%d:%d:%d",&startTime.hour,&startTime.min,&startTime.sec);
	//printf("\n\nEnd Time (hh:mm:ss):");
	//scanf("%d:%d:%d", &endTime.hour, &endTime.min, &endTime.sec);

	//printf("\n\n---> Elapsed Time = %d hrs %d mins %d secs\n",elapsedTime(startTime,endTime));

	//q5iii(20% self do)
	FILE* ofp;
	Student s;
	int count=0;
	char answer;

	printf("\n\nOpening CS students text file....\n\n");

	ofp = fopen("CSsTudents.txt", "w");
	do {
		getSTudentRec(&s);
		count++;
		fprintf(ofp,"%s %d-%d-%d %s\n",s.id,s.dob.day,s.dob.month,s.dob.year,s.name);
		printf("Do you want to continue(Y=yes)?");
		count++;
		rewind(stdin);
		scanf("%c",&answer);
	} while (toupper(answer == 'Y'));

	printf("%d records listed",count);
}