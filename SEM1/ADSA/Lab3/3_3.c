#include <stdio.h>

void reverse(int arr[], int l, int r) {
    while (l < r) {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l++; r--;
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5, k = 2;

    k = k % n;
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);

    printf("Rotated array: ");
    for (int i=0;i<n;i++) printf("%d ", arr[i]);
}
