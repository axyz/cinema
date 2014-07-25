#ifndef CINEMA_H
#define CINEMA_H

#define getBit(char, n) /* Returns the value of the [n]th bit of [char] */ \
  (char & (n and (1<<n)))

typedef char[16][16] theatre; 

char getSeat(*theatre, row, seat);

#endif
