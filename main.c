#include <stdio.h>
#include "lrt2fare.h"
#include "lrt1fare.h"
#include "mrt3fare.h"
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int getStartingLine() {
	printf("Welcome to Elaijah's Station Simulator!\n");
	printf("Please select your starting line.\n");

	int starting_line = 0;
	int has_starting_line = 0;
	while (!has_starting_line) {
		printf("1. LRT1\n2. LRT2\n3. MRT3\nStarting line: ");
		scanf("%d", &starting_line);
		if (starting_line == 1 || starting_line == 2 || starting_line == 3) {
			has_starting_line = 1;

			return starting_line;
		} else {
			printf("Error. Please try again.\n");
			return getStartingLine();
		}
	}
	return 0;
}

int getCardType() {
	int card_type = 0;
	int has_card_type = 0;
	while (!has_card_type) {
	printf("Please select your type of card. \n1. Regular\n2. Student\n3. PWD/Senior\n4. Single Journey Ticket\nCard type: ");
	scanf("%d", &card_type);

	if (card_type == 1 || card_type == 2 || card_type ==  3 || card_type == 4 )
	{
		has_card_type = 1;
	} else {
		printf("Error. Please try again.\n");
		return getCardType();
	}
	}
	return card_type;
	}

float getDiscountMultiplier(int card_type) {
	float discount_multiplier;
	switch (card_type) {
		case 1:
			discount_multiplier = 1;
			break;
		case 2:
			discount_multiplier = 0.8;
			break;
		case 3:
			discount_multiplier = 0.7;	
			break;
		case 4:
			discount_multiplier = 1;
			break;
		default:
			printf("Error. Please try again.\n");
	}
	return discount_multiplier;
}


void displayStations(int starting_line) {
	printf("0. Exit\n");
	switch (starting_line) {
		case 1:
			for (int i = 0; i < LRT1_NUM_STATIONS; i++) {
				printf("%d. %s\n", i + 1, lrt1_stations[i]);
			}
			break;
		case 2:
			for (int i = 0; i < LRT2_NUM_STATIONS; i++) {
				printf("%d. %s\n", i + 1, lrt2_stations[i]);
			}
			break;
		case 3:
			for (int i = 0; i < MRT3_NUM_STATIONS; i++) {
				printf("%d. %s\n", i + 1, mrt3_stations[i]);
			}
			break;
		default:
			printf("Error. Please try again.\n");
	}
}

int calculateFare(int starting_line, int starting_station, int destination_station) {
	int fare = 0;
	switch (starting_line) {
		case 1:
			fare = lrt1_fare_matrix[starting_station - 1][destination_station - 1]; 
			break;
		case 2:
			fare = lrt2_fare_matrix[starting_station - 1][destination_station - 1];
			break;
		case 3:
			fare = mrt3_fare_matrix[starting_station - 1][destination_station - 1];
			break;
		default:
			printf("Error. Please try again.\n");
	}
	return fare;
}

int calculateFareSJ(int starting_line, int starting_station, int destination_station) {
	int fare = 0;
	switch (starting_line) {
		case 1:
			fare = lrt1_sj_fare_matrix[starting_station - 1][destination_station - 1];
			break;
		case 2:
			fare = lrt2_sj_fare_matrix[starting_station - 1][destination_station - 1];
			break;
		case 3:
			fare = mrt3_sj_fare_matrix[starting_station - 1][destination_station - 1];
			break;
		default:
			printf("Error. Please try again.\n");
	}
	return fare;
}
	
