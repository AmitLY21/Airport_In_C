/*
 * Flight.c
 *
 *  Created on: 3 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#include "Flight.h"

int initFlight(Flight* f1, char codeSrc[IATA_SIZE], char codeDest[IATA_SIZE])
{
	copyCode(f1->codeSrc, codeSrc);
	copyCode(f1->codeDest, codeDest);
	f1->hour = checkValidHour();
	Date* d1 = (Date*) malloc(sizeof(Date));
	if(!d1)//in case of unsuccessful allocate
		return 0;
	int check = initDate(d1);
	if(check)
		f1->date = d1;
	return check;
}

void copyCode(char code[IATA_SIZE], char codeToCpy[IATA_SIZE])
{
	for(int i = 0 ; i < IATA_SIZE ; i++)
		code[i]= codeToCpy[i];
}
/////////////////////////////////////////////////////
//checkValidDest								   //
//Aim: to check if the flight path is as the input //
//Output: 0 if equal                               //
//        1 if not                                 //
/////////////////////////////////////////////////////
int checkValidDest(Flight* f1, char codeSrc[], char codeDest[])
{
	if((strcmp(f1->codeDest, codeDest)))
		return 1;
	else if((strcmp(f1->codeSrc, codeSrc)))
		return 1;
	return 0;
}


void printFlight(const Flight* f1)
{
	printf("\nFlight from: %s , to: %s , on: ", f1->codeSrc, f1->codeDest);
	printDate(f1->date);
	printf("hour of flight: %d:00\n", f1->hour);

}

void freeFlight(Flight* f1)
{
	free(f1->date);
}

int checkValidHour()
{
	int flag = 1, hour;
	while(flag)
	{
		printf("\nEnter departure hour ");
		scanf("%d", &hour);
		if(hour > 0 && hour <= MAX_HOUR)
		{
			flag = 0;
		}
		else
			printf("\nInvalid hour\n");
	}
	return hour;
}

