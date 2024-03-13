#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable :4996)

//Tang Chun Xuan
void addFunc1();
void searchFunc1();
void modifyFunc1();
void displayFunc1();
void reportFunc1();
void deleteFunc1();

//Fong Jia Hao
void addFunc();
void displayFunc();
void modifyFunc();
void searchFunc();
void deleteFunc();

//Pang Shun Wang
void bookingAddNew();
void bookingmenu();
void bookingMod();
void bookingSrch();
void bookingDis();
int bookingDelete();
typedef struct {
	char Name[30];
	char id[10];
	char password[15];
	int icNo;
	char country[25];
	char address[50];
}Staff;
typedef struct {
	int Booking_ID;
	int Facility_ID;
}BookingInfo;
typedef struct {
	unsigned int cus_ID;
	float facilitiesPrice;
	char cusName[30];
	int cusPhoneNum;
	char cusAddr[100];
	int cusICNum;
}cusInfo;
typedef struct {
	int start;
	int end;
}bookingTime;
typedef struct {
	int year;
	int month;
	int day;
}date;
typedef struct {
	int year;
	int month;
	int day;
}todayDate;
typedef struct {
	char facId[4], types[20], description[40], venue[20];
	int maxUser, openTime, closeTime;
}Facility;
void addFunc1()
{
	Facility facility;
	char reply;
	int count = 0, password;
	FILE* fp;
	fp = fopen("facility.txt", "a");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}

	printf("Enter password to show your identity:");
	scanf("%d", &password);
	while (password != 12321)
	{
		printf("If enter incidentally,please stop this program and enter again\n");
		printf("Incorrect password,please enter again:");
		scanf("%d", &password);
	}
	printf("Do you want to enter new facility(Y =yes)?:");
	rewind(stdin);
	scanf("%c", &reply);

	do
	{
		printf("Please enter new facility Id:");
		rewind(stdin);
		scanf("%[^\n]", &facility.facId);
		printf("Please enter the facility types:");
		rewind(stdin);
		scanf("%[^\n]", &facility.types);
		printf("Please enter the description of the facility:");
		rewind(stdin);
		scanf("%[^\n]", &facility.description);
		printf("Please enter the facility's venue:");
		rewind(stdin);
		scanf("%[^\n]", &facility.venue);
		printf("Please enter the maximum allowable user:");
		rewind(stdin);
		scanf("%d", &facility.maxUser);
		printf("Please enter the open time(format:HHMM):");
		rewind(stdin);
		scanf("%d", &facility.openTime);
		printf("Please enter the close time(format:HHMM):");
		rewind(stdin);
		scanf("%d", &facility.closeTime);

		fprintf(fp, "%s|%s|%s|%s|%d|%d|%d\n", facility.facId, facility.types, facility.description, facility.venue, facility.maxUser, facility.openTime, facility.closeTime);
		scanf("Do you want add any new records(Y=yes)?");
		rewind(stdin);
		scanf("%c", &reply);
		count++;
	}while (toupper(reply) == 'Y');
	printf("%d records added\n", count);
	fclose(fp);
}

void searchFunc1()
{
	Facility facility[20];
	int i = 0, pCount = 0, a = 0;
	char reply, Id[4], ans;
	FILE* fp;
	fp = fopen("facility.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}

	while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility[i].facId, &facility[i].types, &facility[i].description, &facility[i].venue, &facility[i].maxUser, &facility[i].openTime, &facility[i].closeTime) != EOF)
	{
		a++;
		pCount = a;
	}
	printf("\nEnter the facility Id to know more information:");
	rewind(stdin);
	scanf("%s", &Id);
	do {
		for (i = 0; i <= pCount; i++)
		{
			if (strcmp(Id, facility[i].facId) == 0)
			{
				printf("Id\tTypes\t\tDescription\tVenue\t\tMaximum Allowable User\tOpen Time\tCLose Time\n");
				printf("==\t=====\t\t===========\t=====\t\t======================\t=========\t==========\n");
				printf("%-4s\t%-s\t\t%-s\t%-s\t\t%4d\t%4d\t%4d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
			}
			else
				printf("No such facilities!");
		}
		printf("\nAny more records to search(y=yes)?");
		rewind(stdin);
		scanf("%c", &reply);
	} while (toupper(reply) == 'Y');

	fclose(fp);
}

