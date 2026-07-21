#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cancel_booking.h"

static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cancelBooking(struct Movie movies[]) {
    int movieId, showtimeId;
    char rowChar;
    int colNum;

    printf("\n--- Cancel a Booking ---\n");

    
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

    
    printf("Enter Row (A-E) and Column (1-10) to cancel [e.g., A 5]: ");
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

    
    if (movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].status != 'X') {
        printf("Error: Seat %c%d is not currently booked.\n", rowChar, colNum);
        return;
    }

    
    double refundedAmount = movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].pricePaid;
    char cancelledCustomer[50];
    strcpy(cancelledCustomer, movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].customerName);

    
    movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].status = '.';
    movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].customerName[0] = '\0';
    movies[mIndex].showtimes[sIndex].seats[rIndex][cIndex].pricePaid = 0.0;

  
    printf("\n--------------------------------------------------\n");
    printf("Cancellation Successful!\n");
    printf("Movie: %s (%s)\n", movies[mIndex].name, movies[mIndex].showtimes[sIndex].time);
    printf("Seat: %c%d\n", rowChar, colNum);
    printf("Customer: %s\n", cancelledCustomer);
    printf("Refunded Amount: Rs. %.2f\n", refundedAmount);
    printf("--------------------------------------------------\n\n");
}