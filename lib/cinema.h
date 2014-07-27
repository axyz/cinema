#ifndef CINEMA_H
#define CINEMA_H

#define NROWS 32
#define NSEATS 32

typedef unsigned char Number;

typedef Number Bool;

typedef struct {
  Number seat[NSEATS/8];
} Row;

typedef struct {
  Row row[NROWS];
} Theater;

Bool getSeat(Theater *theater, Number row, Number seat);
void setSeat(Theater *theater, Number row, Number seat);
void clrSeat(Theater *theater, Number row, Number seat);

#endif
