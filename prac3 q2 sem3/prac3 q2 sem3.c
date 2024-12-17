#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void main()
{
	int char_count = 0,letter_count=0,vowel_count=0,consonant_count=0,blank_count=0;
	char ch;

	FILE* fptr;
	fptr = fopen("text.txt", "r");

	if (fptr == NULL)
	{
		printf("File error.cannot open text.txt.\n");
		exit(-1);
	}

	while (fscanf(fptr, "%c", &ch) != EOF)
	{
		char_count++;

		if (ch ==' ')
		{
			blank_count++;
		}
		else
		{
			ch = toupper(ch);

			if (isalpha(ch))
			{
				letter_count++;

				if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
				{
					vowel_count++;
				}
				else 
				{
					consonant_count++;
				}
			}
		}
	}
	printf("Total numbers of character :%d\n", char_count);
	printf("Number of letters          :%d\n", letter_count);
	printf("Number of vowels           :%d\n",vowel_count);
	printf("Number of consonants       :%d\n",consonant_count);
	printf("Number of blank spaces     :%d\n",blank_count);
	printf("Number of words            :%d\n", blank_count + 1);

	fclose(fptr);
}