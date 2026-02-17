#include <stdio.h>

int main() {
    int p, q, i = 0, j = 0, k = 0;

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);
    int a[p];
    printf("Enter %d sorted arrival times: ", p);
    for(int x = 0; x < p; x++) {
        scanf("%d", &a[x]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);
    int b[q];
    printf("Enter %d sorted arrival times: ", q);
    for(int x = 0; x < q; x++) {
        scanf("%d", &b[x]);
    }

    int merged[p + q];

    // Merge logic
    while(i < p && j < q) {
        if(a[i] < b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];
    }

    // Remaining elements
    while(i < p)
        merged[k++] = a[i++];

    while(j < q)
        merged[k++] = b[j++];

    // Output
    printf("Merged log: ");
    for(i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
