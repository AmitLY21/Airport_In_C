/*
 * stringUtill.h
 *
 *  Created on: 3 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#ifndef STRINGUTILL_H_
#define STRINGUTILL_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Airport.h"

#define MAX_LENGTH 255

char* getstrExactLength(char* temp);

char* fixAirportName(char* name);

char* fixEvenString(char* temp);

char* fixOddString(char* temp, int validLastIndex);

char* getLastWordindex(char* name);

char* fixIATAcode(char* checkIATAcode);

#endif /* STRINGUTILL_H_ */
