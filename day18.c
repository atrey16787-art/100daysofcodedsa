#include <stdio.h>

int main() {
    int n, k, i;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    printf("Enter number of rotations: ");
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    // Rotate array
    for(i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Print rotated array
    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}