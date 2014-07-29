#ifndef CINEMA_H
#define CINEMA_H

#define MAX_SEATS 256
#define MAX_ROWS 256

/**
 * The max number of seats that can be reserved during a booking.
 */
#define MAX_BOOKING_SEATS 16

typedef unsigned char Number;

typedef Number Bool;

/**
 * Struct representing a row of seats.
 * If seat[n] is set to 0 then the seat n is available.
 * If seat[n] is set to 1 then the seat n is occupied.
 * seat[n] refers to the physical seat in the row labeled n.
 */
typedef struct {
  Bool seat[MAX_SEATS]; /**< Bool array representing the seats */
} Row;

/**
 * Struct representing a thater.
 * row[n] refers to the physical row in the theater labeled n.
 */
typedef struct {
  Row row[MAX_ROWS]; /**< row is in array of Rows */
} Theater;

/**
 * Struct representing a Seat.
 * Not used for the representation of the theater,
 * but used in the booking process to identify a single seat.
 */
typedef struct {
  Number row; /**< row is the row number */
  Number num; /**< num is the seat number */
} Seat;

/**
 * Struct representing a Booking.
 * Each booking needs a list of seats it refers to.
 * A booking is identified by a uniquie id.
 */
typedef struct {
  unsigned long id; /**< an id to identify the booking */
  Seat seats[MAX_BOOKING_SEATS]; /**< the list of Seat the Booking refers to */
} Booking;

/**
 * Get the value (0 or 1) of the speicifed seat.
 * @see Theater
 * @param theater a pointer to a theater representation.
 * @param row the row number of the seat.
 * @param seat the seat number.
 * @return the flag of the seat (0: available, or 1: occupied). 
 */
Bool getSeat(Theater *theater, Number row, Number seat);

/**
 * Set the value of the speicifed seat to 1 (occupied).
 * @see Theater
 * @param theater a pointer to a theater representation.
 * @param row the row number of the seat.
 * @param seat the seat number. 
 */
void setSeat(Theater *theater, Number row, Number seat);

/**
 * Set the value of the speicifed seat to 0 (available).
 * @see Theater
 * @param theater a pointer to a theater representation.
 * @param row the row number of the seat.
 * @param seat the seat number.
 */
void clrSeat(Theater *theater, Number row, Number seat);

/**
 * Creates a Booking struct from a list of seats.
 * @see Booking
 * @see Seat
 * @param seat[] an array containing the seats the Booking refers to.
 * @return a pointer to the Booking created.
 */
Booking *makeBooking(Seat seats[]);

/**
 * Execute a Booking updating the theater representation.
 * @see Booking
 * @see Theater
 * @param booking a pointer to a Booking.
 * @param theater a pointer to a Theater.
 */
Bool book(Booking *booking, Theater *theater);

#endif
