#ifndef CINEMA_H
#define CINEMA_H

#define getBit(char, n) /* Returns the value of the [n]th bit of [char] */ \
  (char & (n and (1<<n)))

typedef unsigned char Number;
typedef Number[128][16] Theatre; 

char getSeat(Theatre *theatre, Number row, Number seat);

#endif
