# include <stdio.h>
struct player{        
    char name[50]; 
    int runs;
    int wickets;
};
int main(){
    struct player x[100];
    int i,n,max,z=0;
    printf("enter number of players");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("enter student name:");
        scanf("%s",&(x[i].name));
        printf("enter runs:");
        scanf("%d",&(x[i].runs));
        printf("enter wickets:");
        scanf("%d",&(x[i].wickets));
    }
    max=x[0].runs;
    for(int j=0;j<n;j++){
        if(max<x[j].runs){
            max=x[j].runs;
             z=j;
        }
    }
    printf("max mruns:%d, player:%s",x[z].runs,x[z].name);

}