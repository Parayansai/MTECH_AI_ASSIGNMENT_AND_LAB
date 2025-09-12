#include <stdio.h>

int binary_search_recursive(long long arr[], int l, int r, long long key) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] > key) return binary_search_recursive(arr, l, mid - 1, key);
    else return binary_search_recursive(arr, mid + 1, r, key);
}

int main() {
    int n;
    printf("Number of IDs (sorted): ");
    scanf("%d", &n);
    if (n <= 0) { printf("Array empty.\n"); return 0; }
    long long arr[n];
    printf("Enter %d sorted IDs:\n", n);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    long long key;
    printf("Enter ID to search: ");
    scanf("%lld", &key);
    int idx = binary_search_recursive(arr, 0, n - 1, key);
    if (idx == -1) printf("ID not found\n");
    else printf("ID found at index %d \n", idx);
    return 0;
}
