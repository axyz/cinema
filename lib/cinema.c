#include "cinema.h"
#include "bits.h"

Bool getSeat(Theater *theater, Number row, Number seat)
{
  Number segment = seat / (NSEATS / 8);
  Number offset = seat % (NSEATS / 8);
  return GET_BIT(theater->row[row - 1].seat[segment], offset) ? 1 : 0;
}

void setSeat(Theater *theater, Number row, Number seat)
{
  Number segment = seat / (NSEATS / 8);
  Number offset = seat % (NSEATS / 8);
  SET_BIT(theater->row[row - 1].seat[segment], offset);
}

void clrSeat(Theater *theater, Number row, Number seat)
{
  Number segment = seat / (NSEATS / 8);
  Number offset = seat % (NSEATS / 8);
  CLR_BIT(theater->row[row - 1].seat[segment], offset);
}
