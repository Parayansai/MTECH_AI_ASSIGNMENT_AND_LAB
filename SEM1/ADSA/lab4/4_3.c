# include <stdio.h>
// a nested struct is basically struct inside a sruct, it helps us group related sub-info in an other bigger record
struct date{
    int day;
    int month;
    int year;
};
 struct student{
    char name[50];
    struct date dt;
 };
  int main(){
    struct student st[50];
    int i,n=2;
    for(i=0;i<n;i++){
        printf("enter name of student\n");
        scanf("%s",&st[i].name);
        printf("Enter day:\n");
        scanf("%d",&st[i].dt.day);
        printf("Enter month:\n");
        scanf("%d",&st[i].dt.month);
        printf("Enter year:\n");
        scanf("%d",&st[i].dt.year);
    }
    for(i=0;i<n;i++){
        printf("\nstudent %d:\n",i+1);
        printf("Name: %s\n",st[i].name);
        printf("%d/",st[i].dt.day);
        printf("%d/",st[i].dt.month);
        printf("%d/",st[i].dt.year);

    }



    


  }