#include <stdio.h>

int main() {
    int arr[] = {5,12,7,20,15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, found = -1;

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1){
        printf("Element found at index %d", found);
    }
    else{
        printf("Element not found");
    }
}
