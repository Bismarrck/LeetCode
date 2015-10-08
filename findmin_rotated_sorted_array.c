/*
 The solution to the problem:
 Find Minimum in Rotated Sorted Array

 Xin Chen
 */

#include <stdio.h>

int findMin(int *nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return nums[0] < nums[1] ? nums[0] : nums[1];
    }

    int mid = numsSize / 2;
    if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
    } else {
        int minR = findMin(&nums[mid + 1], numsSize - mid - 1);
        int minL = findMin(&nums[0], mid + 1);
        return minL < minR ? minL : minR;
    }
}

void test_findmin(void) {
    printf("%d\n", findMin((int []){4}, 1));
    printf("%d\n", findMin((int []){4, 5, 6, 7, 0, 1, 2}, 7));
    printf("%d\n", findMin((int []){4, 5, 6, 7, 8, 1, 2}, 7));
    printf("%d\n", findMin((int []){4, 5, 6, 7, 8, 9, 2}, 7));
    printf("%d\n", findMin((int []){9, 1, 2, 3, 4, 5, 6}, 7));
}

int main(int argc, char const *argv[])
{
    test_findmin();
    return 0;
}
