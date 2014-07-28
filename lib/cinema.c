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
  Booking b = {"asdfghjklqwert", seats};
  return &b;
}

Bool book(Booking *booking, Theater *teater)
{
  // TO-DO
  return 0;
}
