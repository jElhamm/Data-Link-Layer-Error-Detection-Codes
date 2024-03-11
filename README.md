# Data Link Layer Error Detection Codes

   This repository contains implementations of various *Error Detection Codes* used in the [Data Link Layer](https://en.wikipedia.org/wiki/Data_link_layer) of computer networks.


## Overview

   In the Data Link Layer of the OSI model, error detection codes are used to detect errors that may
   occur during data transmission over a communication channel. These codes are added to the data before transmission
   and are recalculated by the receiver to verify the integrity of the received data.
   Common error detection codes include parity bits, checksums, and cyclic redundancy checks (CRC).
   These codes allow the receiver to determine if any errors have occurred during data transmission
   and take appropriate actions to request retransmission or correct the errors.

## Algorithms Implemented:

   1. [Checksums](Checksums)
   2. [Hamming Codes](Hamming%20Codes)
   3. [Cyclic Redundancy Checks (CRC)](Cyclic%20Redundancy%20Checks)
   4. [Low-Density Parity Check (LDPC) Codes](Low-Density%20Parity%20Check%20Codes)

## Usage

   You can find the implementation of each algorithm in the respective directories within this repository.


## Algorithms Summary

   * *Checksums*: Checksums are a simple error detection technique where the sender calculates a checksum value by summing up the bytes in the data and appends it to the data. The receiver recalculates the checksum and verifies if it matches the received checksum to detect errors. If the checksums don't match, an error is detected.

   * *Hamming Codes*: Hamming codes are error-correcting codes that add redundant bits to the data to detect and correct errors. In Hamming codes, parity bits are added at specific positions in the data to create a code word. These parity bits help in identifying and correcting single-bit errors in the received data.

   * *Cyclic Redundancy Checks (CRC)*: CRC is a more sophisticated error detection technique that involves polynomial division. The sender generates a CRC based on the data and appends it to the message. The receiver performs the same polynomial division and compares the calculated CRC with the received one. If they differ, an error is detected.

   * *Low-Density Parity Check (LDPC) Codes*: LDPC codes are linear error-correcting codes that offer excellent error detection and correction capabilities. These codes have a sparse parity-check matrix structure, making them efficient in terms of error correction performance. LDPC codes are widely used in modern communication systems.

## References
 
   * [Error Detection and Correction in Data link Layer](https://www.tutorialspoint.com/error-detection-and-correction-in-data-link-layer)
   * [Error Detection in Computer Networks](https://www.geeksforgeeks.org/error-detection-in-computer-networks/)
   * [What Is Regression? Definition, Calculation, and Example](https://www.investopedia.com/terms/r/regression.asp#:~:text=A%20regression%20is%20a%20statistical,more%20of%20the%20explanatory%20variables.)



   BOOK:
   Computer Networks (Andrew s. Tanenbaum)

## License

   This repository is licensed under the MIT License.
   See the [LICENSE](./LICENSE) file for more details.