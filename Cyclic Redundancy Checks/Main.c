// This program is a simple example of using CRC (Cyclic Redundancy Check) for error detection in data transmission. 



#include <stdio.h>
#include "crc.h"


int main() {
    char data[100];
    printf("\n****************************************************");
    printf("---> Enter the data to be sent: ");
    scanf("%s", data);
    generateCRCTable();
    uint32_t crc = calculateCRC(data);
    printf("---> CRC code: %u\n", crc);
    if (!checkErrorCRC(data, crc)) {
        printf("   ( ! Error detected in the sent data ! )\n");
    } else {
        printf("---> Data is error-free!\n");
    }
    printf("****************************************************\n");
    return 0;
}