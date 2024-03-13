#include <stdio.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct {
	char facId[4], types[20], description[40], venue[20];
	int maxUser, openTime, closeTime;
}Facility;

void addFunc()
{
	Facility facility;
	char reply;
	int count=0,password;
	FILE* fp;
	fp = fopen("facility.txt", "a");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}
	
	printf("Enter password to show your identity:");
	scanf("%d",&password);
	while(password != 12321)
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
		scanf("%[^\n]",&facility.facId);
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
		scanf("%c",&reply);
		count++;
	}while (toupper(reply) == 'Y');
	printf("%d records added",count);
	fclose(fp);
}

void searchFunc()
{
	Facility facility[20];
	int i=0,pCount=0,a=0;
	char reply,Id[4], ans;
	FILE* fp;
	fp = fopen("facility.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}

	while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility[i].facId, &facility[i].types, &facility[i].description, &facility[i].venue, &facility[i].maxUser, &facility[i].openTime, &facility[i].closeTime) !=EOF)
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
				printf("%-4s\t%-20s\t%-30s\t-20s\t%02d\t%04d\t%04d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
			}
		}
		printf("\nAny more records to search(y=yes)?");
		rewind(stdin);
		scanf("%c", &reply);
	} while (toupper(reply) == 'Y');
	
	fclose(fp);
}

void modifyFunc()
{
	Facility facility[20];
	int a=0, pCount=0,modiCount=0,password, i=0, UpdOpenTime, UpdCloseTime,found=0,maxUser,opTime,cloTime;
	char ans,updId,Id[4], cont,types[20],description[40],venue[20];
	FILE* fp;
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
	printf("\nEnter the facility's type:");
	rewind(stdin);
	scanf("%[^\n]",&types);
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
	scanf("%d", &cloTime);
	do {
		for (i = 0; i <= pCount; i++)
		{
			if (strcmp(Id, facility[i].facId)==0&& strcmp(types, facility[i].types) == 0&& strcmp(description, facility[i].description&& strcmp(venue, facility[i].venue) == 0&& facility[i].maxUser==maxUser&& facility[i].openTime==opTime&& facility[i].closeTime==cloTime)!=EOF)
			{
				printf("%-4s\t%-20s\t%-30s\t-20s\t%02d\t%04d\t%04d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
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
				}

				printf("\nUpdated Record\n");
				printf("\tId\tTypes\tDescription\tVenue\tMaximum Allowable User\tOpen Time\tCLose Time\n");
				printf("\t==\t=====\t===========\t=====\t======================\t=========\t==========\n");
				printf("%-4s\t%-20s\t%-30s\t-20s\t%02d\t%04d\t%04d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
			}
		}
		printf("\nAny more records to modify(y=yes)?");
		rewind(stdin);
		scanf("%c", &cont);
	}while (toupper(cont)=='Y');

	if (!found)//found=0
	{
		printf("\no product match the code %s\n", Id);
	}

	printf("\n%d record(s) modified\n", modiCount);
	fclose(fp);
}

void displayFunc()
{
	Facility facility;
	FILE* fp;
	fp = fopen("facility.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}
	printf("\tId\tTypes\tDescription\tVenue\tMaximum Allowable User\tOpen Time\tCLose Time\n");
	printf("\t==\t=====\t===========\t=====\t======================\t=========\t==========\n");
	while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility.facId, &facility.types, &facility.description, &facility.venue, &facility.maxUser, &facility.openTime, &facility.closeTime) != EOF)
	{
		printf("%-4s\t%-20s\t%-30s\t%s\t%02d\t%04d\t%04d\n",facility.facId,facility.types,facility.description,facility.venue,facility.maxUser,facility.openTime,facility.closeTime);
	}
	fclose(fp);
}

void reportFunc()
{
	char reports = "",reply;
	do {
		printf("Please enter your problems:");
		rewind(stdin);
		scanf("%[^\n]",&reports);

		printf("If do not want to continue,enter N:");
		rewind(stdin);
		scanf("%c", &reply);
	} while (toupper(reply=='Y'));
}

void deleteFunc()
{
	Facility facility[20];
	int i=0,UpdOpenTime, UpdCloseTime,deleteCount=0,pCount=0,a=0;
	char ans,Id[4], cont;
	FILE* fp;
	fp = fopen("facility.txt", "r");
	if (fp == NULL)
	{
		printf("File not found!\n");
		exit(-1);
	}
	printf("Enter the Id to show the information of the facility:");
	rewind(stdin);
	scanf("%s",&Id);
	
	while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%d|%d|%d\n", &facility[i].facId,&facility[i].types,&facility[i].description,&facility[i].venue,&facility[i].maxUser,&facility[i].openTime,&facility[i].closeTime) != EOF)
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
				printf("%-4s\t%-20s\t%-30s\t-20s\t%02d\t%04d\t%04d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
				printf("\nConfirm to delete(Y=yes)?");
				rewind(stdin);
				scanf("%c", &ans);

				if (toupper(ans) == 'Y')
				{
					strcpy(facility[i].facId, "");
					strcpy(facility[i].types, "");
					strcpy(facility[i].description, "");
					strcpy(facility[i].venue, "");
					facility[i].maxUser = "";
					facility[i].openTime = "";
					facility[i].closeTime = "";
					deleteCount++;
				}
			}
		}
		
		printf("\nAny more records to delete(y=yes)?");
		rewind(stdin);
		scanf("%c", &cont);
	}while (toupper(cont) == 'Y');
	
	fclose(fp);
}

void main()
{
	int choice;
	do {
	printf("Facility Module\n");
	printf("1.Add facility(only for staff)\n");
	printf("2.Search facility\n");
	printf("3.Modify facility(only for staff)\n");
	printf("4.Display all facility\n");
	printf("5.Report the facility due to some problems\n");
	printf("6.Delete a facility(only for staff)\n");
	printf("Please enter your choice to see what you want:");
	scanf("%d",&choice);
	while (choice > 6 || choice < 1)
	{
		printf("Not within 1-6,please re-enter again.\n");
		printf("Please enter your choice to see what you want.");
		scanf("%d", &choice);
	}
	switch (choice)
	{
	case 1:addFunc(); break;
	case 2:searchFunc(); break;
	case 3:modifyFunc(); break;
	case 4:displayFunc(); break;
	case 5:reportFunc(); break;
	case 6:deleteFunc(); break;
	case 7:break;
	default:break;
	}
	}while (choice != 7);
}