void checkStationSwitch(int *starting_line, int *starting_station) {
    if (*starting_line == 1 && *starting_station == 2) {
        printf("You can switch to MRT3 Taft Ave.\n");
        printf("Do you want to switch lines? (Y/N)\n");
        char choice = getch();
        if (choice == 'Y' || choice == 'y') {
            *starting_line = 3;
            *starting_station = 13;
        }
    } else if (*starting_line == 1 && *starting_station == 11) {
        printf("You can switch to LRT2 Doroteo Jose.\n");
        printf("Do you want to switch lines? (Y/N)\n");
        char choice = getch();
        if (choice == 'Y' || choice == 'y') {
            *starting_line = 2;
            *starting_station = 1;
        }
    } else if (*starting_line == 2 && *starting_station == 1) {
        printf("You can switch to LRT1 Doroteo Jose.\n");
        printf("Do you want to switch lines? (Y/N)\n");
        char choice = getch();
        if (choice == 'Y' || choice == 'y') {
            *starting_line = 1;
            *starting_station = 11;
        }
    } else if (*starting_line == 2 && *starting_station == 8) {
        printf("You can switch to MRT3 Cubao.\n");
        printf("Do you want to switch lines? (Y/N)\n");
        char choice = getch();
        if (choice == 'Y' || choice == 'y') {
            *starting_line = 3;
            *starting_station = 4;
        }
    } else if (*starting_line == 3 && *starting_station == 13) {
        printf("You can switch to LRT1 EDSA.\n");
        printf("Do you want to switch lines? (Y/N)\n");
        char choice = getch();
        if (choice == 'Y' || choice == 'y') {
            *starting_line = 1;
            *starting_station = 2;
        }
    } else if (*starting_line == 3 && *starting_station == 4) {
        printf("You can switch to LRT2 Cubao.\n");
        printf("Do you want to switch lines? (Y/N)\n");
        char choice = getch();
        if (choice == 'Y' || choice == 'y') {
            *starting_line = 2;
            *starting_station = 8;
        }
    } else if (*starting_line == 3 && *starting_station == 1) {
		printf("You can switch to LRT1 Fernando Poe Jr.\n");
		printf("Do you want to switch lines? (Y/N)\n");
		char choice = getch();
		if (choice == 'Y' || choice == 'y') {
			*starting_line = 1;
			*starting_station = 20;
		}
	} else if (*starting_line == 1 && *starting_station == 20) {
		printf("You can switch to MRT3 North Ave.\n");
		printf("Do you want to switch lines? (Y/N)\n");
		char choice = getch();
		if (choice == 'Y' || choice == 'y') {
			*starting_line = 3;
			*starting_station = 1;
		}
	}
}

int getBalance() {
	int balance = 0;
	
	printf("Please enter your balance: ");
	scanf("%d", &balance);

	if (balance == 4) {
		if (balance < 15) {
			printf("You don't have enough balance to ride.\n");
			exit(0);
		}
	} else {
		if (balance < 20) {
			printf("You don't have enough balance to ride.\n");
			exit(0);
		}
	}
	return balance;
}

int calculateBalance(int balance, int total_fare) {
	int new_balance = balance - total_fare;
	return new_balance;
}

int main()
{
	int starting_line = getStartingLine();
	int card_type = getCardType();
	float discount_multiplier = getDiscountMultiplier(card_type);
	int balance = getBalance();
	int station_switch_first_check = 0;
	int starting_station, destination_station;

	printf("\nWhich station are you starting from?\n");
	displayStations(starting_line);
	scanf("%d", &starting_station);
	int is_finished = 0;
	int total_fare = 0;



	while (!is_finished) {

		//checker to make sure that the station switch happens after the first station
		if (station_switch_first_check == 0)
		{
			station_switch_first_check = 1;
		}
		else
		{
			checkStationSwitch(&starting_line, &starting_station);
		}

		switch (starting_line)
		{
		case 1:
			printf("You are currently at %s.\n", lrt1_stations[starting_station - 1]);
			break;
		case 2:
			printf("You are currently at %s.\n", lrt2_stations[starting_station - 1]);
			break;
		case 3:
			printf("You are currently at %s.\n", mrt3_stations[starting_station - 1]);
			break;
		default:
			printf("Error. Please try again.\n");
		}

		printf("Which station are you going to?\n");
		displayStations(starting_line);
		scanf("%d", &destination_station);

		if (destination_station == 0)
		{
			printf("Thank you for using Elaijah's Station Simulator!\n");
			exit(0);
		}
		
		if (starting_station == destination_station) {
			printf("You are already at your destination.\n");
		} else {
			int fare = calculateFare(starting_line, starting_station, destination_station);
			total_fare += fare * discount_multiplier;
			printf("Your fare is: P%d\n", total_fare);

			balance = calculateBalance(balance, total_fare);
			printf("Your balance is: P%d\n", balance);
		}
		
		printf("Do you want to ride again? (Y/N)\n\n\n");
		char choice = getch();
		if (choice == 'N' || choice == 'n') {
			is_finished = 1;
		}

		starting_station = destination_station;
	}

	printf("Your total fare is: P%d\n", total_fare);
	printf("Your balance is: P%d\n", balance);
	printf("Thank you for using Elaijah's Station Simulator!\n");

	return 0;
}
