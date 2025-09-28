#include <stdio.h>

int main() {
    int arr[] = {1,2,3,1};
    int n=4;

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]==arr[j]) {
                printf("Contains duplicate = true\n");
                return 0;
            }
        }
    }
    printf("Contains duplicate = false\n");



    
}
