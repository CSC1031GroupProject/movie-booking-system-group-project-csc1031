#include <stdio.h>
#include "view_showtimes.h"
#include "view_seatmap.h"

void viewSeatMap(struct Movie movies[]) {
    int movieId, showtimeId;
    int c;

    printf("\n--- View Seat Map ---\n");
    printf("Enter Movie ID (1-3): ");
    scanf("%d", &movieId);
    
    while ((c = getchar()) != '\n' && c != EOF);

    if (movieId < 1 || movieId > MOVIE_COUNT) {
        printf("Error: Invalid Movie ID.\n");
        return;
    }

    printf("Enter Showtime (1 for first, 2 for second): ");
    scanf("%d", &showtimeId);

    while ((c = getchar()) != '\n' && c != EOF);

    if (showtimeId < 1 || showtimeId > SHOWTIMES_PER_MOVIE) {
        printf("Error: Invalid Showtime.\n");
        return;
    }

    int mIndex = movieId - 1;
    int sIndex = showtimeId - 1;

    printf("\nSeat Map for %s (%s)\n", movies[mIndex].name, movies[mIndex].showtimes[sIndex].time);
    printf("--------------------------------------------------\n");
    
    printf("       1  2  3  4  5  6  7  8  9 10\n"); 

    for (int r = 0; r < ROWS; r++) {
        char rowLabel = 'A' + r; 
        printf("Row %c  ", rowLabel);

        for (int col = 0; col < COLS; col++) {
            printf("%c  ", movies[mIndex].showtimes[sIndex].seats[r][col]);
        }

        if (r == 0 || r == 1) {
            printf("  [Regular]");
        } else if (r == 2 || r == 3) {
            printf("  [Premium]");
        } else if (r == 4) {
            printf("  [VIP]");
        }
        
        printf("\n");
    }
    
    printf("--------------------------------------------------\n");
    printf("Legend: '.' = Free, 'X' = Booked\n\n");
}