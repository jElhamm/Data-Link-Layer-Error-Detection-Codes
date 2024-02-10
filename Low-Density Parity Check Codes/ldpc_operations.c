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

// Function to Encode the message using LDPC codes
void encodeLDPC(char *message, int len) {
    int i, j;
    int parityBits = len / 2;
    char parity[MAX_SIZE];
    // Generate parity bits
    for (i = 0; i < parityBits; i++) {
        int sum = 0;
        int factor = 1 << i;
        for (j = 0; j < len; j++) {
            if ((j + 1) & factor)
                sum += message[j] - '0';
        }
        parity[i] = (sum % 2) + '0';
    }

    // Display parity bits
    printf("---> Parity bits: ");
    for (i = 0; i < parityBits; i++) {
        printf("%c ", parity[i]);
    }
    printf("\n");
    // Add parity bits to the message
    for (i = 0; i < parityBits; i++) {
        message[(1 << i) - 1] = parity[i];
    }
    printf("---> Encoded message with LDPC: %s\n", message);
}

// Function to Decode the message using LDPC codes
void decodeLDPC(char *message, int len) {
    int i, j;
    int parityBits = len / 2;
    char parity[MAX_SIZE];
    // Extract parity bits from encoded message
    for (i = 0; i < parityBits; i++) {
        parity[i] = message[(1 << i) - 1];
    }
    // Check parity bits for errors
    printf("---> Detected Parity Errors: ");
    for (i = 0; i < parityBits; i++) {
        int sum = 0;
        int factor = 1 << i;
        for (j = 0; j < len; j++) {
            if ((j + 1) & factor) {
                sum += message[j] - '0';
            }
        }
        if (sum % 2 != 0) {
            printf("Bit %d, ", (1 << i) - 1);
            // Correct error by flipping the bit
            message[(1 << i) - 1] = (message[(1 << i) - 1] == '0') ? '1' : '0';
        }
    }
    // Display corrected message
    printf("\n---> Corrected message: %s\n", message);
}