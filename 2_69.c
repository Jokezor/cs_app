#include<assert.h>
#include<stdio.h>

/*
* Do rotating left shift.
Assume 0 <= n < w
* Examples when x = 0x12345678 and w = 32:
*
n=4 -> 0x23456781, n=20 -> 0x67812345
*/
unsigned rotate_left(unsigned x, int n);


unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    int rot_val = w - n;

    unsigned left  = x << n;

    // To remove the shifting if n is 0, since x >> w is undefined.
    // -!!n will be all 1s if n!=0, 0 if n=0.
    int zero_mask = -!!n;

    unsigned right = (x >> rot_val) & zero_mask;

    return left | right;
}


int main() {
    int x = 0x12345678;
    assert(rotate_left(x, 0) == 0x12345678);
    assert(rotate_left(x, 4) == 0x23456781);
    assert(rotate_left(x, 20) == 0x67812345);
}
