#include<stdio.h>

int main() {
    // Cannot use != nor ==.
    // Do we then need to check each bit?
    // But loops are forbidden!
    // So no.
    int x = 1;

    // A. Any bit of x equals 1.
    // Then return 1, otherwise 0.
    // Either x is odd, then the lowest bit is set.
    // Otherwise, x is even and then (x-1) has the lowest bit set.
    // What if x is 0?, then x-1 yields -1.
    // This has the lowest bit set.
    int val = (x & 1 || (x > 0) && (x-1) & 1);

    printf("A, Val=%d\n", val);

    // B. Any bit of x equals 0.
    // Either x is -1 or 2^w - 1
    x = -1;
    val = (x ^ ((1 << (sizeof(int)-1)*8) -1));

    printf("B, Val=%d\n", val);
    return 0;
}
