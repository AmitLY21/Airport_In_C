/*
 * Main.c
 *
 *  Created on: 7 Dec 2020
 *   Authors:
 *  Gal Shamir 208613356
 *  Amit Levy 206841496
 */
#include <stdio.h>
#include <stdlib.h>
#include "AirportManager.h"
#include "MainFunctions.h"
#include "Airline.h"
#include "Flight.h"

int main()
{

	AirportManager manager;
	Airline airline;
	int numOfAirports, choice, flag = 1;

	initAirportManager(&manager);

	printf("\nEnter number of airports you would like to add (2 minimum):\n");
	scanf("%d", &numOfAirports);
	if(numOfAirports < MIN_NUM_AIRPORT)
		numOfAirports = MIN_NUM_AIRPORT;
	for(int i = 0 ; i < numOfAirports; i++)
		addAirportToManager(&manager);
	getchar(); //clean the buffer

	if(!initAirline(&airline))
		printf("\nError in init Airline\n");

	while(flag)
	{
		printf("\nChoose from the following:\n");
		printf("1--> Add flight to Airline\n"
				"2--> Add Airport\n"
				"3--> Print Airline\n"
				"4--> Print all Airports\n"
				"5--> Print flight on route\n"
				"6--> Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			addFlightToAirline(&airline, &manager);
			break;

		case 2:
			addAirportToManager(&manager);
			break;

		case 3:
			printAirline(&airline);
			break;

		case 4:
			printAllairports(&manager);
			break;

		case 5:
			numberOfFlightOnRoute(&airline, &manager);
			break;

		case 6:
			freeAll(&airline, &manager);
			flag = 0;
			printf("\nHasta La-vista\n");
			printf("\n\t__|__\n --------(_)--------\n   O  O       O  O\n");
			break;

		default:
			printf("\nInvalid input\n");
			break;
		}
	}
}



