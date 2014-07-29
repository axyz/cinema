#ifndef CINEMA_H
#define CINEMA_H

#define MAX_SEATS 256
#define MAX_ROWS 256
#define MAX_BOOKING_SEATS 16

typedef unsigned char Number;

typedef Number Bool;

typedef struct {
  Bool seat[MAX_SEATS];
} Row;

typedef struct {
  Row row[MAX_ROWS];
} Theater;

typedef struct {
  Number row;
  Number num;
} Seat;

typedef struct {
  unsigned long id;
  Seat seats[MAX_BOOKING_SEATS];
} Booking;

Bool getSeat(Theater *theater, Number row, Number seat);
void setSeat(Theater *theater, Number row, Number seat);
void clrSeat(Theater *theater, Number row, Number seat);

Booking *makeBooking(Seat seats[]);
Bool book(Booking *booking, Theater *theater);

#endif
