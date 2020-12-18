/*
 * stringUtill.c
 *
 *  Created on: 3 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */
#include "stringUtill.h"

/////////////////////////////////////////////////////
//getstrExactLength								   //
//Aim: trim string                                 //
//@returns the trimmed string                      //
/////////////////////////////////////////////////////
char* getstrExactLength(char *temp) {
	char *str = strdup(temp);
	if (!str) {
		printf("\nfail in string\n");// In case of unseccssefull allocate
		return NULL;
	}
	return str;
}

char* fixAirportName(char *name) {
	char *lastWordIndex = getLastWordindex(name);
	char *temp = (char*) malloc(MAX_LENGTH * sizeof(char));
	char *newName = (char*) malloc(MAX_LENGTH * sizeof(char));
	if(!temp || !newName)
		{
			printf("\nUnseccssefull allocating(fixAirportName)");
			return NULL;
		}

	if (lastWordIndex == name) {//In case of one word in the name
		name = fixOddString(name, 0);
		name = getstrExactLength(name);
		*(name + strcspn(name , "\n")) = '\0';//replace to null terminator string
		return name;
	}

	name = strtok(name, " ");

	do {
		if (!name) //in case of string starting with spaces
			name = strtok(NULL, " ");
		else {
			temp = getstrExactLength(name);
			if(temp == NULL)
				return temp;

			if (name == lastWordIndex) {
				if (strlen(temp) % 2 == 0) //not including '\n'
					temp = fixOddString(temp, 1);
				else
					temp = fixEvenString(temp);
			} else {
				if (strlen(temp) % 2 == 0)
					temp = fixEvenString(temp);
				else if (name != lastWordIndex)
					temp = fixOddString(temp, 0);
				else
					temp = fixOddString(temp, 1);
			}

			strcat(newName, temp); //concat the new string

			if (name != lastWordIndex)
				strcat(newName, "  ");
			name = strtok(NULL, " ");
		}
	} while (name);

	*(newName + strcspn(newName , "\n")) = '\0';//Replace to null terminator string
	newName = getstrExactLength(newName);
	return newName;
}

char* fixEvenString(char *temp) {
	for (int i = 0; i < strlen(temp); i++) {
		if (i % 2 == 0)
			*(temp + i) = toupper(*(temp + i));
		else
			*(temp + i) = tolower(*(temp + i));
	}
	return temp;
}

char* fixOddString(char *temp, int validLastIndex) {
	if (!validLastIndex) {
		*temp = toupper(*temp);
		for (int i = 1; i < strlen(temp); i++) {
			*(temp + i) = tolower(*(temp + i));
		}
	} else {
		for (int i = 0; i < strlen(temp); i++) {
			*(temp + i) = tolower(*(temp + i));
		}
	}
	return temp;
}

char* getLastWordindex(char *name) {
	char *lastWordIndex = name;
	char *i = name;
	while (*i) {
		if (isspace(*i) && !(isspace(*i + 1)))
			lastWordIndex = i + 1;
		i++;
	}
	return lastWordIndex;
}

char* fixIATAcode(char *checkIATAcode) {
	for (int i = 0; i < IATA_SIZE; i++)
		*(checkIATAcode + i) = toupper(*(checkIATAcode + i));
	return checkIATAcode;
}

