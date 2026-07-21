#ifndef VIEW_SHOWTIMES_H
#define VIEW_SHOWTIMES_H

#define MOVIE_COUNT 3
#define SHOWTIMES_PER_MOVIE 2
#define ROWS 5
#define COLS 10

struct Seat {
    char status;  
    char customerName[50];
    double pricePaid;
};

struct Showtime {
    char time[10];
    struct Seat seats[ROWS][COLS];
};

struct Movie {
    int id;
    char name[50];
    struct Showtime showtimes[SHOWTIMES_PER_MOVIE];
};

void showMoviesList(struct Movie movies[]);

#endif