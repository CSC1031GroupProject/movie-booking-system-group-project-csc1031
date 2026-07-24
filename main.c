#include <stdio.h>
#include "menu.h"
#include "view_showtimes.h"
#include "view_seatmap.h"
#include "book_seat.h"
#include "cancel_booking.h"
#include "search_booking.h"
#include "revenue_report.h"

void initializeSeats(struct Movie movies[]);

int main(){
    struct Movie movies[MOVIE_COUNT] = {
        {1, "Spider-Man: Brand New Day", {{"10:00 AM"}, {"6:30 PM"}}},
        {2, "The Odyssey",               {{"1:30 PM"},  {"8:00 PM"}}},
        {3, "Moana 2",                   {{"11:00 AM"}, {"4:30 PM"}}}
    };
    
    initializeSeats(movies);

    int option = 0;
    
    while (1) {
        option = menu();

        switch (option){
            case 1:
                showMoviesList(movies);
                break;
            
            case 2:
                viewSeatMap(movies);
                break;

            case 3:
                bookSeat(movies);
                break;

            case 4:
                cancelBooking(movies);
                break;

            case 5:
                searchBooking(movies);
                break;

            case 6:
                viewRevenueReport(movies);
                break;

            case 7:
                printf("Exiting program...\n");
                return 0;
        }
    }
    return 0;
}

void initializeSeats(struct Movie movies[]) {
    for (int m = 0; m < MOVIE_COUNT; m++) {
        for (int s = 0; s < SHOWTIMES_PER_MOVIE; s++) {
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    movies[m].showtimes[s].seats[r][c].status = '.';
                    movies[m].showtimes[s].seats[r][c].customerName[0] = '\0';
                    movies[m].showtimes[s].seats[r][c].pricePaid = 0.0;
                }
            }
        }
    }
}