void modifyFunc1()
{
	Facility facility[20];
	int a = 0, pCount = 0, modiCount = 0, password, i = 0, UpdOpenTime, UpdCloseTime, found = 0, maxUser, opTime, cloTime;
	char ans, updId, Id[4], cont, types[20], description[40], venue[20];
	FILE* fp,*fp1;
	fp = fopen("facility.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}
	printf("Enter password to show your identity:");
	scanf("%d", &password);
	while (password != 12321)
	{
		printf("If enter incidentally,please stop this program and enter again\n");
		printf("Incorrect password,please enter again:");
		scanf("%d", &password);
	}

	while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility[i].facId, &facility[i].types, &facility[i].description, &facility[i].venue, &facility[i].maxUser, &facility[i].openTime, &facility[i].closeTime) != EOF)
	{
		a++;
		pCount = a;
	}
	printf("\nEnter the facility Id to know more information:");
	rewind(stdin);
	scanf("%s", &Id);
	/*printf("\nEnter the facility's type:");
	rewind(stdin);
	scanf("%[^\n]", &types);
	printf("\nEnter the facility's description:");
	rewind(stdin);
	scanf("%[^\n]", &description);
	printf("\nEnter the facility's venue:");
	rewind(stdin);
	scanf("%[^\n]", &venue);
	printf("\nEnter the facility's maximum allowable user:");
	rewind(stdin);
	scanf("%d", &maxUser);
	printf("\nEnter the facility's open time:");
	rewind(stdin);
	scanf("%d", &opTime);
	printf("\nEnter the facility's close time:");
	rewind(stdin);
	scanf("%d", &cloTime);*/
	do {
		for (i = 0; i <= pCount; i++)
		{
			if (strcmp(Id, facility[i].facId) == 0/* && strcmp(types, facility[i].types) == 0 && strcmp(description, facility[i].description && strcmp(venue, facility[i].venue) == 0 && facility[i].maxUser == maxUser && facility[i].openTime == opTime && facility[i].closeTime == cloTime*/)
			{
				found == 1;
				printf("Id\tTypes\t\tDescription\tVenue\t\tMaximum Allowable User\tOpen Time\tCLose Time\n");
				printf("==\t=====\t\t===========\t=====\t\t======================\t=========\t==========\n");
				printf("%-4s\t%-20s\t%-30s\t%s\t%4d\t%4d\t%4d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
				printf("\nUpdated open time:");
				scanf("%d", &UpdOpenTime);
				printf("\nUpdated close time:");
				scanf("%d", &UpdCloseTime);

				printf("\nConfirm to modify(Y=yes)?");
				rewind(stdin);
				scanf("%c", &ans);

				if (toupper(ans) == 'Y')
				{
					facility[i].openTime = UpdOpenTime;
					facility[i].closeTime = UpdCloseTime;;
					modiCount++;
					fscanf(fp, "%s|%s|%s|%s|%d|%d|%d\n", &facility[i].facId, &facility[i].types, &facility[i].description, &facility[i].venue, &facility[i].maxUser, &facility[i].openTime, &facility[i].closeTime);
				}
				
				printf("\nUpdated Record\n");
				printf("Id\tTypes\tDescription\tVenue\tMaximum Allowable User\tOpen Time\tCLose Time\n");
				printf("==\t=====\t===========\t=====\t======================\t=========\t==========\n");
				printf("%-4s\t%-15s %-s\t%s\t\t%2d\t\t%4d\t\t%4d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
				fprintf(fp,"%s|%s|%s|%s|%d|%d|%d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
			}
			else
			{
				printf("No such facilities!");
			}
		}
		printf("\nAny more records to modify(y=yes)?");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'Y');

	if (found==0)
	{
		printf("\no product match the ID %s\n", Id);
	}

	printf("\n%d record(s) modified\n", modiCount);
	fclose(fp);
}

void displayFunc1()
{
	Facility facility;
	FILE* fp;
	fp = fopen("facility.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}
	printf("Id\tTypes\t\tDescription\tVenue\t\tMaximum Allowable User\tOpen Time\tCLose Time\n");
	printf("==\t=====\t\t===========\t=====\t\t======================\t=========\t==========\n");
	while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility.facId, &facility.types, &facility.description, &facility.venue, &facility.maxUser, &facility.openTime, &facility.closeTime) != EOF)
	{
		printf("%-4s\t%-15s %-s\t%s\t\t%2d\t\t%4d\t\t%4d\n", facility.facId, facility.types, facility.description, facility.venue, facility.maxUser, facility.openTime, facility.closeTime);
	}
	fclose(fp);
}

void reportFunc1()
{
	FILE* fptr;
	fptr = fopen("report.txt", "a");
	char reports = "", reply;
	do {
		printf("Please enter your problems:");
		rewind(stdin);
		scanf("%[^\n]", &reports);

		fprintf(fptr,"%s\n",reports);

		printf("If do not want to continue,enter N:");
		rewind(stdin);
		scanf("%c", &reply);
	} while (toupper(reply == 'Y'));
}

void deleteFunc1()
{
	Facility facility[20];
	int i = 0, UpdOpenTime, UpdCloseTime, deleteCount = 0, pCount = 0, a = 0;
	char ans, Id[4], cont;
	FILE* fp;
	fp = fopen("facility.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}
	printf("Enter the Id to show the information of the facility:");
	rewind(stdin);
	scanf("%s", &Id);

	while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility[i].facId, &facility[i].types, &facility[i].description, &facility[i].venue, &facility[i].maxUser, &facility[i].openTime, &facility[i].closeTime) != EOF)
	{
		a++;
		pCount = a;
	}
	do
	{
		for (i = 0; i <= pCount; i++)
		{
			if (strcmp(Id, facility[i].facId) == 0)
			{
				printf("Id\tTypes\t\tDescription\tVenue\t\tMaximum Allowable User\tOpen Time\tCLose Time\n");
				printf("==\t=====\t\t===========\t=====\t\t======================\t=========\t==========\n");
				printf("%-4s\t%-15s %-s\t%s\t\t%2d\t\t%4d\t\t%4d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
				printf("\nConfirm to delete(Y=yes)?");
				rewind(stdin);
				scanf("%c", &ans);

				if (toupper(ans) == 'Y')
				{
					strcpy(facility[i].facId, " ");
					strcpy(facility[i].types, " ");
					strcpy(facility[i].description, " ");
					strcpy(facility[i].venue, " ");
					facility[i].maxUser = " ";
					facility[i].openTime = " ";
					facility[i].closeTime = " ";
					deleteCount++;
					fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility[i].facId, &facility[i].types, &facility[i].description, &facility[i].venue, &facility[i].maxUser, &facility[i].openTime, &facility[i].closeTime);
				}

			}
			else
			{
				printf("No such facilities!\n");
			}
		}

		printf("\nAny more records to delete(y=yes)?");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'Y');

	fclose(fp);
}

