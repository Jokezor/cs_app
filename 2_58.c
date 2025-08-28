#include <stdio.h>

/*
2.58 ◆◆
Write a procedure is_little_endian that will return 1 when compiled and run
on a little-endian machine, and will return 0 when compiled and run on a big-
endian machine. This program should run on any machine, regardless of its word
size.
*/

int is_little_endian() {
    int a = 1;
    // Now how to check the first bit?
    return *((unsigned char*) &a) == 1;
}

int main() {
    if (is_little_endian()) {
        printf("Little endian\n");
    }
    else {
        printf("Big endian\n");
    }
    return 0;
}
