#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "book_seat.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void bookSeat(struct Movie movies[]) {
    int movieId, showtimeId, numSeats, categoryChoice;
    char customerName[50];

    printf("\n--- Book a Seat ---\n");

    printf("Enter Movie ID (1-3): ");
    if (scanf("%d", &movieId) != 1 || movieId < 1 || movieId > MOVIE_COUNT) {
        printf("Error: Invalid Movie ID.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    printf("Enter Showtime (1 for first, 2 for second): ");
    if (scanf("%d", &showtimeId) != 1 || showtimeId < 1 || showtimeId > SHOWTIMES_PER_MOVIE) {
        printf("Error: Invalid Showtime.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int mIndex = movieId - 1;
    int sIndex = showtimeId - 1;

    printf("Enter Customer Name: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = '\0'; // Remove newline

    printf("\nSelect Discount Category:\n");
    printf("1. Standard (No Category Discount)\n");
    printf("2. Student (10%% Off)\n");
    printf("3. Senior Citizen (20%% Off)\n");
    printf("Choice (1-3): ");
    if (scanf("%d", &categoryChoice) != 1 || categoryChoice < 1 || categoryChoice > 3) {
        printf("Error: Invalid category selection.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    double categoryDiscount = 0.0;
    if (categoryChoice == 2) categoryDiscount = 0.10;
    else if (categoryChoice == 3) categoryDiscount = 0.20;

    printf("How many seats would you like to book? ");
    if (scanf("%d", &numSeats) != 1 || numSeats <= 0 || numSeats > (ROWS * COLS)) {
        printf("Error: Invalid number of seats.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    double groupDiscount = (numSeats >= 4) ? 0.10 : 0.0;
    double totalDiscount = categoryDiscount + groupDiscount;

    double grandTotal = 0.0;
    int bookedCount = 0;

    printf("\nBooking %d seat(s). Discount Applied: %.0f%%\n", numSeats, totalDiscount * 100);
    printf("--------------------------------------------------\n");

    while (bookedCount < numSeats) {
        char rowChar;
        int colNum;

        printf("Seat %d of %d - Enter Row (A-E) and Column (1-10) [e.g., A 5]: ", bookedCount + 1, numSeats);
        if (scanf(" %c %d", &rowChar, &colNum) != 2) {
            printf("Invalid input format. Try again.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        rowChar = toupper(rowChar);
        int rIndex = rowChar - 'A';
        int cIndex = colNum - 1;

        if (rIndex < 0 || rIndex >= ROWS || cIndex < 0 || cIndex >= COLS) {
            printf("Error: Seat out of range. Row must be A-E and Column 1-10.\n");
            continue;
        }

        if (movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].status == 'X') {
            printf("Error: Seat %c%d is already booked! Please pick another seat.\n", rowChar, colNum);
            continue;
        }

        double basePrice = 0.0;
        if (rIndex == 0 || rIndex == 1)      basePrice = 500.0;
        else if (rIndex == 2 || rIndex == 3) basePrice = 750.0;
        else if (rIndex == 4)               basePrice = 1000.0;

        double finalSeatPrice = basePrice * (1.0 - totalDiscount);

        movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].status = 'X';
        strcpy(movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].customerName, customerName);
        movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].pricePaid = finalSeatPrice;

        grandTotal += finalSeatPrice;
        bookedCount++;

        printf(" -> Seat %c%d reserved! Base: Rs. %.2f | Final: Rs. %.2f\n", 
               rowChar, colNum, basePrice, finalSeatPrice);
    }

    printf("--------------------------------------------------\n");
    printf("Booking Successful for %s!\n", customerName);
    printf("Movie: %s (%s)\n", movies[mIndex].name, movies[mIndex].showtimes[sIndex].time);
    printf("Total Amount Paid: Rs. %.2f\n\n", grandTotal);
}