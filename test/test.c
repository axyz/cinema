#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/cinema.h"

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
  return 0;
}
