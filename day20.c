#include <stdio.h>

int main() {
    int n;

    // input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // input array elements
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    // count subarrays with sum 0
    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                count++;
            }
        }
    }

    // output result
    printf("Number of subarrays with sum 0: %d\n", count);

    return 0;
}