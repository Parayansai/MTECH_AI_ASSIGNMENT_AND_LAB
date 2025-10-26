# include <stdio.h>
struct Employee{
    int id;        
    char name[50]; 
    int age;      
    float salary;
};
int main(){
    struct Employee employee[100]; // 100 structs are being made in the memory
    int i,n;
    printf("enter number of employees you want");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("enter name\n");
        scanf("%s",&employee[i].name);

        printf("enter id\n");
        scanf("%d",&employee[i].id);

        printf("enter age\n");
        scanf("%d",&employee[i].age);

        printf("enter salary\n");
        scanf("%f",&employee[i].salary);


    }
    for(i=0;i<n;i++){
        printf("\nEmployee %d:\n",i+1);
        printf("id: %d\n",employee[i].id);
        printf("Name: %s\n",employee[i].name);
        printf("Age: %d\n",employee[i].age);
        printf("Salary: %f\n",employee[i].salary);

    }

}