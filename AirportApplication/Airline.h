/*
 * Airline.h
 *
 *  Created on: 1 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#ifndef AIRLINE_H_
#define AIRLINE_H_
#include <stdio.h>
#include <stdlib.h>
#include "Airport.h"
#include "stringUtill.h"
#include "Flight.h"

typedef struct{
	char* name;
	int numOfFlights;
	Flight** allAirlineFlights;
}Airline;

int initAirline(Airline* a1);

int addFlight(Flight* f1, Airline* a1);

int checkFlightsRoute(Flight** f1, int size, char codeSrc[], char codeDest[]);

void printAirline(const Airline* airline);

void freeAirline(Airline* a1);

#endif /* AIRLINE_H_ */
