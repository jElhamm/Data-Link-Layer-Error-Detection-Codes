/**
  * This code defines two functions for checksum operations. 

  * 1. `calculateChecksum`: It calculates the checksum by summing up all elements in the data array,
  *     carrying over any overflow, and then taking the one's complement of the final sum as the checksum.
   
  * 2. `verifyChecksum`: It calls `calculateChecksum` and returns `1` if the calculated checksum is `0`,
  *     indicating a valid checksum, or `0` otherwise.

  * These functions are used for data integrity checks using checksums.
**/



#include "Checksums.h"


// Calculate the checksum of the data array
unsigned short calculateChecksum(char data[], int size) {
    unsigned int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return (unsigned short)(~sum);
}

// Verify if the calculated checksum is 0, indicating data integrity
int verifyChecksum(char data[], int size) {
    return calculateChecksum(data, size) == 0;
}