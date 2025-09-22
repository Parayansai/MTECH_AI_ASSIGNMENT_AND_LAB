#include <stdio.h>

int sumArray(int arr[], int n) {
    if (n == 0)
        return 0;

    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = sumArray(arr, n);

    printf("Sum of array elements = %d\n", result);

    return 0;
}

