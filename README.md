# Movie Booking System Group Project for CSC 1031
This is the repository we created for the group project for CSC 1031 - Software Development Fundamentals.

## Program Summary
This program is a command-line program built in C, that can be used in a theater to manage seat bookings and ticket pricing for a set of movie showtimes.

## Functionality
1. View Showtimes - List all movies and their available showtimes
2. View Seat Map - Print the seat grid for a chosen showtime, showing free (.) vs booked (X) seats, with tiers indicated
3. Book a Seat - Customer picks a showtime and seat; system checks availability, calculates price based on seat tier and any discount, and records the booking
4. Cancel a Booking - Free up a seat and remove it from revenue calculations
5. Search Booking - Find a booking by customer name or seat number, showing the price paid
6. View Revenue Report - Calculate and display total tickets sold and total revenue per showtime


## How to Build and Run

### Compilation
Build the complete project using `gcc`:

```bash
gcc *.c -o movie_booking
```

### Running the Program
Execute the compiled binary:

```bash
./movie_booking
```


## Group Members

- **Linuka Wijesinghe**   — [GitHub Profile](https://github.com/linuka135-cyber) | **Index No:** AS20250368
- **Lochana Ranathunga**  — [GitHub Profile](https://github.com/lochanalmr)      | **Index No:** AS20250450
- **Sadeep Shyamal**      — [GitHub Profile](https://github.com/sadeepshyamal)    | **Index No:** AS20250500
- **Kavisha Alwis**       — [GitHub Profile](https://github.com/kkkalwis)         | **Index No:** AS20250543
- **Daham Makumbura**     — [GitHub Profile](https://github.com/daham1026)        | **Index No:** AS20250573

