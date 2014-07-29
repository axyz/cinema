#include "hash.h"
#include <time.h>

/*
  Hash function with a timestamp * SDBM hash of [string]
 */
unsigned long hash(char string[])
{
  int hash = 0;
  int i;
  for(i = 0; string[i] != '\0'; i++) {
    hash = string[i] + (hash << 6) + (hash << 16) - hash;
  }
  return hash * time(0);
}
