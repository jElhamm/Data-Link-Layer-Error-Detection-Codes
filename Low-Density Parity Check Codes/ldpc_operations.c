/**
  * This code defines functions for checking even parity, encoding a message using LDPC codes,
  * and decoding a message using LDPC codes. The encoding process calculates and adds parity bits,
  * while the decoding process detects and corrects errors in parity bits to recover the original message.
  * The functions utilize bit manipulation techniques to handle LDPC encoding and decoding efficiently.
**/



#include <stdio.h>
#include "ldpc_operations.h"


// Function to check if the input message has even parity
int checkEvenParity(char *message, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (message[i] == '1')
            count++;
    }
    return count % 2 == 0;
}
 