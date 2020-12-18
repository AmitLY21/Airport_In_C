/*
 * MainFunctions.c
 *
 *  Created on: 9 Dec 2020
 * Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */
#include "MainFunctions.h"

void addFlightToAirline(Airline* airline, AirportManager* manager)
{
	char codeSrc[IATA_SIZE], codeDest[IATA_SIZE];
	getSrcDestFromUser(codeSrc, codeDest, manager);
	Flight* f1 = (Flight*)malloc(sizeof(Flight));
	if(!f1)
		printf("\nError in allocate flight\n");

	if(!initFlight(f1, codeSrc, codeDest))
		printf("\nError in initFlight\n");

	if(!addFlight(f1, airline))
		printf("\nError in add flight\n");
	else
		printf("\nFlight added successfully\n");
}

//get IATA code , source and destination
int getSrcDestFromUser(char codeSrc[IATA_SIZE], char codeDest[IATA_SIZE], AirportManager* manager)
{
	int flag = 1;
	Airport* airportSrc = (Airport*)malloc(sizeof(Airport));
	Airport* airportDest= (Airport*)malloc(sizeof(Airport));

	while(flag)
	{
		printf("\nEnter Air Port source IATA code:\n");
		scanf("%s", codeSrc);

		printf("\nEnter Air Port destination IATA code:\n");
		scanf("%s", codeDest);

		for(int i = 0 ; i < IATA_SIZE ; i++)
		{
			codeSrc[i] = toupper(codeSrc[i]);
			codeDest[i] = toupper(codeDest[i]);
		}

		airportSrc = findAirportByIATA(codeSrc, manager);//findAirportByIATA @returns Airport*
		airportDest = findAirportByIATA(codeDest, manager);//findAirportByIATA @returns Airport*

		if(!airportSrc || !airportDest)
			printf("\nInvalid IATA code\n");
		else if(!checkValidSrcDest(airportSrc, airportDest))//checkValidSrcDest @returns 0 if equal 1 if not
		{
			flag = 0;
		}
	}
	return 1;
}

void addAirportToManager(AirportManager* manager)
{
	int flag = 1;
	Airport a;
	while(flag)
	{
		if(initAirPort(&a))
		{
			int isExist = 0;
			for(int i = 0 ; i < manager->numOfAirports; i++)
			{
				if(equalsAirportsByIATA(&a, &manager->allAirports[i]))
				{
					printf("\nAirport already exist\n");
					isExist = 1;
				}
			}
			if(!isExist)
			{
				if(addAirport(a,  manager))
				{
					printf("\nAirport added successfully\n");
					flag = 0;
				}
			}
		}
	}
}
/////////////////////////////////////////////////////
//checkValidSrcDest								   //
//Aim: check if the Airport IATA code is the same  //
//Output: 0 if equal                               //
//        1 if not                                 //
/////////////////////////////////////////////////////
int checkValidSrcDest(Airport* airportSrc,Airport* airportDest)
{
	if(equalsAirportsByIATA(airportSrc, airportDest))
	{
		printf("\nAirport source and destination are equals\n");
		return 1;
	}
	return 0;
}

void numberOfFlightOnRoute(Airline* airline,AirportManager* manager)
{
	char codeSrc[IATA_SIZE], codeDest[IATA_SIZE];
	getSrcDestFromUser(codeSrc, codeDest, manager);
	printf("\nNumber of flights on route: %d\n",checkFlightsRoute(airline->allAirlineFlights, airline->numOfFlights, codeSrc, codeDest));
}

void freeAll(Airline* airline, AirportManager* manager)
{
	freeAirline(airline);
	free(manager->allAirports);

}



