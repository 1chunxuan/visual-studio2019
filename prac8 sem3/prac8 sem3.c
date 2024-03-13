#include<stdio.h>
#pragma warning(disable:4996)
#include<math.h>
#include<stdlib.h>
#define PI 3.14159
#define THISYEAR 2022
#define THISMONTH 3

//q1
void diameterAreaCircum(double r,double *d,double *a,double *c)
{
	*d = 2 * r;
	*a = PI * r * r;
	*c = 2 * PI * r;
}

//q2
void rootsFx(double a,double b,double c,double *x1,double *x2)
{
	*x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	*x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

//q3a
int bigger(int x,int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int smaller(int x,int y)
{
	if (x < y)
		return x;
	else
		return y;
}

//q3b
void hiLo(int x, int y, int z, int* highest, int* lowest)
{
	if (z > bigger(x, y))
		*highest = z;
	else
		*highest = bigger(x, y);

	if (z < smaller(x, y))
		*lowest = z;
	else
		*lowest=(smaller(x, y));
}

//q4
void convertTime(int secs, int* hr, int* min, int* sec)
{
	*hr = secs / 3600;
	*min = secs % 3600 / 60;
	*sec = secs % 60;
}

//q5
void getGradeAndGp(char* grade, int* gp)
{
	printf("Enter grade for the subject:");
	rewind(stdin);
	scanf("%c",grade);
	*grade = toupper(*grade);

	while (*grade != 'A' && *grade != 'B' && *grade != 'C' && *grade != 'D' && *grade != 'F' && *grade != 'X')
	{
		printf("Enter grade for the subject:");
		rewind(stdin);
		scanf("%c", grade);
		*grade = toupper(*grade);
	}
	switch (*grade)
	{
	    case 'A':*gp = 4; break;
		case 'B':*gp = 3; break;
		case 'c':*gp = 2; break;
		case 'D':*gp = 1; break;
		case 'F':
		case 'X':
			*gp = 0; break;
		default:*gp = -1;
	}
}

//q6
void age(int monthBorn, int yearBorn, int* ageYrs, int* ageMths)
{
	*ageYrs = THISYEAR - yearBorn;

	if (THISMONTH > monthBorn)
		*ageMths = THISMONTH - monthBorn;
	else
	{
		(*ageYrs)--;
		*ageMths = 12 + THISMONTH - monthBorn;
	}
}

//q7
void additionQuiz(int level, int* correct, double* score)
{
	int x, y, ans;
	*correct = 0;
	for (int i = 1; i <= 5;i++)
	{
		x = rand() % (level * 20) + 1;
		y = rand() % (level * 20) + 1;

		printf("Q%d: %d + %d =",i,x,y);
		scanf("%d",&ans);

		if (ans == (x + y))
		{
			printf("Correct!\n");
			(*correct)++;
		}
		else
			printf("Wrong!\n");
	}
	*score = *correct / 5.0;
}

void main()
{
	////q1
	//double radius,diameter,area,circumference;
	//printf("Enter the radius:");
	//scanf("%lf",&radius);
	//diameterAreaCircum(radius, &diameter, &area, &circumference);
	//printf("\nDiameter=%.2lf",diameter);
	//printf("\nArea=%.2lf",area);
	//printf("\nCircumference=%.2lf",circumference);

	////q2
	//double a = 2, b = 5, c = -3, x1, x2;
	//rootsFx(a, b, c, &x1, &x2);

	//printf("THe roots are %.2lf and %.2lf\n",x1,x2);

	////q3c
	//int x = 2, y = 10, z = 4,hi,lo;
	//hiLo(x, y, z, &hi, &lo);
	//printf("Highest=%d\n",hi);
	//printf("Lowest=%d\n",lo);

	////q4
	//int seconds,hour,minute,sec;
	//printf("Enter seconds:");
	//scanf("%d",&seconds);
	//convertTime(seconds, &hour, &minute, &sec);
	//printf("%d %d %d\n",hour,minute,sec);
	//printf("%d seconds =%d hr %d min %d sec",seconds,hour,minute,sec);

	////q5
	//int creditHour, qp, gp;
	//char grade;

	//printf("Enter the credit hour:");
	//scanf("%d",&creditHour);

	//getGradeAndGp(&grade, &gp);

	//qp = creditHour * gp;
	//printf("\nYour quality point is %d\n",qp);

	////q6
	//int dobMonth, dobYear,year,month;
	//printf("Enter month of birth:");
	//scanf("%d",&dobMonth);
	//printf("Enter year of birth:");
	//scanf("%d", &dobYear);
	//age(dobMonth,dobYear,&year,&month);

	//printf("Your age is %d yrs %d mths\n",year,month);

	//q7
	int level, correct;
	double score;

	printf("Good day,Welcome to Addition Quiz!\n\n");
	printf("Enter level:");
	scanf("%d",&level);

	additionQuiz(level, &correct, &score);

	printf("You got %d out of 5 questions.\n",correct);
	printf("Your score: %.0lf%%\n\n",score*100);
}