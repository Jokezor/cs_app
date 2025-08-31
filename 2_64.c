#include<stdio.h>
#include<assert.h>


int any_odd_one(unsigned x);


/* 
 * Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32 
*/
int any_odd_one(unsigned x) {
    // So, we should check odd bits.
    // We could simply make a mask with alternating 01.
//    int mask = (1 << 1) + (1 << 3) + (1 << 5) + (1 << 7) + (1 << 9) + (1 << 11) + (1 << 13) + (1 << 15) + (1 << 17) + (1 << 19) + (1 << 21) + (1 << 23) + (1 << 25) + (1 << 27) + (1 << 29) + (1 << 31);
    // Ahh, use hexadecimal.
    int mask = 0xAAAAAAAA;
    return !!(x & mask);
}

int main() {
    printf("%d\n", any_odd_one(2));
    assert(any_odd_one(0x2));
    assert(!any_odd_one(0x4));
    return 0;
}
