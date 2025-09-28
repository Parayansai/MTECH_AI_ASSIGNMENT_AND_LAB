#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    char department[20];
};

int main() {
    struct Employee e[3] = {
        {101,"John",50000,"IT"},
        {102,"Mary",60000,"HR"},
        {103,"Sam",55000,"IT"}
    };
    int n=3;

    for (int i=0;i<n;i++) {
        if (strcmp(e[i].department,"IT")==0) {
            e[i].salary *= 1.10;
        }
    }

    for (int i=0;i<n;i++) {
        printf("%s (%s) Salary=%.2f\n", e[i].name, e[i].department, e[i].salary);
    }
    

    
}
