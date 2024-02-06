/**
  * This code is an implementation of a CRC (Cyclic Redundancy Check) algorithm
  *  used to generate and verify CRC values for data to detect errors during data transmission or storage. 
**/



#include "crc.h"
#include <string.h>
#include <stdio.h>

uint32_t crcTable[256];

// Function to generate the CRC table
void generateCRCTable() {
    for (uint32_t i = 0; i < 256; i++) {
        uint32_t crc = i << (WIDTH - 8);                                        // Calculate CRC value for the current index
        for (uint32_t j = 0; j < 8; j++) {                                      // Loop through 8 bits
            crc = (crc & TOPBIT) ? ((crc << 1) ^ POLYNOMIAL) : (crc << 1);      // Perform CRC calculation
        }
        crcTable[i] = crc;                                                      // Store the calculated CRC value in the table
    }
}

// Function to calculate CRC value for given data
uint32_t calculateCRC(char *data) {
    uint32_t crc = 0xFFFFFFFF;
    size_t dataSize = strlen(data);
    for (size_t i = 0; i < dataSize; i++) {                                     // Loop through each character in the input data
        crc = (crc << 8) ^ crcTable[((crc >> (WIDTH - 8)) ^ data[i]) & 0xFF];   // Update the CRC value
    }
    return crc;     
}
 
// Function to check if CRC matches the calculated CRC from the data
bool checkErrorCRC(char *data, uint32_t crc) {
    uint32_t calculatedCRC = calculateCRC(data);
    return crc == calculatedCRC;
}