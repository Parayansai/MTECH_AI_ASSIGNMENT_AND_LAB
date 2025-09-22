# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main() {
    char str[]="pArayan";
    int count = 0;

    for (int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }

    printf("Number of vowels: %d", count);
}
