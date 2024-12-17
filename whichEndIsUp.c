#include <stdio.h>
// function to determine system endianness
void checkSystemEdnianness() {
    // create a union that contains an integer and an array of bytes
    union {
        unsigned int i;
        unsigned char byte[sizeof(unsigned int)];
    } number;    

    // Assign a value to the integer part where you can easily see byte order

    number.i = 0x1;

    //check the first byte of the union
    if (number.bytep[0] == 0x1) {
        printf("System is little-endian.\n");
    } else {
        printf("system is big-endian.\n");

    }


    }
    
    int main () {
        // check and print the system's endianness
        checkSystemEdnianness();
        return 0;
    }
