#include "cinema.h"

Number *getSeat(Theatre *theatre, Number row, Number seat)
{
  Number segment = seat / 16;
  Number offset = seat % 16;
  return getBit(theatre[row - 1][segment], offset);
}
