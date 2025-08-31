#include <stdio.h>
#include <assert.h>

/*
* Return 1 when x can be represented as an n-bit, 2’s-complement
* number; 0 otherwise
* Assume 1 <= n <= w
*/
// Your function should follow the bit-level integer coding rules (page 164).
int fits_bits(int x, int n);


int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    int offset = w - n;

    // No bits set that won't fit.
    // Then shift back
    // x << offset >> offset == x;
    return ((x << offset) >> offset) == x;
}

int main() {
    assert(fits_bits(8, 5));
    assert(fits_bits(-1, 16));
    return 0;

}
