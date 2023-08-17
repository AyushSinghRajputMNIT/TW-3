#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 50
#define MAX_TRAIN 10
#define MAX_SEATS 50

struct Seat {
    int seatNumber;
    int isBooked;
    char passengerName[50];
};

struct Train {
    char trainName[50];
    int numSeats;
    float seatCost;
    struct Seat seats[MAX_SEATS];
};

struct Train trains[MAX_TRAIN];
int trainCount = 0;

void initializeSeats(struct Seat seats[], int numSeats) {
    for (int i = 0; i < numSeats; ++i) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].passengerName, "");
    }
}

void addTrain(const char *trainName, int numSeats, float seatCost) {
    if (trainCount < MAX_TRAIN) {
        struct Train newTrain;
        strcpy(newTrain.trainName, trainName);
        newTrain.numSeats = numSeats;
        newTrain.seatCost = seatCost;
        initializeSeats(newTrain.seats, numSeats);
        trains[trainCount] = newTrain;
        trainCount++;
        printf("Train added successfully.\n");
    } else {
        printf("Maximum train limit reached.\n");
    }
}

void displayCities() {
    printf("Available Cities:\n");
    printf("1. City A\n");
    printf("2. City B\n");

}

void bookTicket(int trainIndex, int seatNumber, const char *passengerName) {
    if (trainIndex >= 0 && trainIndex < trainCount) {
        struct Train *train = &trains[trainIndex];
        if (seatNumber > 0 && seatNumber <= train->numSeats && !train->seats[seatNumber - 1].isBooked) {
            train->seats[seatNumber - 1].isBooked = 1;
            strcpy(train->seats[seatNumber - 1].passengerName, passengerName);
            printf("Ticket booked successfully.\n");
        } else {
            printf("Invalid seat number or seat already booked.\n");
        }
    } else {
        printf("Invalid train selection.\n");
    }
}

void displayTrainInfo(int trainIndex) {
    if (trainIndex >= 0 && trainIndex < trainCount) {
        struct Train *train = &trains[trainIndex];
        printf("Train Name: %s\n", train->trainName);
        printf("Number of Seats: %d\n", train->numSeats);
        printf("Seat Cost: $%.2f\n", train->seatCost);
        printf("Available Seats:\n");
        for (int j = 0; j < train->numSeats; ++j) {
            if (!train->seats[j].isBooked) {
                printf("Seat %d\n", train->seats[j].seatNumber);
            }
        }
    } else {
        printf("Invalid train selection.\n");
    }
}


int main() {

    displayCities();

    int choice;
    do {
        printf("\nRailway Reservation System\n");
        printf("1. Add Train\n");
        printf("2. Book Ticket\n");
        printf("3. Display Train Info\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int numSeats;
                float seatCost;
                char trainName[50];
                printf("Enter train name: ");
                scanf("%s", trainName);
                printf("Enter number of seats: ");
                scanf("%d", &numSeats);
                printf("Enter seat cost: ");
                scanf("%f", &seatCost);
                addTrain(trainName, numSeats, seatCost);
                break;
            }
            case 2: {
                int trainIndex, seatNumber;
                char passengerName[50];
                printf("Select a train:\n");
                for (int i = 0; i < trainCount; ++i) {
                    printf("%d. %s\n", i + 1, trains[i].trainName);
                }
                printf("Enter your choice: ");
                scanf("%d", &trainIndex);
                trainIndex--;
                if (trainIndex >= 0 && trainIndex < trainCount) {
                    displayTrainInfo(trainIndex);
                    printf("Enter seat number: ");
                    scanf("%d", &seatNumber);
                    printf("Enter passenger name: ");
                    scanf("%s", passengerName);
                    bookTicket(trainIndex, seatNumber, passengerName);
                } else {
                    printf("Invalid train selection.\n");
                }
                break;
            }
            case 3: {
                int trainIndex;
                printf("Select a train:\n");
                for (int i = 0; i < trainCount; ++i) {
                    printf("%d. %s\n", i + 1, trains[i].trainName);
                }
                printf("Enter your choice: ");
                scanf("%d", &trainIndex);
                trainIndex--;
                if (trainIndex >= 0 && trainIndex < trainCount) {
                    displayTrainInfo(trainIndex);
                } else {
                    printf("Invalid train selection.\n");
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

