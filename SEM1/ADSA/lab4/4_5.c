# include <stdio.h>
struct student{        
    char name[50]; 
    int marks;
};
int main(){
    struct student x[100];
    int i,n,max,z=0;
    printf("enter number of students");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("enter student name:");
        scanf("%s",&(x[i].name));
        printf("enter marks:");
        scanf("%d",&(x[i].marks));
    }
    max=x[0].marks;
    for(int j=0;j<n;j++){
        if(max<x[j].marks){
            max=x[j].marks;
             z=j;
        }
    }
    printf("max marks:%d, student:%s",x[z].marks,x[z].name);

}      