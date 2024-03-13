#include<stdio.h>
#pragma warning(disable:4996)

void main()
{
	char question[80],answer[80],response[80];
	int qNo = 1,correct=0;

	FILE* qPtr, * aPtr;

	qPtr = fopen("Questions.txt", "r");
	aPtr = fopen("Answers.txt", "r");

	if (qPtr == NULL || aPtr == NULL)
	{
		printf("Cannot open file\n");
		exit(-1);
	}

	printf("\nHello,this is a Quiz.\n\n");

	while (fscanf(qPtr, "%[^\n]\n", question) != EOF)
	{
		fscanf(aPtr, "%[^\n]\n", answer);
		printf("Q%d:  %s\n", qNo, question);
		rewind(stdin);
		scanf("%[^\n]", response);

		if (strcmp(answer, response) == 0)
		{
			printf(">>>>>CORRECT\n\n");
			correct++;
		}
		else
			printf(">>>>>WRONG,answer should be %s\n\n",answer);
		qNo++;
	}
	//display output here
	printf("Number of correct answers = %d\n", correct);
	printf("Total questions           = %d\n",--qNo);
	printf("Your score                =%.2lf%%\n",correct *100.0/qNo);

	fclose(qPtr);
	fclose(aPtr);
}