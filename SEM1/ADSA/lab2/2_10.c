#include <stdio.h>
#include <string.h>

int main() {
    int num;
    char str[20];  

    printf("Enter a number: ");
    scanf("%d", &num);

    sprintf(str, "%d", num);  // convert int to string
    int left = 0, right = strlen(str) - 1;
    int isPalindrome = 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("%d is a Palindrome", num);
    else
        printf("%d is NOT a Palindrome", num);

}
