#include <stdio.h>
#include <string.h>

void reverse(char str[], char rev[]) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        rev[i] = str[len - 1 - i];
    }
    rev[len] = '\0';
}

int main() {
    char reversed[100];
    char username[]="parayan";

    reverse(username, reversed);

    printf("Reversed string: %s", reversed);
}