void facilityModule()
{
	int choice;
	do
	{

		printf("Facility Module\n");
		printf("1.Add facility(only for staff)\n");
		printf("2.Search facility\n");
		printf("3.Modify facility(only for staff)\n");
		printf("4.Display all facility\n");
		printf("5.Report the facility due to some problems\n");
		printf("6.Delete a facility(only for staff)\n");
		printf("Please enter your choice to see what you want:");
		scanf("%d", &choice);
		while (choice > 6 || choice < 1)
		{
			printf("Not within 1-6,please re-enter again.\n");
			printf("Please enter your choice to see what you want.");
			scanf("%d", &choice);
		}
		switch (choice)
		{
		case 1:addFunc1(); break;
		case 2:searchFunc1(); break;
		case 3:modifyFunc1(); break;
		case 4:displayFunc1(); break;
		case 5:reportFunc1(); break;
		case 6:deleteFunc1(); break;
		case 7:break;
		default:break;
		}
	} while (choice != 7);
}
void addFunc()
{
	Staff staff;
	char inf;

	FILE* fp;
	fp = fopen("staff.dat", "ab");

	if (fp == NULL)
	{
		printf("File cannot open.\n");
		exit(-1);
	}

	printf("Add New staff Information ? (Y = Yes) : ");
	rewind(stdin);
	scanf("%c", &inf);

	while (toupper(inf) == 'Y')
	{
		printf("Please Enter Staff Information : \n");
		printf("Enter Staff's Name : ");
		rewind(stdin);
		scanf("%[^\n]", &staff.Name);

		printf("\tStaff ID : ");
		rewind(stdin);
		scanf("%s", &staff.id);

		printf("\tStaff Password : ");
		rewind(stdin);
		scanf("%s", &staff.password);

		printf("\tStaff IC : ");
		scanf("%d", &staff.icNo);

		printf("\tCountry : ");
		rewind(stdin);
		scanf("%s", &staff.country);

		printf("\tAddress : ");
		rewind(stdin);
		scanf("%[^\n]", &staff.address);

		fwrite(&staff, sizeof(Staff), 1, fp);

		printf("Add staff Information ? (Y = Yes) : ");
		rewind(stdin);
		scanf("%c", &inf);
	}

	fclose(fp);
}

void displayFunc()
{
	Staff staff;
	int count = 0;

	FILE* fp;
	fp = fopen("staff.dat", "rb");

	if (fp == NULL)
	{
		printf("File cannot open.\n");
		exit(-1);
	}

	printf("\t\t\t\t\tStaff Information\n\n");
	printf("\tStaff Name\t\tStaff ID\tStaff Password\t\tStaff IC\t\tCountry\t\t\tAddress\n");
	printf("\t==========\t\t========\t==============\t\t========\t\t=======\t\t\t=======\n");

	while (fread(&staff, sizeof(Staff), 1, fp))
	{
		printf("    %15s     %15s %18s%21d       %15s  %20s\n\n\n", staff.Name, staff.id, staff.password, staff.icNo, staff.country, staff.address);
		count++;
	}
	printf("\t<%d rewords listed>\n\n", count);

	fclose(fp);
}

