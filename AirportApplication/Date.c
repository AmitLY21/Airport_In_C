/*
 * Date.c
 *
 *  Created on: 1 Dec 2020
 *   *  Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */
#include "Date.h"

const int months [] = {31,28,31,30,31,30,31,31,30,31,30,31};

int initDate(Date* d1)
{
	char* date;
	int flag = 1;
	while(flag)
	{
		date = (char*)malloc(MAX_LENGTH * sizeof(char));
		printf("\nEnter Date (dd/mm/yyyy):\n");
		scanf("%s", date);
		date = strtok(date, "/");
		//days
		int days = atoi(date);
		date = strtok(NULL, "/");
		//month
		int month = atoi(date);
		date = strtok(NULL, "/");
		//year
		int year = atoi(date);
		date = strtok(NULL, "/");
		if(checkValidDate(days, month, year))
		{
			d1->day = days;
			d1->month = month;
			d1->year = year;
			flag = 0;
			return 1;
		}
		printf("\nInvalid date\n");
	}
	return 0;
}

void printDate(const Date* d1)
{
	printf("Date: %d/%d/%d ", d1->day, d1->month, d1->year);
}

int checkValidDate(int days, int month, int year)
{
	if(year < CURRENT_YEAR || year > MAX_YEAR)
		return 0;
	if(month <= 0 || month > 12)
		return 0;
	if(days > months[month -1] || days <= 0)
		return 0;
	return 1;
}


