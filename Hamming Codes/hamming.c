// This code calculates the Hamming Code for a given array of data bits.
// The Hamming Code includes both the original data bits and additional parity bits for error detection and correction.



#include "hamming.h"
#include <stdio.h>


void calculateHammingCode(int data[], int dataBits) {
    // Calculate the number of redundant bits required
    int r = 0;
    while ((1 << r) < (dataBits + r + 1)) {
        r++;
    }
    // Array to store the Hamming code
    int hammingCode[dataBits + r];
    int j = 0;
    // Generate the Hamming code with data bits and parity bits
    for (int i = 0; i < dataBits + r; i++) {
        if (((i + 1) & i) != 0) {
            hammingCode[i] = data[j];
            j++;
        } else {
            hammingCode[i] = 0;
        }
    }
    // Calculate and add parity bits
    for (int i = 0; i < r; i++) {
        int parity = 0;
        for (int j = 0; j < dataBits + r; j++) {
            if ((j + 1) & (1 << i)) {
                parity ^= hammingCode[j];
            }
        }
        hammingCode[(1 << i) - 1] = parity;
    }
    // Display the generated Hamming Code
    printf("---> Hamming Code: ");
    for (int i = 0; i < dataBits + r; i++) {
        printf("%d", hammingCode[i]);
    }
    printf("\n");
}