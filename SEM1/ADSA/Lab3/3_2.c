#include <stdio.h>

int main() {
    int arr[] = {10, 2, -2, -20, 10};
    int n = 5, S = -10;
    int i, j;

    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = i; j < n; j++) {
            sum += arr[j];
            if (sum == S) {
                printf("Subarray found from %d to %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No subarray found\n");
}