void modifyFunc()
{
	char ans, cont, Id[15], country[26], address[50], password[20];
	int i = 0, sCount = 0, modiCount = 0, found, IcNo;

	Staff s[20];

	FILE* fp;
	fp = fopen("staff.dat", "rb");

	if (fp == NULL)
	{
		printf("File cannot open.\n");
		exit(-1);
	}

	while (fread(&s[i], sizeof(Staff), 1, fp))
	{
		i++;
		sCount = i;
	}
	fclose(fp);

	do {
		printf("Enter staff Id to modify : ");
		rewind(stdin);
		scanf("%s", Id);

		found = 0;

		printf("\tStaff Name\t\tStaff ID\tStaff Password\t\tStaff IC\t\tCountry\t\t\tAddress\n");
		printf("\t==========\t\t========\t==============\t\t========\t\t=======\t\t\t=======\n");

		for (i = 0; i < sCount; i++)
		{
			if (strcmp(Id, s[i].id) == 0)
			{
				found = 1;
				printf("    %15s     %15s %18s%21d       %15s  %20s\n", s[i].Name, s[i].id, s[i].password, s[i].icNo, s[i].country, s[i].address);

				printf("\nNew password :");
				rewind(stdin);
				scanf("%s", password);

				printf("\nNew Country :");
				rewind(stdin);
				scanf("%s", country);

				printf("\nNew Address :");
				rewind(stdin);
				scanf("%s", address);

				printf("\nConfirm to Modify (Y=Yes) ?");
				rewind(stdin);
				scanf("%c", &ans);

				if (toupper(ans) == 'Y')
				{
					strcpy(s[i].password, password);
					strcpy(s[i].country, country);
					strcpy(s[i].address, address);
					modiCount++;
				}

				printf("Latest Staff Information :\n");
				printf("\tStaff Name\t\tStaff ID\tStaff Password\t\tStaff IC\t\tCountry\t\t\tAddress\n");
				printf("\t==========\t\t========\t==============\t\t========\t\t=======\t\t\t=======\n");
				printf("    %15s     %15s %18s%21d       %15s  %20s\n", s[i].Name, s[i].id, s[i].password, s[i].icNo, s[i].country, s[i].address);
			}
		}
		if (!found)
			printf("\nNo information found with the ID %s \n", Id);
		printf("\nModify again (Y=Yes) ?");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'Y');

	fp = fopen("staff.dat", "wb");

	for (i = 0; i < sCount; i++)
	{
		fwrite(&s[i], sizeof(Staff), 1, fp);
	}

	printf("\n\n%d staff's information(s) modified.\n\n", modiCount);

	fclose(fp);
}

void searchFunc()
{
	int i = 0, sCount = 0, count = 0, found;
	char cont, searchId[15];

	Staff s[20];

	FILE* fp;
	fp = fopen("staff.dat", "rb");

	if (fp == NULL)
	{
		printf("Cannot open the file !\n");
		exit(-1);
	}


	while (fread(&s[i], sizeof(Staff), 1, fp) == 1)
	{
		i++;
		sCount = i;
	}
	fclose(fp);

	do {
		printf("Enter the staff Id to search : ");
		rewind(stdin);
		scanf("%s", searchId);


		for (i = 0; i < sCount; i++)
		{
			if (strcmp(searchId, s[i].id) == 0)
			{
				printf("\tStaff Name\t\tStaff ID\tStaff Password\t\tStaff IC\t\tCountry\t\t\tAddress\n");
				printf("\t==========\t\t========\t==============\t\t========\t\t=======\t\t\t=======\n");
				printf("    %15s     %15s %18s%21d       %15s  %20s\n", s[i].Name, s[i].id, s[i].password, s[i].icNo, s[i].country, s[i].address);
				count++;
			}
		}
		printf("\n\t%d staff inforamtion found \n", count);

		printf("Search for another(Y = Yes) : ");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'Y');

	fclose(fp);
}

void deleteFunc()
{
	int staffCount = 0, delCount = 0;
	char comfirm;
	char delStaff[7];

	Staff staff;
	Staff del[20];
	FILE* fp;

	fp = fopen("staff.dat", "rb");

	if (fp == NULL)
	{
		printf("File cannot open.\n");
		exit(-1);
	}

	while (fread(&staff, sizeof(Staff), 1, fp))
	{
		del[staffCount] = staff;
		staffCount++;
	}

	fclose(fp);

	printf("Enter Staff's Id to delete : ");
	rewind(stdin);
	scanf("%s", delStaff);

	for (int i = 0; i < staffCount; i++)
	{
		if (strcmp(del[i].id, delStaff) == 0)
		{
			printf("Comfirm Delete (Y = Yes) ? ");
			rewind(stdin);
			scanf("%c", &comfirm);
			if (toupper(comfirm) == 'Y')
			{
				delCount++;
				for (int j = i; j < staffCount; j++)
				{
					del[j] = del[j + 1];
				}
			}
		}
	}

	fp = fopen("staff.dat", "wb");

	if (fp == NULL)
	{
		printf("File cannot open.\n");
		exit(-1);
	}

	for (int i = 0; i < (staffCount - delCount); i++)
	{
		fwrite(&del[i], sizeof(Staff), 1, fp);
	}

	fclose(fp);
}


