/*
 * Airport.h
 *
 *  Created on: 1 Dec 2020
 * Authors:
 *   Gal Shamir 208613356
 *   Amit Levy 206841496
 */

#ifndef AIRPORT_H_
#define AIRPORT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringUtill.h"
#define IATA_SIZE 4//because null terminator string

typedef struct {
	char* name;
	char* state;
	char codeIATA[IATA_SIZE];
}Airport;

int initAirPort(Airport* a1);

void printAirport(const Airport* a1);

int equalsAirportsByIATA(Airport* a1, Airport* a2);

int checkAirportIATA(Airport* a1, char code[IATA_SIZE]);

char* getIATA(char* checkInputIATA);

void freeAirport(Airport* a1);

#endif /* AIRPORT_H_ */
