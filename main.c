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
	while (1) {  
			printf("1. LRT1\n2. LRT2\n3. MRT3\nStarting line: ");

			if (scanf("%d", &starting_line) != 1) {
				while (getchar() != '\n');  
				printf("Error. Please enter a number (1, 2, or 3).\n");
				continue;  
			}

			if (starting_line == 1 || starting_line == 2 || starting_line == 3) {
				return starting_line;  
			} else {
				printf("Error. Please try again.\n");
			}
		}
	
	return 0;
}

int getCardType() {
	int card_type = 0;
    while (1) {
        printf("Please select your type of card.\n");
        printf("1. Regular\n2. Student\n3. PWD/Senior\n4. Single Journey Ticket\nCard type: ");
        
        if (scanf("%d", &card_type) != 1) {
            while (getchar() != '\n'); 
            printf("Error. Please enter a valid number (1, 2, 3, or 4).\n");
            continue; 
        }

        if (card_type >= 1 && card_type <= 4) {
            return card_type;  
        } else {
            printf("Error. Please try again.\n");
        }
    }
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
typedef struct {
    int line;
    int station;
    int new_line;
    int new_station;
    const char* switch_message;
} StationSwitch;

int promptSwitchConfirmation() {
    char choice;
    do {
        printf("Do you want to switch lines? (Y/N): ");
        while (getchar() != '\n');  // Clear the buffer
        choice = getchar();
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
    
    return (choice == 'Y' || choice == 'y');
}

void checkStationSwitch(int *starting_line, int *starting_station) {
    StationSwitch switches[] = {
        {1, 2, 3, 13, "You can switch to MRT3 Taft Ave.\n"},
        {1, 11, 2, 1, "You can switch to LRT2 Doroteo Jose.\n"},
        {2, 1, 1, 11, "You can switch to LRT1 Doroteo Jose.\n"},
        {2, 8, 3, 4, "You can switch to MRT3 Cubao.\n"},
        {3, 13, 1, 2, "You can switch to LRT1 EDSA.\n"},
        {3, 4, 2, 8, "You can switch to LRT2 Cubao.\n"},
        {3, 1, 1, 20, "You can switch to LRT1 Fernando Poe Jr.\n"},
        {1, 20, 3, 1, "You can switch to MRT3 North Ave.\n"}
    };

    for (int i = 0; i < sizeof(switches) / sizeof(switches[0]); i++) {
        if (*starting_line == switches[i].line && *starting_station == switches[i].station) {
            printf("%s", switches[i].switch_message);
            if (promptSwitchConfirmation()) {
                *starting_line = switches[i].new_line;
                *starting_station = switches[i].new_station;
            }
            break;
        }
    }
}

int getBalance(int card_type) {
	int balance = 0;
	
    while (1) {
        printf("Please enter your balance: ");

        if (scanf("%d", &balance) != 1) {
            while (getchar() != '\n');  
            printf("Error. Please enter a valid number.\n");
            continue; 
        }

        if ((card_type == 4 && balance < 15) || (card_type != 4 && balance < 20)) {
            printf("You don't have enough balance to ride.\n");
            exit(0); 
        }

        return balance;
    }
}

int calculateBalance(int balance, int total_fare) {
	int new_balance = balance - total_fare;
	return new_balance;
}

int isValidStation(int starting_line, int station) {
	switch (starting_line) {
		case 1:
			return station >= 0 && station <= LRT1_NUM_STATIONS;
		case 2:
			return station >= 0 && station <= LRT2_NUM_STATIONS;
		case 3:
			return station >= 0 && station <= MRT3_NUM_STATIONS;
		default:
			return 0;
	}
}

int main() {
    int starting_line = getStartingLine();
    int card_type = getCardType();
    float discount_multiplier = getDiscountMultiplier(card_type);
    int balance = getBalance(card_type);
    int station_switch_first_check = 0;
    int total_fare_switch_first_check = 0;
    int starting_station = 0, destination_station = 0;
    int is_finished = 0;
    int fare = 0;
    int total_fare = 0;
	char continue_ride;

    printf("\nWhich station are you starting from?\n");
    displayStations(starting_line);

    while (1) {
        printf("Enter starting station number: ");
        if (scanf("%d", &starting_station) != 1) {
            while (getchar() != '\n');  // Clear invalid input
            printf("Error. Please enter a valid station number.\n");
            continue;
        }
        if (isValidStation(starting_line, starting_station)) break; 
        else printf("Invalid station number. Please try again.\n");
    }

	system("cls");

    while (!is_finished) {
        if (station_switch_first_check == 0) {
            station_switch_first_check = 1;
        } else {
            checkStationSwitch(&starting_line, &starting_station);

            system("cls");
        }

        switch (starting_line) {
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
                printf("Error. Invalid line number.\n");
                continue;
        }

        printf("Which station are you going to?\n");
        displayStations(starting_line);
        while (1) {
            printf("Enter station destination number (or 0 to exit): ");
            if (scanf("%d", &destination_station) != 1) {
                while (getchar() != '\n');  
                printf("Error. Please enter a valid station number.\n");
                continue;
            }
            if (destination_station == 0) {

                if (total_fare > 0) {
                    printf("Your total fare is: P%d\n", total_fare);
                    printf("Your balance is: P%d\n", balance);
                }
                
                printf("Thank you for using Elaijah's Station Simulator!\n");
                printf("Press any key to exit.\n");
                getch();
                exit(0);
            }
            if (isValidStation(starting_line, destination_station)) break;  
            else printf("Invalid station number. Please try again.\n");
        }

        if (starting_station == destination_station) {
            printf("You are already at your destination.\n");
        } else {

            if (card_type == 4) {
                fare = calculateFareSJ(starting_line, starting_station, destination_station);
                total_fare += fare;
            } else {
                fare = calculateFare(starting_line, starting_station, destination_station);
                total_fare += fare * discount_multiplier;
            }

            if (total_fare_switch_first_check == 0) {
                printf("Your fare is: P%d\n", total_fare);
                total_fare_switch_first_check = 1;
            } else {
                printf("Your fare for this ride is: P%d\n", fare);
                printf("Your total fare is: P%d\n", total_fare);
            }

            balance = calculateBalance(balance, total_fare);
            printf("Your balance is: P%d\n", balance);

            if (balance < 0) {
                printf("Insufficient balance for further rides.\n");
                exit(0);
            }
        }

		do {
			printf("Do you want to ride again? (Y/N): ");
			while (getchar() != '\n');  // clear buffer, removes any extra characters
			continue_ride = getchar();
		} while (continue_ride != 'Y' && continue_ride != 'y' && continue_ride != 'N' && continue_ride != 'n');

		if (continue_ride == 'N' || continue_ride == 'n') {
			is_finished = 1;
		}

		system("cls");

		starting_station = destination_station;
	}

    printf("Your total fare is: P%d\n", total_fare);
    printf("Your balance is: P%d\n", balance);
    printf("Thank you for using Elaijah's Station Simulator!\n");
    printf("Press any key to exit.\n");

    getch();

    return 0;
}
