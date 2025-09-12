#include <stdio.h>
#include <ctype.h>

int main() {
    char s[1001];
    printf("Enter a string (max 1000 chars):\n");

    fgets(s, sizeof(s), stdin);
    if (s[0] == '\n') fgets(s, sizeof(s), stdin);

    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower((unsigned char)s[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') count++;
    }
    printf("Vowel count = %d\n", count);
    return 0;
}
