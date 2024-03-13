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
	} while (toupper(reply) == 'Y');
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
	FILE* fp, * fp1;
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
				fprintf(fp, "%s|%s|%s|%s|%d|%d|%d\n", facility[i].facId, facility[i].types, facility[i].description, facility[i].venue, facility[i].maxUser, facility[i].openTime, facility[i].closeTime);
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

	if (found == 0)
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

		fprintf(fptr, "%s\n", reports);

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