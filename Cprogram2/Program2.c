/*
 * Program2.c
 *
 *  Created on: Feb 11, 2023
 *      Author: e127g344
 */
#include <stdio.h>



void scoreCalc(int score)
{
	int a,b,c,d,e,total;
	if (score==0 || score==1)
		printf("\nSTOP");
	else
	{
		for (a=0;a<9;++a)
		{
			for (b=0;b<9;++b)
			{
				for (c=0;c<9;++c)
				{
					for (d=0;d<9;++d)
					{
						for (e=0;e<9;++e)
						{
							total = a*8 + b*7 + c*6 + d*3 + e*2;
							if(total == score)
							{
								printf("%d", a);
								printf(" TD + 2pt, %d", b);
								printf(" TD + FG, %d", c);
								printf(" TD, %d", d);
								printf(" 3pt FG, %d", e);
								printf(" Safety \n");
							}
						}
					}
				}
			}
		}
	}

}

int main()
{
	int i; //General integer
	printf("Enter 0 or 1 to STOP \nEnter the NFL score: \n");
	scanf("%d", &i);


	scoreCalc(i);

	return 0;
}
