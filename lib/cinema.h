#ifndef CINEMA_H
#define CINEMA_H

typedef unsigned char Number;
typedef Number[128][16] Theatre; 

char getSeat(Theatre *theatre, Number row, Number seat);

#endif
