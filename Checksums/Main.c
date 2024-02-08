/**
  * This C program calculates and verifies checksums for input data.
  * It reads user input, calculates the checksum for the input data, and then verifies the checksum for received data.
  * If the checksum matches, it indicates no errors; otherwise, it detects a checksum error.
**/



#include <stdio.h>
#include <string.h>
#include "Checksums.h"
#define MAX_SIZE 1000


int main() {
    char data[MAX_SIZE];
    unsigned short checksum;
    printf("\n*******************************************************************************");
    printf("---> Enter the data to calculate checksum: ");
    fgets(data, MAX_SIZE, stdin);
    // Removing newline character from input
    data[strcspn(data, "\n")] = 0;
    int dataSize = strlen(data);
    checksum = calculateChecksum(data, dataSize);
    printf("---> Checksum calculated: 0x%04X\n", checksum);
    // Verification
    printf("---> Enter the received data to verify: ");
    fgets(data, MAX_SIZE, stdin);
    data[strcspn(data, "\n")] = 0;
    if (verifyChecksum(data, dataSize)) {
        printf("*** No error in received data. Checksum verified. ***\n");
    } else {
        printf("  ( ! Error in received data. Checksum does not match. ! )\n");
    }
    return 0;
    printf("*******************************************************************************\n");
}