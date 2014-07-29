#include <stdlib.h>
#include <string.h>

#include "cinema.h"

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

Booking *makeBooking(Seat seats[])
{
  // TO-DO
  unsigned long id = 12345;
  Booking *b = (Booking*)malloc(sizeof(Booking));
  b->id = id;
  memcpy(b->seats, seats, sizeof(seats));
  return b;
}

Bool book(Booking *booking, Theater *teater)
{
  // TO-DO
  return 0;
}
