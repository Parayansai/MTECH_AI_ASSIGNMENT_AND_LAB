#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int marks;
};

int main(void) {
    struct student *arr = NULL;
    struct student *tmp = NULL;
    int n, add, new_n;

    printf("Enter initial number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number\n");
        return 1;
    }

    arr = malloc(n * sizeof *arr);

    for (int i = 0; i < n; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%s", arr[i].name);       
        printf("Student %d marks: ", i + 1);
        if (scanf("%d", &arr[i].marks) != 1) {
            fprintf(stderr, "Invalid marks\n");
            free(arr);
            return 1;
        }
    }

    printf("How many more students to add? ");
    if (scanf("%d", &add) != 1 || add < 0) {
        fprintf(stderr, "Invalid number to add\n");
        free(arr);
        return 1;
    }

    if (add == 0) {
        printf("\nNo new students added.\n\n");
    } else {
        new_n = n + add;

        tmp = realloc(arr, new_n * sizeof *arr);
        if (tmp == NULL) {
            perror("realloc");
            free(arr);            
            return 1;
        }
        arr = tmp;

        for (int i = n; i < new_n; i++) {
            printf("Student %d name: ", i + 1);
            scanf("%49s", arr[i].name);
            printf("Student %d marks: ", i + 1);
            if (scanf("%d", &arr[i].marks) != 1) {
                fprintf(stderr, "Invalid marks\n");
                free(arr);
                return 1;
            }
        }

        n = new_n;
        printf("\nAdded %d students.\n\n", add);
    }

    printf("All students:\n");
    for (int i = 0; i < n; i++) {
        printf("%2d: %s, %d\n", i + 1, arr[i].name, arr[i].marks);
    }

    free(arr);
}
