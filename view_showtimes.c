#include <stdio.h>
#include "view_showtimes.h"

void showMoviesList(struct Movie movies[])
{
    printf("+----------+---------------------------+------------+------------+\n");
    printf("| Movie ID | Movie Name                | Showtime 1 | Showtime 2 |\n");
    printf("+----------+---------------------------+------------+------------+\n");

    for(int i = 0; i < MOVIE_COUNT; i++)
    {
        printf("| %-8d | %-25s | %-10s | %-10s |\n",
               movies[i].id,
               movies[i].name,
               movies[i].showtimes[0].time,
               movies[i].showtimes[1].time);
    }

    printf("+----------+---------------------------+------------+------------+\n");
}