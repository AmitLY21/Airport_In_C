/*
 * Date.h
 *
 *  Created on: 1 Dec 2020
 *      Author: gal
 */

#ifndef DATE_H_
#define DATE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringUtill.h"

#define CURRENT_YEAR 2020
#define MAX_YEAR 2023

typedef struct{
	int day, month, year;
}Date;

int initDate(Date* d1);

void printDate(const Date* d1);

int checkValidDate(int days, int month, int year);


#endif /* DATE_H_ */
