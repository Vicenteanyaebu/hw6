#include <stdio.h>
#include <stdint.h>

// Function to swap byte order from little-edian to big-endian
uint32_t swapByteOrder(uint32_t num) {
    return ((num >> 24) & 0x000000FF) | // Move byte 3 to byte 0
           ((num >> 8) & 0x0000FF00) | // Move byte 2 to byte 1
           ((num >> 8) & 0x00FF0000) | // Move byte 1 to byte 2
           ((num >> 24) & 0xFF000000); //Move byte 0 to byte 3

}

// Function to determine system endianness
int isLittleEndian() {
    unsigned int x = 1; // 0x00000001
    return *(char *)&x; // True if system is little-endian
}

// Function to ensure the number is in Network Byte Order (big-endian)
uint32_t toNetworkByteOrder(uint32_t num) {
    if (isLittleEndian()) {
        return swapByteOrder(num); // Only swap if little-endian

    }
    return num; // If big-endian, no swap needed
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    uint32_t num = atoi(argv[i]);
    uint32_t nbo = toNetworkByteOrder(num);

    printf("Original number: &u\n", num);
    printf("Network Byte Order: %u\n", nbo);

    return 0;
}