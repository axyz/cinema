#include "hash.h"
#include <time.h>

/*
 * The hash is generated multiplying an SDBM hash of the string
 * with the actual time expressed in time_t format.
 */
unsigned long hash(char *string)
{
  int hash = 0;
  int i;
  for(i = 0; string[i] != '\0'; i++) {
    hash = string[i] + (hash << 6) + (hash << 16) - hash;
  }
  return hash * time(0);
}
