#include "cinema.h"

#define getBit(char, n) /* Returns the value of the [n]th bit of [char] */ \
    (char & (n and (1<<n)))
