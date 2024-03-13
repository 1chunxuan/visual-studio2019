#include<stdio.h>
#pragma warning(disable:4996)
#define PI 3.14159
//q1
void displaySquaresCubes()
{
	int i, square, cube;

	printf("NUMBER\tSQUARE\tCUBE\n");
	printf("======\t======\t====\n");

	for (i = 1; 1 <= 10; i++)
	{
		square = i * i;
		cube = i * i * i;

		printf("%d\t%d\t%d\n",i,square,cube);
	}
}

//q2
void doTriangleArea()
{
	int a, b;
	double area;

	printf("Enter side A:");
	scanf("%d",&a);
	printf("Enter side B:");
	scanf("%d", &b);

	area = 0.5 * a * b;

	printf("\nThe area of triangle is %.2lf",area);
}

//q3
void displayCircleInfo()
{
	double radius, diameter, area, circum;

	printf("Enter radius:");
	scanf("%lf", &radius);

	diameter = 2 * radius;
	circum = 2 * PI * radius;
	area = PI * radius * radius;

	printf("Diameter is %.2lf\n", diameter);
	printf("Circumference is %.2lf\n", circum);
	printf("Area is %.2lf\n", area);
}

//q3b

//q4
void displayCinemaMenu()
{
	printf("\tCINEMA menu\n");
	printf("1.Book a ticket\n");
	printf("2.Display seat layout\n");
	printf("3.Exit\n");
	printf("\nChoose an option:\n");
}

void bookATicket()
{
	printf("Book A Ticket -> Under construction\n");
}
void displaySeatLayout()
{
	printf("Display Seat Layout -> Under construction\n");
}

//q5a
int getValidMark()
{
	int mark;

	printf("Key in the mark(0-100):");
	scanf("%d",&mark);

	while (mark < 0 || mark>100)
	{
		printf("Mark must between 0 and 100\n");
		printf("Key in the mark(0-100):");
		scanf("%d", &mark);
	}

	return mark;
}

//q6
double triangleArea()
{
	int a, b;
	double area;

	printf("Enter side A:");
	scanf("%d", &a);
	printf("Enter side B:");
	scanf("%d", &b);

	area = 0.5 * a * b;

	return area;
}


void main()
{
	//void displaySquaresCubes();//q1

	//q4
	/*int option;
	
	do {
		void displayCinemaMenu();
		scanf("%d",&option);

		switch (option)
		{
		case 1:bookATicket(); break;
		case 2:displaySeatLayout; break;
		case 3:printf("Have a nice day!\n"); break;
		default:printf("Invalid option!"); break;
		}
	} while (option != 3);*/

	////q5&5b
	//int pcdMark;

	//pcdMark = getValidMark();

	//if (pcdMark >= 50)
	//	printf("--->PASS\n");
	//else
	//	printf("--->FAIL\n");

	//q6
	double area;

	area = triangleArea();

	printf("The 1st area=%.2lf\n\n",area);
	printf("The 1st area=%.2lf\n\n",triangleArea());
}