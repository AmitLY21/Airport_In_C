/*
 * Airport.c
 *
 *  Created on: 3 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */

#include "Airport.h"

int initAirPort(Airport *a1) {
	printf("\nEnter state:\n");
	a1->state = (char*) malloc(MAX_LENGTH * sizeof(char));
	if (!a1->state)
		return 0; //in case of unsuccessful allocate
	scanf("%s", a1->state);
	a1->state = getstrExactLength(a1->state);
	if (!a1->state)
		return 0; //in case of unsuccessful allocate
	getchar();//clean the buffer
	printf("\nEnter name:\n");
	a1->name = (char*) malloc(MAX_LENGTH * sizeof(char));
	fgets(a1->name, MAX_LENGTH, stdin);
	a1->name = fixAirportName(a1->name);
	//IATA is unique to each airport (check!)
	char *checkInputIATA = (char*) malloc(MAX_LENGTH * sizeof(char));
	if (!checkInputIATA)
		return 0;
	strcpy(a1->codeIATA ,getIATA(checkInputIATA));
	return 1;
}
//Get IATA code from user
char* getIATA(char *checkInputIATA) {
	int flag = 1;
	while (flag) {
		printf("\nenter IATA code (3 letters):\n");
		scanf("%s", checkInputIATA);
		checkInputIATA = getstrExactLength(checkInputIATA);
		if (strlen(checkInputIATA) != 3) {
			printf("\nInvalid code length , please enter again");
			scanf("%s", checkInputIATA);
		} else {
			checkInputIATA = fixIATAcode(checkInputIATA);
			flag = 0;
		}
	}
	return checkInputIATA;
}

void printAirport(const Airport *a1) {
	printf("Name: %s, State: %s, Code IATA: %s\n", a1->name, a1->state, a1->codeIATA);
}
/**
 * equalsAirportsByIATA
 * @return 1 if equals 0 if not
 */
int equalsAirportsByIATA(Airport *a1, Airport *a2) {
	for(int i = 0 ; i < IATA_SIZE ; i++)
	{
		a1->codeIATA[i] = toupper(a1->codeIATA[i]);
		a2->codeIATA[i] = toupper(a2->codeIATA[i]);
	}
	if (strcmp(a1->codeIATA, a2->codeIATA) == 0)
		return 1;
	return 0;
}
/**
 * checkAirportIATA
 * @return 1 if equals 0 if not
 */
int checkAirportIATA(Airport *a1, char code[IATA_SIZE]) {
	if (strcmp(a1->codeIATA, code) == 0)
		return 1;
	return 0;
}

void freeAirport(Airport* a1)
{
	free(a1->name);
	free(a1->state);
}
