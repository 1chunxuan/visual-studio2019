#include <stdio.h>
#pragma warning(disable:4996)

//q1
double inchToCm(double);

double inchToCm(double inch)
{
	return(inch*2.54);
}

//q2
int dayOfWeek(int);

int dayOfWeek(int day)
{
	switch (day)
	{
	case 0:printf("Sunday\n"); break;
	case 1:printf("Monday\n"); break;
	case 2:printf("Tuesday\n"); break;
	case 3:printf("Wednesday\n"); break;
	case 4:printf("Thursday\n"); break;
	case 5:printf("Friday\n"); break;
	case 6:printf("Saturday\n"); break;
	default:printf("...Sorry,invalid day\n"); 
	}
}

//q3a
int finalMark(int prac,int cw,int exam)
{
	return(prac + cw + exam);
}

//q3b
int markIsValid(int mark, int maxMark)
{
	int valid;

	if (mark >= 0 && mark <= maxMark)
		valid = 1;
	else
		valid = 0;

	return valid;
}

//q4
char markToGrade(int mark)
{
	char grade;

	if (mark < 0 || mark>100)
		grade = 'Z';
	else if (mark >= 80)
		grade = 'A';
	else if (mark >= 65)
		grade = 'B';
	else if (mark >= 50)
		grade = 'C';
	else if (mark >= 40)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}

//q5a
void displayVehicleRate(char veh)
{
	switch (tolower(veh))
	{
	case 'c':printf("Vehicle type:CAR =>RM2.00 per hour(or part thereof)\n"); break;
	case 'b':printf("Vehicle type:BUS =>RM3.00 per hour(or part thereof)\n"); break;
	case 't':printf("Vehicle type:TRUCK =>RM4.00 per hour(or part thereof)\n"); break;
	default:printf("Vehicle type:Unknown =>RM0.00 => contact Manager\n"); 
	}
}

//q5b
char getVehicleType()
{
	char veh;

	do {
		printf("Vehicle Type: c(ar),b(us),t(ruck):");
		rewind(stdin);
		scanf("%c",&veh);
		veh = tolower(veh);
	} while (veh!='c'&&veh!='b'&&veh!='t');

	return veh;
}

//q5c
int calcHoursParked(int inHr, int inMin, int outHr, int outMin)
{
	int hrs;

	if (inHr < 7 || inHr>23 || outHr < 7 || outHr>23 || inHr > outHr || (inHr == outHr && inMin == outMin))
		return -1;

	hrs = outHr - inHr;

	if (outMin > inMin)
		hrs++;

	return hrs;
}

//q5d
int parkingCharge(char veh,int hrs)
{
	int charge;

	switch (tolower(veh))
	{
	case 'c':charge = 2 * hrs; break;
	case 'b':charge = 3 * hrs; break;
	case 't':charge = 4 * hrs; break;
	default:charge = 0;
	}
	return charge;
}

void main()
{
	////q1
	//double inch, cm;

	//printf("Enter inch:");
	//scanf("%lf",&inch);

	//cm = inchToCm(inch);

	//printf("%.2lf inches = %.2lfcentimeter\n",inch,cm);

	////q2
	//int day;
	//printf("Enter day of week(0=SUnday,6=Saturday):");
	//scanf("%d",&day);

	//while (day < 0 || day>6)
	//{
	//	printf("Day should between 0-6\n");
	//	printf("Enter day of week(0=Sunday,6=Saturday):");
	//	scanf("%d", &day);
	//}

	//printf("The day is:");
	//dayOfWeek(day);

	////q3
	//int pMark, cwMark, examMark, final;
	//char grade;////q4

	//do {
	//	printf("Practical mark should between 0-30\n");
	//	scanf("%d",&pMark);
	//} while (!markIsValid(pMark,30));

	//printf("\n");

	//do {
	//	printf("Coursework mark should between 0-20\n");
	//	scanf("%d", &cwMark);
	//} while (!markIsValid(cwMark, 20));

	//printf("\n");

	//do {
	//	printf("Exam mark should between 0-50\n");
	//	scanf("%d", &examMark);
	//} while (!markIsValid(examMark, 50));

	//printf("\n");
	//final = finalMark(pMark,cwMark,examMark);
	//markToGrade(final);////q4
	//printf("Results : Final mark = %d Grade= %c\n",final,grade);

	//q5e
	char veh;
	int inHr, inMin, outHr, outMin,hrs,charge;

	getVehicleType(veh);
	printf("Time entered car park(hh mm):");
	scanf("%d %d",inHr,inMin);
	printf("Time exited car park(hh mm):");
	scanf("%d %d", outHr, outMin);
	calcHoursParked(inHr, inMin, outHr, outMin);
	parkingCharge(veh, hrs);

	printf("===========================================\n");
	printf("Parking Ticket\n");
	displayVehicleRate(veh);
	printf("Hours parked :%d\n",hrs);
	printf("Please pay this amount ---->RM%d.00\n",charge);
	printf("Thank You & Have a Nice Day !\n");
	printf("===========================================\n");
}