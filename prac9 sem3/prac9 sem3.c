#include<stdio.h>
#pragma warning(disable:4996)

////q1a
//void getExamMark();
//void getCourseworkMark();
//void calculateFinalMark();
//void printFinalMark();
//
//int exam, coursework, final;
//
//void main()
//{
//	getExamMark(); // must be from 0 to 100
//	getCourseworkMark(); // must be from 0 to 40
//	calculateFinalMark(); // 60%*exam + coursework
//	printFinalMark(); // display final mark tidily
//}
//
//void getExamMark()
//{
//	do {
//		printf("Enter exam mark(0-100):");
//		scanf("%d",&exam);
//	} while (exam < 0 || exam>100);
//}
//
//void getCourseworkMark()
//{
//	do {
//		printf("Enter course work mark(0-40):");
//		scanf("%d", &coursework);
//	} while (coursework < 0 || coursework>40);
//}
//
//void calculateFinalMark()
//{
//	final = exam * 0.6 + coursework;
//}
//
//void printFinalMark()
//{
//	printf("\nYour final mark is %d\n",final);
//}

////q1b
//int getExamMark();
//int getCourseworkMark();
//int calculateFinalMark(int,int );
//void printFinalMark(int);
//
//void main()
//{
//	int exam, coursework, final;
//	exam = getExamMark();
//	coursework = getCourseworkMark();
//	final = calculateFinalMark( exam,  coursework);
//	printFinalMark(final);
//}
//
//int getExamMark()
//{
//	int exam;
//	do {
//		printf("Enter exam mark(0-100):");
//		scanf("%d",&exam);
//	} while (exam < 0 || exam>100);
//	return exam;
//}
//int getCourseworkMark()
//{
//	int coursework;
//	do {
//		printf("Enter course work mark(0-40):");
//		scanf("%d",&coursework);
//	} while (coursework < 0 || coursework>40);
//	return coursework;
//}
//int calculateFinalMark(int exam,int coursework)
//{
//	int final;
//	final = exam * 0.6 + coursework;
//	return final;
//}
//void printFinalMark(int final)
//{
//	printf("\nYour final mark is %d\n",final);
//}

//q2
int upgrade(int mgTest, int* cwMark)
{
	if (mgTest >= 50 && *cwMark >= 40 && *cwMark <= 49)
	{
		*cwMark += mgTest / 10;

		if (*cwMark > 50)
			*cwMark = 50;
		return 1;
	}
	else
		return 0;
}

void main()
{
	int mgMark, cwMark,isUpgraded;

	do {
		printf("Enter make good mark:");
		scanf("%d",&mgMark);
	} while (mgMark < 0 || mgMark>100);

	do {
		printf("Enter course work mark:");
		scanf("%d", &cwMark);
	} while (cwMark < 0 || cwMark>100);

	isUpgraded = upgrade(mgMark, &cwMark);

	if (isUpgraded == 1)
		printf("Your coursework mark has been upgraded to %d\n",cwMark);
	else
		printf("Your coursework mark remains as %d\n",cwMark);
}

