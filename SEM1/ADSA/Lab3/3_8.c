#include <stdio.h>

int main() {
    int nums[] = {2,7,11,15};
    int n=4, target=9;

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (nums[i]+nums[j]==target) {
                printf("Indices %d and %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No two-sum found\n");


    
}
