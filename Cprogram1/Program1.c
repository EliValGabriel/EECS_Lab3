/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: e127g344
 */
#include <stdio.h>

int i;

void reportPrinter(char months[12][12], float input[12])
{
	//for loop prints the sales and months
	printf("Months \t\tSales\n\n");
	for (i=0; i<12; ++i)
	{
		printf("%s \t\t", months[i]);
		printf("$%5.2f \n", input[i]);
	}
}

void salesSumm(char months[12][12], float input[12])
{
	float average = 0;
	float max = 0;
	float min = 0;
	int x=0;
	char maxMonth[12];
	char minMonth[12];

	printf("\nSales summary: \n");
	for (i=0; i<12; ++i)
	{
		if (input[i]>max)
		{
			max = input[i];
			for(x=0; x<12; ++x)
			{
				maxMonth[x]=months[i][x];
			}
		}
		if (min == 0)
		{
			min = input[i];
			for(x=0; x<12; ++x)
			{
				minMonth[x]=months[i][x];
			}
		}
		else if(input[i]<min)
		{
			min = input[i];
			for(x=0; x<12; ++x)
			{
				minMonth[x]=months[i][x];
			}
		}
		average += input[i];
	}
	average = average/12;
	printf("\nMinimum Sales: $%5.2f", min);
	printf("  (%s", minMonth);
	printf("\nMaximum Sales: $%5.2f", max);
	printf("  (%s", maxMonth);
	printf("\nAverage Sales: $%5.2f", average);
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void sixMonth(char months[12][12], float input[12])
{
	float average = 0;
	int x;
	printf("\n\nSix-Month Moving Average Report:\n\n");
	for (i=0; i<7; ++i)
	{
		average = 0;
		printf(months[i]);
		printf(" - %s", months[i+5]);
		for (x=0; x<6; ++x)
		{
			average += input[x+i];
		}
		average = average/6;
		printf("\t\t$%5.2f", average);
		printf("\n");
	}

}

void highLow(char months[12][12], float input[12])
{
	int y,j;
	float new[12];
	for (i=0; i<12; ++i)
	{
		new[i]=input[i];
	}

	for (y=0; y < 12; y++)
	{
		for (j=0; j<12; j++)
			if (new[j] < new[j+1])
				swap(&new[j], &new[j+1]);
	}


	printf("\nSales Report (Highest to Lowest):\nMonth\tSales\n\n");
	for (i=0; i<12; ++i)
	{
		printf("$%5.2f \n", new[i]);
	}

}

int main()
{

	FILE* input = fopen("sales.txt", "r"); //reads the sales.txt file
	FILE* months = fopen("months.txt", "r"); //reads the months.txt file

	char monthArray[12][12];
	float saleArray[12]={1,2,3,4,5,6,7,8,9,10,11,12};

	//Two if statements below run if the files are empty
	if (input == NULL)
	{
		printf("File can't be opened\n");
		exit(0);
	}
	if (months == NULL)
	{
		printf("File can't be opened\n");
		exit(0);
	}

	//for loop adds to the saleArray and monthArray with i used as the counter
	for (i=0; i<12; i++)
	{
		fscanf(input, "%f", &saleArray[i]);
		fscanf(months, "%10s", &monthArray[i]);
	}

	reportPrinter(monthArray,saleArray);
	salesSumm(monthArray,saleArray);
	sixMonth(monthArray,saleArray);
	highLow(monthArray,saleArray);


	fclose(input);
	fclose(months);

	return 0;
}
