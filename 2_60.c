/*
2.60 ◆◆
Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 −1
(most significant). Write code for the following C function, which will return an
unsigned value in which byte i of argument x has been replaced by byte b:

unsigned replace_byte (unsigned x, int i, unsigned char b);

Here are some examples showing how the function should work:
replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
*/
#include<assert.h>
#include<stdio.h>

typedef unsigned char *byte_pointer;

unsigned replace_byte_simple(unsigned x, int i, unsigned char b) {
    /*
    replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
    replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
    */
    // Hmm, to do this, we could simply convert the unsigned x into a unsigned char pointer.
    // Then we replace AB?
    // Lets think of other ways.
    // We could maybe do a union on these bits? But nope, first the bits for that byte position need to be cleared.
    // Easiest is to convert.
    assert(i >= 0);
    assert(i <= sizeof(unsigned)-1);
    byte_pointer bytes = (byte_pointer) &x;
    bytes[i] = b;
    return x;
}


unsigned replace_byte(unsigned x, int i, unsigned char b) {
    assert(i >= 0);
    assert(i <= sizeof(unsigned)-1);
    // We could now clear the bits at index i.
    // If we xor, we would clear the common bits.
    // 1 byte has 8 bits. 
    // Basically, a byte with all 1s, bit shifted i bits.
    // (i << 3) == i*8;
    unsigned mask = unsigned((0xFF) << (i << 3));
    unsigned pos_byte = (b) << (i << 3);
    return (x & ~mask) | pos_byte;
}

int main() {
    assert(replace_byte(0x12345678, 2, 0xAB) == 0x12AB5678);
    assert(replace_byte(0x12345678, 0, 0xAB) == 0x123456AB);

    printf("Yey\n");
    return 0;
}
