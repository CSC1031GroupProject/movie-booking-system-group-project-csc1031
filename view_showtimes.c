#include <stdio.h>
#include "view_showtimes.h"


void showMoviesList()
{
    struct Movie movies[MOVIE_COUNT] = {
        {1, "Spider-Man: Brand New Day", "10:00 AM", "6:30 PM"},
        {2, "The Odyssey", "1:30 PM", "8:00 PM"},
        {3, "Moana 2", "11:00 AM", "4:30 PM"}
    };

    printf("+----------+---------------------------+------------+------------+\n");
    printf("| Movie ID | Movie Name                | Showtime 1 | Showtime 2 |\n");
    printf("+----------+---------------------------+------------+------------+\n");

    for(int i = 0; i < MOVIE_COUNT; i++)
    {
        printf("| %-8d | %-25s | %-10s | %-10s |\n",
               movies[i].id,
               movies[i].name,
               movies[i].showtime1,
               movies[i].showtime2);
    }

    printf("+----------+---------------------------+------------+------------+\n");
}
