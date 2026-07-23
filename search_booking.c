#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "search_booking.h"

static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void searchBooking(struct Movie movies[]) {
    int movieId, showtimeId, searchChoice;

    printf("\n--- Search Booking ---\n");

    printf("Enter Movie ID (1-%d): ", MOVIE_COUNT);
    if (scanf("%d", &movieId) != 1 || movieId < 1 || movieId > MOVIE_COUNT) {
        printf("Error: Invalid Movie ID.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("Enter Showtime (1 for first, 2 for second): ");
    if (scanf("%d", &showtimeId) != 1 || showtimeId < 1 || showtimeId > SHOWTIMES_PER_MOVIE) {
        printf("Error: Invalid Showtime.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    int mIndex = movieId - 1;
    int sIndex = showtimeId - 1;

    printf("\nSearch by:\n");
    printf("1. Customer Name\n");
    printf("2. Seat Number\n");
    printf("Choice (1-2): ");
    if (scanf("%d", &searchChoice) != 1 || searchChoice < 1 || searchChoice > 2) {
        printf("Error: Invalid choice.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("\nMovie: %s (%s)\n", movies[mIndex].name, movies[mIndex].showtimes[sIndex].time);
    printf("--------------------------------------------------\n");

    if (searchChoice == 1) {
        char searchName[50];

        printf("Enter Customer Name: ");
        fgets(searchName, sizeof(searchName), stdin);
        searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

        int found = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                struct Seat *seat = &movies[mIndex].showtimes[sIndex].seats[r][c];

                if (seat->status == 'X' && strcmp(seat->customerName, searchName) == 0) {
                    printf("Seat %c%d | Customer: %s | Price Paid: Rs. %.2f\n",
                           'A' + r, c + 1, seat->customerName, seat->pricePaid);
                    found++;
                }
            }
        }

        if (!found) {
            printf("No booking found for customer \"%s\".\n", searchName);
        }
    } else {
        char rowChar;
        int colNum;

        printf("Enter Row (A-E) and Column (1-10) [e.g., A 5]: ");
        if (scanf(" %c %d", &rowChar, &colNum) != 2) {
            printf("Error: Invalid input format.\n");
            clearBuffer();
            return;
        }
        clearBuffer();

        rowChar = toupper(rowChar);
        int rIndex = rowChar - 'A';
        int cIndex = colNum - 1;

        if (rIndex < 0 || rIndex >= ROWS || cIndex < 0 || cIndex >= COLS) {
            printf("Error: Seat out of range. Row must be A-E and Column 1-10.\n");
            return;
        }

        struct Seat *seat = &movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex];

        if (seat->status != 'X') {
            printf("Seat %c%d is not currently booked.\n", rowChar, colNum);
        } else {
            printf("Seat %c%d | Customer: %s | Price Paid: Rs. %.2f\n",
                   rowChar, colNum, seat->customerName, seat->pricePaid);
        }
    }

    printf("--------------------------------------------------\n\n");
}
