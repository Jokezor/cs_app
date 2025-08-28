#include <stdio.h>

/*
2.57 ◆
Write procedures show_short, show_long, and show_double that print the byte
representations of C objects of types short, long, and double, respectively. Try
these out on several machines.
*/

// Show bytes goes up to the length of the number of bytes and print each.
// So show_short should just be 16 bits.

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
    printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_short(short x) {
    // If we have a x too big, then it should fit.
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_short(ival);
}

int main() {
    int a = 1<<15 + 2;
    test_show_bytes(a);
    return 0;
}
