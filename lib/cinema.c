#include "cinema.h"

char *getSeat(*theatre, row, seat)
{
  int segment = seat / 16;
  int offset = seat % 16;
  return getBit(theatre[row - 1][segment], offset);
}
