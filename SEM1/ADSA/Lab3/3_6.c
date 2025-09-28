#include <stdio.h>

struct Book {
    char title[50];
    char author[50];
    float price;
};

int main() {
    struct Book b[3] = {
        {"C Programming","parayan",450},
        {"Algorithms","sai",1000},
        {"DS in C","X",300}
    };
    int n=3;
    float threshold = 400;

    for (int i=0;i<n;i++) {
        if (b[i].price > threshold) {
            printf("\"%s\" by %s : %.2f\n", b[i].title, b[i].author, b[i].price);
        }
    }
}
