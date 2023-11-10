#include <stdio.h>

struct participant {
    int id;
    char first_name[50];
    char last_name[50];
    int meals;
    int hotel;
    int hotel_type;
};

int main() {
    struct participant p[100];
    int choice;
    int numParticipants = 0;
    int idAmount;
    int total = 0;
    int i;

    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Add a participant\n");
        printf("2. Calculate the amount for a participant\n");
        printf("3. Display all participants\n");
        printf("4. Remove a participant\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a participant
                if (numParticipants < 100) {
                    p[numParticipants].id = numParticipants + 1;
                    printf("Enter the first name: ");
                    scanf("%s", p[numParticipants].first_name);
                    printf("Enter the last name: ");
                    scanf("%s", p[numParticipants].last_name);

                    printf("Does the participant want meals? (1 for yes, 0 for no): ");
                    scanf("%d", &p[numParticipants].meals);
                    if (p[numParticipants].meals == 1) {
                        printf("(1 for lunch) (2 for dinner) (3 for both): ");
                        scanf("%d", &p[numParticipants].meals);
                    } else {
                        p[numParticipants].meals = 0;
                    }

                    printf("Does the participant want a hotel? (1 for yes, 0 for no): ");
                    scanf("%d", &p[numParticipants].hotel);
                    if (p[numParticipants].hotel == 1) {
                        printf("Enter the hotel type (4 for 4 stars, 5 for 5 stars): ");
                        scanf("%d", &p[numParticipants].hotel_type);
                    } else {
                        p[numParticipants].hotel = 0;
                    }

                    numParticipants = numParticipants + 1;
                    printf("Participant added successfully!\n");
                } else {
                    printf("Maximum number of participants reached!\n");
                }
                break;

            case 2:
                // Calculate the amount for a participant
                printf("Enter the participant's ID: ");
                scanf("%d", &idAmount);
                int participantFound = 0;
                int meal_amount = 0;
                int hotel_amount = 0;

                for (i = 0; i < numParticipants; i++) {
                    if (idAmount == p[i].id) {
                        participantFound = 1;

                        switch (p[i].meals) {
                            case 0:
                                meal_amount = 0;
                                break;
                            case 2:
                                meal_amount = 15;
                                break;
                            case 3:
                                meal_amount = 35;
                                break;
                            case 4:
                                meal_amount = 50;
                                break;
                        }

                        switch (p[i].hotel_type) {
                            case 4:
                                hotel_amount = 75;
                                break;
                            case 5:
                                hotel_amount = 100;
                                break;
                        }
                    }

                }

                if (participantFound) {
                    total = meal_amount + hotel_amount;
                    printf("The total amount for the participant with ID %d is %d DT.\n", idAmount, total);
                } else {
                    printf("Participant with ID %d not found.\n", idAmount);
                }
                break;

            case 3:
                // Display all participants
                printf("\nList of all participants:\n");
                for (i = 0; i < numParticipants; i++) {
                    printf("ID: %d, First Name: %s, Last Name: %s\n", p[i].id, p[i].first_name, p[i].last_name);
                }
                break;

        }
    } while (choice != 0);

    return 0;
}
"# Event-Participant-Manager" 
