/*
 * Airline.c
 *
 *  Created on: 6 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#include "Airline.h"

int initAirline(Airline* a1)
{
	a1->numOfFlights = 0;
	printf("\nEnter airline name:");
	a1->name = (char*)malloc(MAX_LENGTH * sizeof(char));
	if(!a1->name)
		return 0;
	fgets(a1->name , MAX_LENGTH , stdin);
	a1->name=getstrExactLength(a1->name);
	*(a1->name + strcspn(a1->name , "\n")) = '\0';//replace to null terminator string
	return 1;
}

int addFlight(Flight* f1, Airline* a1)
{
	if(a1->numOfFlights == 0)
	{
		a1->allAirlineFlights = (Flight**)malloc(sizeof(Flight*));
		if(!a1->allAirlineFlights)
			return 0;
	}
	else
	{
	int newSize = (a1->numOfFlights + 1) * sizeof(Flight*);
	a1->allAirlineFlights = (Flight**)realloc(a1->allAirlineFlights, newSize);
	}
	a1->allAirlineFlights[a1->numOfFlights] = f1;
	a1->numOfFlights = a1->numOfFlights+1;
	return 1;
}

void printAirline(const Airline* airline)
{
	printf("\nAirline name: %s, Flights:", airline->name);
	for(int i = 0; i < airline->numOfFlights; i++)
		printFlight(airline->allAirlineFlights[i]);
}


int checkFlightsRoute(Flight** f1, int size, char codeSrc[], char codeDest[])
{
	int count = 0;
	for(int i = 0 ; i < size; i++)
	{
		if(checkValidDest(f1[i], codeSrc, codeDest) == 0)
			count++;
	}
	return count;
}

void freeAirline(Airline* a1)
{
	for(int i = 0; i < a1->numOfFlights; i++)
		freeFlight(a1->allAirlineFlights[i]);
}

