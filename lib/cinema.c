#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cinema.h"
#include "hash.h"

Bool getSeat(Theater *theater, Number row, Number seat)
{
  return theater->row[row].seat[seat];
}

void setSeat(Theater *theater, Number row, Number seat)
{
  theater->row[row].seat[seat] = 1;
}

void clrSeat(Theater *theater, Number row, Number seat)
{
  theater->row[row].seat[seat] = 0;
}

/*
 * TO-FIX: result in an abort trap 6
 * TO-FIX: not a big issue, but it adds some random char at the end.
 * setting ret to [MAX_BOOKING_SEATS * 8] removes random chars,
 * but do not adds the final #.
 */
void seatsToString(Seat seats[], char *str, Number size)
{
  char ret[MAX_BOOKING_SEATS * 8 + 1] = "#";
  char tmp[8];
  Number i;
  for(i = 0; i < size; i++) {
    snprintf(tmp, 9, "%d:%d#", seats[i].row, seats[i].num);
    strcat(ret, tmp);
  }
  memcpy(str, ret, sizeof(ret));
}

Booking *makeBooking(Seat seats[], Number size)
{
  unsigned long id;
  /* str max size will be MAX_BOOKING_SEATS * 8 (255:255#) + 1 (initial #)*/
  char *str;
  seatsToString(seats, str, size);
  id = hash(str);
  Booking *b = (Booking*)malloc(sizeof(Booking));
  b->id = id;
  b->size = size;
  memcpy(b->seats, seats, sizeof(Seat) * size);
  return b;
}

char book(Booking *booking, Theater *theater, char *err)
{
  char *error;
  Number i;
  for(i = 0; i < booking->size; i++) {
    Number row = booking->seats[i].row;
    Number num = booking->seats[i].num;
    if(getSeat(theater, row, num) == 1) {
      snprintf(err, 128, "error: the seat N°%d in the row N°%d is already reserved.", num, row);
      return -1;
    }
  }
  for(i = 0; i < booking->size; i++) {
    setSeat(theater, booking->seats[i].row, booking->seats[i].num);
  }
  return 0;
}
