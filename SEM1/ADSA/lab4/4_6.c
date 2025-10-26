# include <stdio.h>
/*In C, structures are user-defined data types that can hold different data types together (e.g., name, marks, age, etc.).
however, C does not allow direct comparison of two structs using relational operators) */

#include <stdio.h>
#include <string.h>  

struct student {
    char name[50];
    int marks;
};

int main() {
    struct student s1, s2;

    // Input for first student
    printf("Enter first student's name: ");
    scanf("%s", s1.name);  //
    printf("Enter first student's marks: ");
    scanf("%d", &s1.marks);

    // Input for second student
    printf("Enter second student's name: ");
    scanf("%49s", s2.name);
    printf("Enter second student's marks: ");
    scanf("%d", &s2.marks);

    // Compare the two structures
    if (strcmp(s1.name, s2.name) == 0 && s1.marks == s2.marks) {
        printf("\nBoth students are the same.\n");
    } else {
        printf("\nThe students are different.\n");
    }

}

