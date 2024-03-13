#include <stdio.h>
#pragma warning(disable:4996)
#include <Windows.h>

typedef struct {
	char code[6];
	int expiryYear;
	char country[26];
}Product;

void addRecords()//q1
{
	Product prod;
	char ans;

	FILE* fp;
	fp = fopen("product.dat", "ab");

	printf("Add records(Y=yes)?");
	rewind(stdin);
	scanf("%c", &ans);

	while (toupper(ans) == 'Y')
	{
		printf("Enter product details:\n");
		printf("\tCode:");
		rewind(stdin);
		scanf("%s",&prod.code);
		printf("\tExpiry date:");
		rewind(stdin);
		scanf("%d", &prod.expiryYear);
		printf("\tCountry:");
		rewind(stdin);
		scanf("%s", &prod.country);

		fwrite(&prod, sizeof(Product), 1, fp);

		printf("Add records(Y=yes)?");
		rewind(stdin);
		scanf("%c", &ans);
    }
	fclose(fp);
}

//q2(i)
void displayProducts()
{
	Product prod;
	int count = 0;
	SYSTEMTIME t;

	FILE* fp;
	fp = fopen("product.dat", "rb");

	GetLocalTime(&t);

	printf("\t\tProducts details - as at %d-%d-%d %02d:%02d\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
	printf("\tProduct Code\tExpiry Date\tCountry\n");
	printf("\t============\t===========\t=======\n");

	while (fread(&prod, sizeof(Product), 1, fp))
	{
		printf("\t%-18s %-10d %-26s \n", prod.code, prod.expiryYear, prod.country); 
		count++;
	}
	printf("\n\t< %d products listed >\n",count);

	fclose(fp);
}

void modifyProducts()
{
	Product p[20];
	char ans, cont, prodCode[6], country[26];
	int i = 0, updYear, pCount, modiCount = 0, found;

	FILE* fp;
	fp = fopen("product.dat", "rb");

	while (fread(&p[i], sizeof(Product), 1,fp))
	{
		i++;
		pCount = i;
	}
	fclose(fp);

	do {
		printf("\nEnter the product code to be modified");
		rewind(stdin);
		scanf("%s",&prodCode);

		found = 0;//no record match yet

		printf("\tProduct Code\tExpiry Date\tCountry\n");
		printf("\t============\t===========\t=======\n");

		for (i = 0; i < pCount; i++)
		{
			if (strcmp(prodCode,p[i].code)==0)
			{
				found = 1;//record match

				printf("\t%-18s %-10d %-26s \n", p[i].code, p[i].expiryYear, p[i].country);

				printf("\nUpdated year:");
				scanf("%d", &updYear);
				printf("Updated country:");
				rewind(stdin);
				scanf("[^\n]", country);

				printf("\nConfirm to modify(Y=yes)?");
				rewind(stdin);
				scanf("%c", &ans);

				if (toupper(ans) == 'Y')
				{
					p[i].expiryYear = updYear;
					strcpy(p[i].country, country);
					modiCount++;
				}
				printf("\nUpdated Record");
				printf("\tProduct Code\tExpiry Date\tCountry\n");
				printf("\t============\t===========\t=======\n");
				printf("\t%-18s %-10d %-26s\n", p[i].code, p[i].expiryYear, p[i].country);
			}
		}
		if (!found)//found=0
		{
			printf("\no product match the code %s\n", prodCode);
		}

		printf("\nAny more records to modify(y=yes)?");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'Y');

	fp = fopen("product.dat", "wb");
	for (i = 0; i < pCount; i++)
	{
		fwrite(&p[i], sizeof(Product), 1, fp);
	}

	printf("\n%d record(s) modified\n", modiCount);

}
void main()
{
	/*addRecords();*/
	/*displayProducts();*/

	int option;
	do {
		printf("\n\t\tPRODUCT menu\n");
		printf("\t1->Display Product Details\n");
		printf("\t2->add product\n");
		printf("\t3->Modify Product\n");
		printf("\t4->Exit\n");

		printf("Enter your option");
		scanf("%d", &option);

		switch (option)
		{
		case 1:displayProducts(); break;
		case 2:addRecords(); break;
		case 3:modifyProducts(); break;
		case 4:break;
		default:printf("Invalid Option!");
		}
	} while (option != 4); 
}

