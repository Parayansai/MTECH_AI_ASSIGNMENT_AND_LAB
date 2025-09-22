#include <stdio.h>

int main() {
    int arr[] = {5, 12, 7, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    int last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (arr[i] != key) {
        i++;
    }

    arr[n - 1] = last;

    if (i < n - 1 || arr[n - 1] == key)
        printf("Element found at index %d", i);
    else
        printf("Element not found");
}
