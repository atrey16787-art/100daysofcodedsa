#include <stdio.h>

int main() {
    int n, k, i;
    int count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        count++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", count);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d\n", count);

    return 0;
}
