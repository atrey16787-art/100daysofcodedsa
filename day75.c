#include <stdio.h>

#define MAX 1000

// Simple hashmap using arrays
int findMaxLen(int arr[], int n) {
    int prefixSum = 0, maxLen = 0;

    // Initialize map with -1 (means not found)
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -2;  // -2 means unused
    }

    int offset = MAX; // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0 from start
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: prefix sum seen before
        if (hash[prefixSum + offset] != -2) {
            int prevIndex = hash[prefixSum + offset];
            int len = i - prevIndex;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // store first occurrence
            hash[prefixSum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", findMaxLen(arr, n));

    return 0;
}