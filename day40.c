#include <stdio.h>

/*********** SWAP ***********/
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/*********** HEAPIFY (MAX HEAP) ***********/
void heapify(int arr[], int n, int i) {
    int largest = i;       // root
    int left = 2*i + 1;    // left child
    int right = 2*i + 2;   // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // recursive call
    }
}

/*********** HEAP SORT ***********/
void heapSort(int arr[], int n) {

    // Step 1: Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        swap(&arr[0], &arr[i]);

        // Call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

/*********** MAIN ***********/
int main() {
    int arr[] = {40, 10, 30, 50, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}