#include <stdio.h>

int main() {
    int arr[] = {10,15,22,37,34,57};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        if (arr[i] & 1){
            printf("%d is Odd\n", arr[i]);
        }
        else{
            printf("%d is Even\n", arr[i]);
        }
    }

}
