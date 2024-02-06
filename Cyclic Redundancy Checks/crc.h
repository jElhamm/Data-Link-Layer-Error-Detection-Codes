// This code is a header file crc.h that defines constants, function prototypes,
// and external variables related to a CRC (Cyclic Redundancy Check) algorithm



#ifndef CRC_H
#define CRC_H
#include <stdint.h>
#include <stdbool.h>
#define WIDTH 32
#define TOPBIT (1u << (WIDTH - 1))
#define POLYNOMIAL 0x04C11DB7
extern uint32_t crcTable[256];


void generateCRCTable();
uint32_t calculateCRC(char *data);
bool checkErrorCRC(char *data, uint32_t crc);

#endif