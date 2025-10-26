# include <stdio.h>
struct complex{
    float real;
    float imag;
};

void swap(struct complex *a, struct complex *b){
    struct complex temp = *a;
    *a=*b;
    *b= temp;

}
int main(){
    struct complex c1,c2;
    printf("enter the real and imaginary part of complex numbers\n");
    scanf("%f""%f",&c1.real,&c1.imag);
    printf("enter the real and imaginary part of the other complex numbers\n");
    scanf("%f""%f",&c2.real,&c2.imag);

    printf("before swapping\n");
    printf("c1=%f + %fi:\n",c1.real,c1.imag);
    printf("c2=%f + %fi:\n",c2.real,c2.imag);

    swap(&c1,&c2);
    printf("after swapping\n");
    printf("c1=%f + %fi:\n",c1.real,c1.imag);
    printf("c2=%f + %fi:\n",c2.real,c2.imag);
}