#include <stdio.h>
#include <string.h>

int main() {
    char *arr[] = {"flower","flow","flight"};
    int n=3;
    char prefix[100];
    int idx=0;

    int minlen = strlen(arr[0]);
    for (int i=1;i<n;i++) {
        if ((int)strlen(arr[i]) < minlen) minlen = strlen(arr[i]);
    }

    for (int i=0;i<minlen;i++) {
        char c = arr[0][i];
        int ok = 1;
        for (int j=1;j<n;j++) {
            if (arr[j][i] != c) { ok=0; break; }
        }
        if (!ok) break;
        prefix[idx++] = c;
    }
    prefix[idx]='\0';

    printf("Longest common prefix: \"%s\"\n", prefix);



    
}
