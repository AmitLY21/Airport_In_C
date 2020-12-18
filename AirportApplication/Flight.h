/*
 * Flight.h
 *
 *  Created on: 1 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Airport.h"
#include "AirportManager.h"
#include "Date.h"

#define MAX_HOUR 23

typedef struct{
	char codeSrc [IATA_SIZE];
	char codeDest [IATA_SIZE];
	int hour;
	Date* date;
}Flight;

int initFlight(Flight* f1, char codeSrc[IATA_SIZE], char codeDest[IATA_SIZE]);

int checkValidDest(Flight* f1, char codeSrc[], char codeDest[]);

void copyCode(char code[IATA_SIZE], char codeToCpy[IATA_SIZE]);

void printFlight(const Flight* f1);

void freeFlight(Flight* f1);

int checkValidHour();

#endif /* FLIGHT_H_ */
