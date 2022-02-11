#include<stdio.h>
#include"calendar.h"
int Day(int year)
{
	int result;
	result = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) +
	((year) / 400) + 1) % 7;
	return result;
}
void printa(int t)
{
	for(int i = 0; i < t; i++)
	{
		printf("$");
	}
}

int main()
{
	char *mon[] = {" ", "Janurary", "Feburary", "March", "April", "May","June","July", "August", "September", "October", "Novemeber", "Decemeber"};
	char *days[] = {" ", "Sun", "Mon", "Tue", "Wed", "Thu","Fri", "Sat"};
  int DaysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	printf("Enter a year: ");
	int Year;
	scanf("%d", &Year);


	if (Year <= 0)
	{
		printf("enter the valid year");
		scanf("%d", &Year);
	}

	if((Year % 400 == 0 && Year % 100 == 0) || Year % 4 == 0)
	{
		printf("Yes it is a leap year.\n");
		DaysOfMonth[2] = DaysOfMonth[2] + 1;
	}else
	{
		printf("No it is not a leap year.\n");
	}
int Week = Day(Year);
for(int months = 1; months <= 12; months++)
	{
		int fhalf, shalf;
		int length = strlen(mon[months]);
		int t = 63 - length;
		int startDay;
		if(t % 2 != 0 )
		{
			fhalf = (t / 2) + 1;
		}else
		{
			fhalf = (t / 2);
		}
		shalf = t / 2;

		printf("\n\n");
		printa(fhalf);
		printf("%s", mon[months]);
		printa(shalf);
		printf("\n");
     	for(int day = 1; day <=7; day++)
		{
			printf("%s       ", days[day]);
		}

		printf("\n");
		for(startDay = 0; startDay < Week; startDay++)
		{
			if(startDay == 0)
			{
				printf("  ");
			}else
			{
			printf("          ");
		  }
		}

		for(int days = 1; days <= DaysOfMonth[months]; days++)
		{
			if(Week == 0)
			{
				printf(" %d", days);
				Week++;
			}else
			{
			if(days == 10)
			{
				printf("%11d", days);
			}else
			{
			printf("%10d", days);
		  }
			Week++;
			}
			if(Week == 7)
			{
				printf("\n");
				Week = 0;
			}
			startDay = Week;
		}
		printf("\n");
	}
	return 0;
}
