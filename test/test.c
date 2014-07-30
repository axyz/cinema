#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/md5.h>
#include "../lib/cinema.h"
#include "../lib/hash.h"

int main()
{
  Theater *broadway = malloc(sizeof(Theater));
  //setSeat(broadway, 2, 1);
  setSeat(broadway, 55, 45);
  setSeat(broadway, 0, 0);
  setSeat(broadway, 255, 255);
  clrSeat(broadway, 55, 45);
  /*asm("int3");*/
  printf("%o\n", getSeat(broadway, 0, 0));
  printf("%o\n", getSeat(broadway, 0, 1));
  printf("%o\n", getSeat(broadway, 1, 0));
  printf("%o\n", getSeat(broadway, 1, 1));
  printf("%o\n", getSeat(broadway, 1, 2));
  printf("%o\n", getSeat(broadway, 2, 1));
  printf("%o\n", getSeat(broadway, 55, 45));
  printf("%o\n", getSeat(broadway, 255, 255));
  printf("%d\n", sizeof(*broadway));
  printf("%lu\n", hash("55:33#33:44#33:22#78:33#23:12#66:64#36:75#12:67#54:86#12:67"));
  Seat seats[] = {
    {110, 122}, 
    {122, 214}, 
    {116, 146},
    {222, 215},
    {232, 215},
    {142, 125},
    {122, 155},
    {152, 145},
    {142, 135},
    {122, 135},
    {152, 135},
    {112, 115},
    {222, 115},
    {122, 215},
    {122, 125},
    {222, 225},
  };
  Booking *b = makeBooking(seats, 16);
  printf("%lu\n", b->seats[14].row);
  char *str[128];
  seatsToString(seats, str, 16);
  printf("%s\n", str);
  char *err[128];
  Seat seats2[] = {
    {3, 3},
    {6, 7}
  };
  setSeat(broadway, 6, 8);
  Booking *b2 = makeBooking(seats2, 2);
  printf("%d\n", book(b2, broadway, err));
  printf("%s\n", err);
  printf("%d\n", getSeat(broadway, 6, 7));
  return 0;
}
