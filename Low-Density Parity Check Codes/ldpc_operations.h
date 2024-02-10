// This code snippet is a header file 'ldpc_operations.h'. It defines the maximum size of a message as 100 characters



#ifndef LDPC_OPERATIONS_H
#define LDPC_OPERATIONS_H
#define MAX_SIZE 1000


int checkEvenParity(char *message, int len);

#endif



/**
  * Additionally, it declares three functions related to LDPC (Low-Density Parity-Check) operations:

  * 1. `checkEvenParity`: Takes a message and its length as input and checks if the message has even parity, returning a boolean result.
   