#include<stdio.h>

int main() {
    // Cannot use != nor ==.
    // Do we then need to check each bit?
    // But loops are forbidden!
    // So no.
    int x = 1;

    int val = !!x;

    printf("A, Val=%d\n", val);

    // B. Any bit of x equals 0.
    x = 0;
    val = !!~x;

    printf("B, Val=%d\n", val);

    // C. Any bit in the least significant byte is 1
    x = 255;
    val = !!(x & 0xFF);
    printf("C, Val=%d\n", val);

    // D. Any bit in the most significant byte is 0
    x = 0;
    int shift_val = (sizeof(int) - 1) << 3;
    int mask = 0xFF << (shift_val);
    val = !!(~x & mask);

    printf("D, Val=%d\n", val);
    return 0;
}
