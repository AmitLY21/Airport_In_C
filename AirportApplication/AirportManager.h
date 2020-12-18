/*
 * AirportManager.h
 *
 *  Created on: 1 Dec 2020
 *  *  Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#ifndef AIRPORTMANAGER_H_
#define AIRPORTMANAGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Airport.h"

#define MIN_NUM_AIRPORT 2

typedef struct{
	int numOfAirports;
	Airport* allAirports;
}AirportManager;

void initAirportManager(AirportManager* manager);

int addAirport(Airport a1, AirportManager* manager);

Airport* findAirportByIATA(char code[IATA_SIZE], AirportManager* m1);

void printAllairports(const AirportManager* manager);

int enlargeAllAirportsArray(AirportManager* manager);

#endif /* AIRPORTMANAGER_H_ */
