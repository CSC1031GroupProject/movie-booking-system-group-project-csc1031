#ifndef VIEW_SHOWTIMES_H
#define VIEW_SHOWTIMES_H

#define MOVIE_COUNT 3

struct Movie {
    int id;
    char name[50];
    char showtime1[10];
    char showtime2[10];
};

void showMoviesList();

#endif