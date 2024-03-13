#include<stdio.h>
#pragma warning(disable:4996)

struct DATE {
	int day, month, year;
};

typedef struct {
	char model[10];
	struct DATE purchaseDate;
	double power;
	double price;
}CAR;

void haha()
{
	//q1a
	CAR car[10];

	//q1b
	car[9].purchaseDate.year = 2022;

	//q1c
	car[4].model = "Vios";

	//q1d
	printf("Please enter the price of cars:");
	for (int i = 0; i < 10; i++)
	{
		scanf("%lf",&car[i].price);
	}

}

void main()
{
	//q2a
	FILE* carFile, * carSelect;

	//q2b
	carFile = fopen("car.txt", "r");

	//q2c
	if (carFile == NULL)
	{
		printf("Cannot open the file\n");
		exit(-1);
	}

	//q2d
	carSelect = fopen("CarSelection.bin", "wb");

	//q2e(i)
	for (int i = 0; i < 10; i++)
	{
		fscanf(carFile,"%[^|]|%d|%d|%d|%lf|%lf\n",&carRec.model,&carRec.purchaseDate.day,&carRec.purchaseDate.month,&carRec.purchaseDate.year,&carRec.power,&carRec.price);
	}

	//q2e(ii)
	while (fscanf(carFile, "%lf", &carRec.power))
	{
		if (carRec.power > 1.5)
			fwrite(carRec.power, sizeof(carRec.power), 1, carSelect);
	}
}

char calcBmi(double kg, double m, double* bmi)
{
	char category="";
	*bmi = kg / (m * m);
	if (*bmi > 25)
		category = 'O';
	else if (*bmi > 18.5 && *bmi < 24.9)
		category = 'N';
	else if (*bmi < 18.5)
		category = 'U';

	return category;
}

void main()
{
	double kilogram, meter, bmi;
	char category1="";
	printf("Please enter your height in meter and weight in kilogram to calculate bmi:\n");
	printf("Height:");
	scanf("%lf",&meter);
	printf("Weight:");
	scanf("%lf",&kilogram);
	category1=calcBmi(kilogram, meter, &bmi);
	if (category1 == 'O')
		printf("You are overweight\n");
	else if (category1 == 'N')
		printf("You are normal\n");
	else if (category1 == 'U')
		printf("You are underweight\n");
}