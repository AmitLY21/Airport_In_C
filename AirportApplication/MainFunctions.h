/*
 * MainFunctions.h
 *
 *  Created on: 7 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#ifndef MAINFUNCTIONS_H_
#define MAINFUNCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Airline.h"
#include "AirportManager.h"
#include "Airport.h"

void addFlightToAirline(Airline* airline, AirportManager* manager);

void addAirportToManager(AirportManager* manager);

void numberOfFlightOnRoute(Airline* airline, AirportManager* manager);

int checkValidSrcDest(Airport* airportSrc, Airport* airportDest);

int getSrcDestFromUser(char codeSrc[IATA_SIZE], char codeDest[IATA_SIZE], AirportManager* manager);

void freeAll(Airline* airline, AirportManager* manager);

#endif /* MAINFUNCTIONS_H_ */
