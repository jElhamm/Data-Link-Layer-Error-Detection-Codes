// This code is a simple program that takes user input for the number of data bits and the actual data bits (0s and 1s),
// calculates the Hamming Code for the input data, and then displays the generated Hamming Code.



#include <stdio.h>
#include "hamming.h"


int main() {
    int dataBits;
    printf("\n****************************************************************");
    printf("Enter the number of data bits: ");
    scanf("%d", &dataBits);
    int data[dataBits];
    printf("Enter the data bits (separated by spaces - 0 or 1): ");
    for (int i = 0; i < dataBits; i++) {
        scanf("%d", &data[i]);
    }
    calculateHammingCode(data, dataBits);
    printf("*****************************************************************\n");
    return 0;
}