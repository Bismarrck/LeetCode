#include <stdlib.h>
#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    if (n == 0) {
        return;
    }

    int i = m - 1;
    int j = n - 1;
    int k = n + m - 1;
    int min1 = nums1[0];
    int max1 = nums1[i];
    int min2 = nums2[0];
    int max2 = nums2[j];

    if (min2 > max1) {
        int a = 0;
        for (; a < n; a ++) {
            nums1[m + a] = nums2[a];
        }
    }
    else if (min1 > max2) {
        int a = k;
        for (; a >= n; a --) {
            nums1[a] = nums1[a - n];
        }
        for (a = 0; a < n; a ++) {
            nums1[a] = nums2[a];
        }
    }
    else {
        while (k >= 0) {
            if (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k] = nums1[i];
                    i --;
                } else {
                    nums1[k] = nums2[j];
                    j --;
                }
            } else if (i < 0) {
                nums1[k] = nums2[j];
                j --;
            } else if (j < 0) {
                nums1[k] = nums1[i];
                i --;
            }
            k --;
        }
    }
}

int main(int argc, char const *argv[])
{
    int nums1[] = { 4, 0, 0, 0, 0 };
    int nums2[] = { 1, 2, 3, 6 };
    int m = 1;
    int n = 4;

    merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i ++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
