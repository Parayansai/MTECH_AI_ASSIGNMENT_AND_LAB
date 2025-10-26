# include <stdio.h>
/*
struct complex{
    int real;
    int img;
};
struct complex rev(struct complex *x);
int main(){
    struct complex x;
    printf("enter real part of complex");
    scanf("%d",&(x.real));//(*(&x)).real
    printf("enter imaginary part of complex");
    scanf("%d",&(x.img));
    printf("%d+%di\n",x.real,x.img);
    //x=rev(x);
    rev(&x);
    printf("%d+%di",x.real,x.img);


}

struct complex rev(struct complex x){
    int c= x.real;
    x.real=x.img;
    x.img=c;
    return x;

}

struct complex rev(struct complex *x){
    int c=(*x).real;
    (*x).real=(*x).img;
    (*x).img=c;

}
*/
struct date{
    int day;
    int month;
    int year;
};
struct student{
    int age;
    char name[50];
    struct date dt;
};
int main(){
    struct student x;
    printf("enter student name:");
    scanf("%s",x.name);
    printf("enter student age:");
    scanf("%d",&(x.age));    
    printf("enter day:");
    scanf("%d",&(x.dt.day));
    printf("enter month:");
    scanf("%d",&(x.dt.month));
    printf("enter year:");
    scanf("%d",&(x.dt.year));
    printf("name:%s,age:%d,date:%d/%d/%d",x.name,x.age,x.dt.day,x.dt.month,x.dt.year);

}