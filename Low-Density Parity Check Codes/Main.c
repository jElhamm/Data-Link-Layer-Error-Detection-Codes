/**
  * This C program prompts the user to input a message length and message bits.
  * It then checks the input message for parity and processes it using LDPC encoding and decoding operations.
  * Finally, it displays appropriate error messages if needed.
**/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ldpc_operations.h"


int main() {
    int len;
    char message[MAX_SIZE];
    printf("\n******************************************************************");
    printf("---> Enter the length of the message: ");
    scanf("%d", &len);
    printf("---> Enter the message bits (e.g., 101011): ");
    printf("******************************************************************\n");
    scanf("%s", message);
    if (strlen(message) != len) {
        printf("  ( ! Error: Length of the message does not match the input ! )\n");
        return 1;
    }
    if (!checkEvenParity(message, len)) {
        printf("  ( ! Error: Input message does not have even parity ! )\n");
        return 1;
    }
    encodeLDPC(message, len);
    decodeLDPC(message, len);
    printf("******************************************************************\n");
    return 0;
}