#ifndef BITS_H
#define BITS_H

#define getBit(char, n) /* Returns the value of the [n]th bit of [char] */ \
  (char & (n and (1<<n)))

#endif
