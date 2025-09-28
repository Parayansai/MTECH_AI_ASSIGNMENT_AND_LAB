#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s[3] = {{"Alice",1,78.5},{"Bob",2,85.0},{"Cara",3,82.0}};
    int n = 3, best = 0;

    for (int i=1;i<n;i++) {
        if (s[i].marks > s[best].marks) best = i;
    }

    printf("Top student: %s (Roll %d) Marks=%.2f\n",
           s[best].name, s[best].roll, s[best].marks);


           
}
