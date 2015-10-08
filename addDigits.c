/*
 The C solution to the problem:
 Add Digits

 Xin Chen
 */

#include <stdio.h>

// Source: https://leetcode.com/discuss/55910/two-lines-c-code-with-explanation
int addDigits(int num) {
    int res = num % 9;
    return (res != 0 || num == 0) ? res : 9;
}

int main(const int argc, const char *argv[]) {
    return 0;
}