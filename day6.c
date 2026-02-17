#include <stdio.h>

int main() {
    int n;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(n == 0) return 0;

    int k = 1;  // index for unique elements

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    printf("Unique elements: ");
    for(int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
