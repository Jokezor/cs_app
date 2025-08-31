#include <assert.h>
#include <stdio.h>
/* Declaration of data type where 4 bytes are packed
into an unsigned */

typedef unsigned packed_t;

/* Extract byte from word.
Return as signed integer */
int xbyte(packed_t word, int bytenum);

/* Failed attempt at xbyte */
int xbyte(packed_t word, int bytenum)
{
    // Ah, the bytes are signed, meaning that the first bit is a sign bit.
    // It does not handle negative values.

    // Fix with left, right and subtraction.
    int w = 3;
    int shift_bits = (w - bytenum) << 3;
    return ((int) word << shift_bits) >> 24;
}


int main() {
    assert(xbyte(0xFFFFFFFF, 0) == -1);
    assert(xbyte(0x0A000000, 3) == 0x0A);
    assert(xbyte(0x00112233, 0) == 0x33);
    assert(xbyte(0x00112233, 1) == 0x22);
    assert(xbyte(0x00112233, 2) == 0x11);
    assert(xbyte(0x00112233, 3) == 0x00);

    assert(xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD);
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0xAABBCCDD, 2) == 0xFFFFFFBB);
    assert(xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);
    return 0;
}