void staffModule()
{
	int option;

	do {
		printf("\n\tFunction Menu\n");
		printf("\t=================\n");
		printf("\t1 >> Add staff\n");
		printf("\t2 >> Display staff\n");
		printf("\t3 >> Modify staff\n");
		printf("\t4 >> Search staff\n");
		printf("\t5 >> Delete staff\n");
		printf("\t6 >> Exit Program\n");

		rewind(stdin);

		printf("\n");
		printf("Enter your option : ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:addFunc(); break;
		case 2:displayFunc(); break;
		case 3:modifyFunc(); break;
		case 4:searchFunc(); break;
		case 5:deleteFunc(); break;
		case 6:break;
		default:
			printf("Invalid option !");
		}
	} while (option != 6);
}
void bookingModule()
{
	bookingmenu();
}
int validYear(int year) {
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}
int theValidDate(date* validDate) {
	if (validDate->year > 2099 ||
		validDate->year < 2000)
		return 0;
	if (validDate->month < 1 || validDate->month > 12)
		return 0;
	if (validDate->day < 1 || validDate->day > 31)
		return 0;
	if (validDate->month == 2)
	{
		if (validYear(validDate->year))
			return (validDate->day <= 29);
		else
			return (validDate->day <= 28);
	}
	if (validDate->month == 4 || validDate->month == 6 ||
		validDate->month == 9 || validDate->month == 11)
		return (validDate->month <= 30);
	return 1;
}
void bookingmenu()
{
	int bookingMenuOp;
	do
	{
		printf("\n\t MENU\n\n");
		printf("\n\t1.Add Booking Entry\n");
		printf("\n\t2.Modify Booking Records\n");
		printf("\n\t3.Search Booking Records\n");
		printf("\n\t4.Display Booking Records\n");
		printf("\n\t5.Delete Booking Records\n");
		printf("\n\t6.Exit\n\n");
		printf("\tPlease enter your choice ==> ");
		scanf("%d", &bookingMenuOp);
		switch (bookingMenuOp)
		{
		case 1:
			bookingAddNew();
			break;
		case 2:
			bookingMod();
			break;
		case 3:
			bookingSrch();
			break;
		case 4:
			bookingDis();
			break;
		case 5:
			bookingDelete();
			break;
		case 6:
			printf("\n\n\tThank you!!!\n");
			exit(1);
			break;
		default:
			printf("\n\n\tPlease retype again...\n");
		}
	} while (bookingMenuOp != 0);
}
void bookingAddNew()
{
	cusInfo CI;
	date Dt;
	BookingInfo BI;
	bookingTime BT;
	todayDate TD;
	cusInfo bookingAdd = { 0 };
	FILE* fptr = NULL;
	int status = 0;
	char choice;
	fptr = fopen("booking.txt", "w");
	if (fptr == NULL) {
		printf("cannot open the file\n");
		exit(1);
	}
	printf("\n\nAdd the new booking records: ");
	printf("\n\n===========================================================\n");
	do
	{
		printf("\n\nEnter booking id : ");
		scanf("%d", &BI.Booking_ID);
		printf("\n\nCustomer ID = ");
		scanf("%u", &bookingAdd.cus_ID);
		rewind(stdin);
		rewind(stdin);
		printf("\nPlease enter Customer Name = ");
		scanf("%[^\n]", &CI.cusName);
		rewind(stdin);
		printf("\nPlease enter Customer Phone Number = ");
		scanf("%d", &CI.cusPhoneNum);
		rewind(stdin);
		printf("\nPlease enter Customer Address = ");
		scanf("%[^\n]", &CI.cusAddr);
		rewind(stdin);
		printf("\nPlease enter Customer IC Number = ");
		scanf("%d", &CI.cusICNum);
		rewind(stdin);
		printf("\nPlease enter facility ID = ");
		scanf("%d", &BI.Facility_ID);
		rewind(stdin);
		printf("\nPrice of facilities = ");
		scanf("%f", &CI.facilitiesPrice);
		rewind(stdin);
		printf("\nBooking time (Example type format 10 10 = 10am - 10pm )= ");
		scanf("%d%d", &BT.start, &BT.end);
		rewind(stdin);
		do
		{
			printf("\nBooking Date : ");
			printf("\nPlease enter the booking date in format (dd/mm/yyyy) :");
			scanf("%d/%d/%d", &Dt.day, &Dt.month, &Dt.year);
			status = theValidDate(&Dt);
			if (status != 1)
			{
				printf("\n\nPlease enter a valid date.\n");
			}
		} while (!status);
		do
		{
			printf("\nToday date : ");
			printf("\nPlease enter the today date in format (dd/mm/yyyy) :");
			scanf("%d/%d/%d", &TD.day, &TD.month, &TD.year);
			status = theValidDate(&Dt);
			if (status != 1)
			{
				printf("\n\nPlease enter a valid date.\n");
			}
		} while (!status);
		printf("\n\tContinue? = ");
		rewind(stdin);
		scanf("%c", &choice);
	} while (toupper(choice) != 'N');
	fprintf(fptr, "%d\n%u\n%s\n%d\n%s\n%d\n%d\n%.2lf\n%d %d\n%d/%d/%d\n%d/%d/%d",
		BI.Booking_ID, bookingAdd.cus_ID, CI.cusName,
		CI.cusPhoneNum, CI.cusAddr, CI.cusICNum, BI.Facility_ID,
		CI.facilitiesPrice, BT.start, BT.end, Dt.day, Dt.month, Dt.year,
		TD.day, TD.month, TD.year);
	fclose(fptr);
	return 1;
}
void bookingMod()
{
	int status = 0;
	char choice;
	int found = 0;
	int bookingDlts = 0;
	cusInfo bookingAdd = { 0 };
	cusInfo CI;
	date Dt;
	BookingInfo BI;
	bookingTime BT;
	todayDate TD;
	FILE* fptr = NULL;
	FILE* tmpF = NULL;
	fptr = fopen("booking.txt", "r");
	if (fptr == NULL) {
		printf("File cannot open \n");
		exit(-1);
	}
	tmpF = fopen("temp.txt", "w");
	if (tmpF == NULL) {
		printf("File cannot open \n");
		exit(1);
	}
	fscanf(fptr, "%d\n%d\n", &BI.Booking_ID, &CI.cus_ID);
	printf("\n\n\tEnter the booking ID that you want to edit : ");
	scanf("%d", &bookingDlts);
	if (BI.Booking_ID != bookingDlts)
	{
		printf("No match found !");
		return 1;
	}
	else
	{
		found = 1;
	}
	if (found == 1)
	{
		printf("\n\n\tBooking record has been edited");
	}
	else
	{
		printf("\n\n\tRecord is not found");
	}
	fclose(fptr);
	fclose(tmpF);
	remove("booking.txt");
	rename("temp.txt", "booking.txt");
	fptr = fopen("booking.txt", "w");
	if (fptr == NULL) {
		printf("cannot open the file\n");
		exit(1);
	}
	printf("\n\nAdd another booking records: ");
	printf("\n\n===========================================================\n");
	do
	{
		printf("\n\nEnter new booking id : ");
		scanf("%d", &BI.Booking_ID);
		printf("\n\nEnter new Customer ID = ");
		scanf("%u", &bookingAdd.cus_ID);
		rewind(stdin);
		rewind(stdin);
		printf("\nPlease enter new Customer Name = ");
		scanf("%[^\n]", &CI.cusName);
		rewind(stdin);
		printf("\nPlease enter new Customer Phone Number = ");
		scanf("%d", &CI.cusPhoneNum);
		rewind(stdin);
		printf("\nPlease enter new Customer Address = ");
		scanf("%[^\n]", &CI.cusAddr);
		rewind(stdin);
		printf("\nPlease enter Customer IC Number = ");
		scanf("%d", &CI.cusICNum);
		rewind(stdin);
		printf("\nPlease enter new facility ID = ");
		scanf("%d", &BI.Facility_ID);
		rewind(stdin);
		printf("\nPlease enter new Price of facilities = ");
		scanf("%f", &CI.facilitiesPrice);
		rewind(stdin);
		printf("\nPlease enter new Booking time (Example type format 10 10 = 10am - 10pm) = ");
		scanf("%d%d", &BT.start, &BT.end);
		rewind(stdin);
		do
		{
			printf("\nPlease enter new Booking Date : ");
			printf("\nPlease enter the booking date in format (dd/mm/yyyy) :");
			scanf("%d/%d/%d", &Dt.day, &Dt.month, &Dt.year);
			status = theValidDate(&Dt);
			if (status != 1)
			{
				printf("\n\nPlease enter a valid date.\n");
			}
		} while (!status);
		do
		{
			printf("\nPlease enter new Today Date : ");
			printf("\nPlease enter the Today date in format (dd/mm/yyyy) :");
			scanf("%d/%d/%d", &TD.day, &TD.month, &TD.year);
			status = theValidDate(&Dt);
			if (status != 1)

			{
				printf("\n\nPlease enter a valid date.\n");
			}
		} while (!status);
		printf("\n\tContinue? = ");
		rewind(stdin);
		scanf("%c", &choice);
	} while (toupper(choice) != 'N');
	fprintf(fptr, "%d\n%u\n%s\n%d\n%s\n%d\n%d\n%.2lf\n%d %d\n%d/%d/%d\n%d/%d/%d	\n",
		BI.Booking_ID, bookingAdd.cus_ID, CI.cusName,
		CI.cusPhoneNum, CI.cusAddr, CI.cusICNum, BI.Facility_ID,
		CI.facilitiesPrice, BT.start, BT.end, Dt.day, Dt.month, Dt.year,
		TD.day, TD.month, TD.year);
	fclose(fptr);
	return 1;
}
void bookingSrch()
{
	cusInfo CI;
	date Dt;
	BookingInfo BI;
	bookingTime BT;
	todayDate TD;
	int found = 0;
	int cus_ID = 0;
	cusInfo bookingAdd = { 0 };
	FILE* fptr = NULL;
	fptr = fopen("booking.txt", "r");
	if (fptr == NULL) {
		printf("cannot open the file\n");
		exit(1);
	}
	while (fscanf(fptr, "%d", &CI.cus_ID) == EOF) {
		fclose(fptr);
		printf("\n\nFacing the issue while reading the file\n");
		exit(1);
	}
	printf("\n\nPlease Enter Customer ID to search : ");
	rewind(stdin);
	scanf("%[^\n]", &cus_ID);

	if (CI.cus_ID == cus_ID)
	{
		found = 1;
	}
	if (found = 1)
	{
		fscanf(fptr, "%d\n%d\n", &BI.Booking_ID, &CI.cus_ID);
		fscanf(fptr, "%s\n", &CI.cusName);
		fscanf(fptr, "%d\n%s\n%d\n%d\n", &CI.cusPhoneNum, &CI.cusAddr,
			&CI.cusICNum, &BI.Facility_ID);
		fscanf(fptr, "%f\n%d%d\n%d/%d/%d", &CI.facilitiesPrice, &BT.start,
			&BT.end, &Dt.day, &Dt.month, &Dt.year);
		fscanf(fptr, "\n%d/%d/%d", &TD.day, &TD.month, &TD.year);
		printf("\n\nBooking ID = %d\n", BI.Booking_ID);
		printf("\n\nCustomer ID = %u\n", CI.cus_ID);
		printf("\n\nCustomer Name = %s\n", CI.cusName);
		printf("\n\nCustomer Phone Number = %d\n", CI.cusPhoneNum);
		printf("\n\nCustomer Address = %s\n", CI.cusAddr);
		printf("\n\nCustomer IC Number = %d\n", CI.cusICNum);
		printf("\n\nFacility ID = %d\n", BI.Facility_ID);
		printf("\n\nPrice of facilities = %lf\n", CI.facilitiesPrice);
		printf("\n\nBooking time = (%dam - %dpm)\n", BT.start, BT.end);
		printf("\n\nBooking date(day/month/year) = (%d/%d/%d)\n", Dt.day,
			Dt.month, Dt.year);
		printf("\n\nToday date(day/month/year) = (%d/%d/%d)\n", TD.day,
			TD.month, TD.year);
	}
	else
	{
		printf("\n\n\tNo Record Available");
	}
	fclose(fptr);
	printf("\n\n\tPress any key to go to menu.....");
	rewind(stdin);
	getchar();
	return 1;
}
void bookingDis()
{
	cusInfo CI;
	date Dt;
	BookingInfo BI;
	bookingTime BT;
	todayDate TD;
	cusInfo bookingAdd = { 0 };
	int found = 0;
	int cus_ID = 0;
	FILE* fptr;
	int bookingDid;
	fptr = fopen("booking.txt", "r");
	if (fptr == NULL) {
		printf("File cannot open \n");
		exit(-1);
	}

	printf("Enter the booking ID that you want to display:");
	scanf("%d", &bookingDid);

	fscanf(fptr, "%d\n", &BI.Booking_ID);


	if (bookingDid == BI.Booking_ID)
	{
		fscanf(fptr, "%d\n%d\n", &BI.Booking_ID, &CI.cus_ID);
		fscanf(fptr, "%s\n", &CI.cusName);
		fscanf(fptr, "%d\n%s\n%d\n%d\n", &CI.cusPhoneNum, &CI.cusAddr,
			&CI.cusICNum, &BI.Facility_ID);
		fscanf(fptr, "%f\n%d%d\n%d/%d/%d", &CI.facilitiesPrice, &BT.start,
			&BT.end, &Dt.day, &Dt.month, &Dt.year);
		fscanf(fptr, "\n%d/%d/%d", &TD.day, &TD.month, &TD.year);
		printf("\n\nBooking ID = %d\n", BI.Booking_ID);
		printf("\n\nCustomer ID = %u\n", CI.cus_ID);
		printf("\n\nCustomer Name = %s\n", CI.cusName);
		printf("\n\nCustomer Phone Number = %d\n", CI.cusPhoneNum);
		printf("\n\nCustomer Address = %s\n", CI.cusAddr);
		printf("\n\nCustomer IC Number = %d\n", CI.cusICNum);
		printf("\n\nFacility ID = %d\n", BI.Facility_ID);
		printf("\n\nPrice of facilities = %lf\n", CI.facilitiesPrice);
		printf("\n\nBooking time = (%dam - %dpm)\n", BT.start, BT.end);
		printf("\n\nBooking date(day/month/year) = (%d/%d/%d)\n", Dt.day,
			Dt.month, Dt.year);
		printf("\n\nToday date(day/month/year) = (%d/%d/%d)\n", TD.day,
			TD.month, TD.year);
	}

	else
	{
		printf("\n\n\tNo Record Available");
	}

	fclose(fptr);
	return 0;
}
int bookingDelete()
{
	int found = 0;
	int bookingDlts = 0;
	cusInfo bookingAdd = { 0 };
	cusInfo CI;
	date Dt;
	BookingInfo BI;
	bookingTime BT;
	todayDate TD;
	FILE* fptr = NULL;
	FILE* tmpF = NULL;
	printf("Delete the booking record");
	fptr = fopen("booking.txt", "r");
	if (fptr == NULL) {
		printf("File cannot open \n");
		exit(-1);
	}
	tmpF = fopen("temp.txt", "w");
	if (tmpF == NULL) {
		printf("File cannot open \n");
		exit(1);
	}
	fscanf(fptr, "%d\n%d\n", &BI.Booking_ID, &CI.cus_ID);
	printf("\n\n\tEnter the booking id that you want to delete : ");
	scanf("%d", &bookingDlts);
	if (BI.Booking_ID != bookingDlts)
	{
		printf("No match found !");
		return 1;
	}
	else
	{
		found = 1;
	}
	if (found == 1)
	{
		printf("\n\n\tBooking record has been deleted");
	}
	else
	{
		printf("\n\n\tRecord is not found");
	}
	fclose(fptr);
	fclose(tmpF);
	remove("booking.txt");
	rename("temp.txt", "booking.txt");
	return 1;
}
void main()
{
	int choice;

	do {
		printf(" .----------------.  .----------------.  .----------------.   .----------------.  .----------------.  .----------------.  .----------------.\n ");
		printf("| .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. |\n");
		printf("| |  _________   | || |  _________   | || |   ______     | | | |     ______   | || |   _____      | || | _____  _____ | || |   ______     | |\n");
		printf("| | |  _   _  |  | || | |_   ___  |  | || |  |_   __ \   | | | |   .' ___  |  | || |  |_   _|     | || ||_   _||_   _|| || |  |_   _ \    | |\n");
		printf("| | |_/ | | \_|  | || |   | |_  \_|  | || |    | |__) |  | | | |  / .'   \_|  | || |    | |       | || |  | |    | |  | || |    | |_) |   | |\n");
		printf("| |     | |      | || |   |  _|      | || |    |  ___/   | | | |  | |         | || |    | |   _   | || |  | '    ' |  | || |    |  __'.   | |\n");
		printf("| |    _| |_     | || |  _| |_       | || |   _| |_      | | | |  \ `.___.'\  | || |   _| |__/ |  | || |   \ `--' /   | || |   _| |__) |  | |\n");
		printf("| |   |_____|    | || | |_____|      | || |  |_____|     | | | |   `._____.'  | || |  |________|  | || |    `.__.'    | || |  |_______/   | |\n");
		printf("| |              | || |              | || |              | | | |              | || |              | || |              | || |              | |\n");
		printf("| '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' |\n");
		printf(" '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------' \n");
		printf("Club facilities recreation maintaining system\n");
		printf("1.Booking module\n");
		printf("2.Facility module\n");
		printf("3.Staff Module\n");
		printf("Please enter your choice to see what you want:");
		scanf("%d", &choice);
		while (choice > 3 || choice < 1)
		{
			printf("Not within 1-3,please re-enter again.\n");
			printf("Please enter your choice to see what you want.");
			scanf("%d", &choice);
		}
		switch (choice)
		{
		case 1:bookingModule(); break;
		case 2:facilityModule(); break;
		case 3:staffModule(); break;
		case 4: break;
		}
	} while (choice != 4);

}