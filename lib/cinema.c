#include "cinema.h"
#include "bits.h"

Number getSeat(Theatre *theatre, Number row, Number seat)
{
  Number segment = seat / 16;
  Number offset = seat % 16;
  return GET_BIT(theatre[row - 1][segment], offset);
}
