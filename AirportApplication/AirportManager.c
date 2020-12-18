/*
 * AirportManager.c
 *
 *  Created on: 6 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */
#include"AirportManager.h"


void initAirportManager(AirportManager* manager)
{
	manager->numOfAirports = 0;
	manager->allAirports= (Airport*)malloc(sizeof(Airport));
}

int addAirport(Airport a1, AirportManager* manager)
{
	int check = enlargeAllAirportsArray(manager);//in case of unseccefull allocate
	if(check)
		manager->allAirports[manager->numOfAirports] = a1;
	manager->numOfAirports = manager->numOfAirports + 1;
	return check;
}

int enlargeAllAirportsArray(AirportManager* manager)
{
	int newSize = manager->numOfAirports * sizeof(Airport) + sizeof(Airport);
	manager->allAirports = (Airport*)realloc(manager->allAirports, newSize);
	if(!manager->allAirports)
		return 0;
	return 1;
}

Airport* findAirportByIATA(char code[IATA_SIZE], AirportManager* m1)
{
	for(int i=0; i < m1->numOfAirports; i++)
	{
		if(checkAirportIATA(&m1->allAirports[i], code))
			return &m1->allAirports[i];
	}
	return NULL;
}


void printAllairports(const AirportManager* manager)
{
	printf("\nAll airports:\n");
	for(int i = 0; i < manager->numOfAirports; i++)
	{
		printf("%d) ", (i+1));
		printAirport(&manager->allAirports[i]);
	}
}




