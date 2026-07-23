#include <stdio.h>
#include "revenue_report.h"

void viewRevenueReport(struct Movie movies[]) {
    int grandTicketsSold = 0;
    double grandRevenue = 0.0;

    printf("\n--- Revenue Report ---\n");
    printf("+----------+---------------------------+------------+--------------+----------------+\n");
    printf("| Movie ID | Movie Name                | Showtime   | Tickets Sold | Revenue (Rs.)  |\n");
    printf("+----------+---------------------------+------------+--------------+----------------+\n");

    for (int m = 0; m < MOVIE_COUNT; m++) {
        for (int s = 0; s < SHOWTIMES_PER_MOVIE; s++) {
            int ticketsSold = 0;
            double revenue = 0.0;

            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (movies[m].showtimes[s].seats[r][c].status == 'X') {
                        ticketsSold++;
                        revenue += movies[m].showtimes[s].seats[r][c].pricePaid;
                    }
                }
            }

            printf("| %-8d | %-25s | %-10s | %-12d | %14.2f |\n",
                   movies[m].id,
                   movies[m].name,
                   movies[m].showtimes[s].time,
                   ticketsSold,
                   revenue);

            grandTicketsSold += ticketsSold;
            grandRevenue += revenue;
        }
    }

    printf("+----------+---------------------------+------------+--------------+----------------+\n");
    printf("Total Tickets Sold: %d\n", grandTicketsSold);
    printf("Total Revenue: Rs. %.2f\n\n", grandRevenue);
}
