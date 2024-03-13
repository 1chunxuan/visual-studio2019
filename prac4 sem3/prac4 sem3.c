#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct
{
	char name[25], gender, playerType, countryCode[5];
	int ranking;
}Player;

//q1
void addRecords()
{
	Player p;
	int i;

	FILE* fp;

	fp = fopen("badmintonPlayers.txt", "w");

	if (fp == NULL)
	{
		printf("file open error\n");
		exit(-1);
	}

	printf("Enter 5 players' details:\n");

	for (i = 1; i <= 5; i++)
	{
		printf("Player Number %d\n", i);

		printf("Name:");
		rewind(stdin);
		scanf("%[^\n]", p.name);
		printf("Gender:");
		rewind(stdin);
		scanf("%c", &p.gender);
		printf("Player type:");
		rewind(stdin);
		scanf("%c", &p.playerType);
		printf("Country code:");
		rewind(stdin);
		scanf("%s", p.countryCode);
		printf("Ranking:");
		scanf("%d", &p.ranking);

		fprintf(fp, "%s|%c|%c|%s|%d\n", p.name, p.gender, p.playerType, p.countryCode, p.ranking);

		fclose(fp);
	}
}

//q2
void displayRecords()
{
	Player p;
	char gameType[20];
	int count = 0;

	FILE* fp;

	fp = fopen("badmintonPlayers.txt", "r");

	if (fp == NULL)
	{
		printf("file open error\n");
		exit(-1);
	}

	printf("List of players\n");
	printf("Name\t\tGender\tCountry\tGame type\tRanking\n");
	printf("-----------------------------------------------\n");

	while (fscanf(fp, "%[^|]|%c|%c|%[^|]|%d\n", p.name, &p.gender, &p.playerType, &p.countryCode, &p.ranking) != EOF)
	{
		if (toupper(p.playerType) == 'X')
			strcpy(gameType, "Mixed Double");
		else
		{
			if (toupper(p.gender) == 'M')
				strcat(gameType, "Men's");
			else if (toupper(p.gender) == 'F')
				strcat(gameType, "Women's");
			else
				strcat(gameType, "???");

			if (toupper(p.playerType) == 'S')
				strcat(gameType, "Singles");
			else if (toupper(p.playerType) == 'D')
				strcat(gameType, "Doubles");
		}
		count++;
		printf("%-25s %c %-5s  %-20s %d",p.name,p.gender,p.countryCode,gameType,p.ranking);

		strcpy(gameType, "");//to refresh gameType
	}
	printf("-----------------------------------------------\n");
	printf("%d player(s) listed\n", count);

	fclose(fp);
}

//q1(ii) havent done
void main()
{
	addRecords();
	/*displayRecords();*/
}



