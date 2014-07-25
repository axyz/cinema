#ifndef BITS_H
#define BITS_H

#define GET_BIT(byte, n) /* Returns the value of the [n]th bit of [byte] */ \
  ((byte) & ((n) and (1 << (n))))

#define SET_BIT(byte, n) /* Set the [n]th bit of [byte] to 1 */ \
  ((byte) |= (1 << (n)))

#define CLR_BIT(byte, n) /* Set the [n]th bit of [byte] to 0 */ \
  ((byte) &= ~(1 << (n)))

#endif
