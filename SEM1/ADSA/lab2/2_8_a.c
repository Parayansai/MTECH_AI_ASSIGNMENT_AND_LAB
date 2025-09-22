#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[]="pArayan";
    int count = 0;
    int lookup[256] = {0};

    lookup['a'] = lookup['e'] = lookup['i'] = lookup['o'] = lookup['u'] = 1;
    lookup['A'] = lookup['E'] = lookup['I'] = lookup['O'] = lookup['U'] = 1;

    for (int i = 0; i < strlen(str); i++) {
        if (lookup[(unsigned char)str[i]])
            count++;
    }

    printf("Number of vowels: %d", count);
}
