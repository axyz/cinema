#ifndef HASH_H
#define HASH_H

/**
 * Makes a hash from a string.
 * Intended to be used to generate unique ids for the Bookings.
 * @param string the string to be hashed.
 * @return the hash number as an unsigned long.
 */
unsigned long hash(char *string);

#endif
