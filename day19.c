#include <stdio.h>
#include <stdlib.h>

// function for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    // Step 2: Two pointer approach
    int left = 0, right = n - 1;
    int minSum = arr[left] + arr[right];
    int num1 = arr[left], num2 = arr[right];

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    // Output result
    printf("%d %d", num1, num2);

    return 0;
}