#include <stdio.h>

int menu()
{
    int option = 0;
    int c;

    printf("Main Menu:\n");
    printf("1. View Showtimes\n");
    printf("2. View Seat Map\n");
    printf("3. Book a Seat\n");
    printf("4. Cancel a Booking\n");
    printf("5. Search Booking\n");
    printf("6. View Revenue Report\n");
    printf("7. Exit\n");

    while (1) {
        printf("Select option: ");

        int result = scanf("%d", &option);

        while ((c = getchar()) != '\n' && c != EOF);

        if (result != 1) {
            printf("Invalid input, please enter a number.\n");
            continue;
        }

        if (option >= 1 && option <= 7) {
            break;
        }

        printf("Please choose a number between 1 and 7.\n");
    }

    return option;
}