# include <stdio.h>
int main(){
    int i,max,sales[]={1,2,3,4,4,5,8,9,5,4,3,3};
    int n=sizeof(sales)/sizeof(sales[0]);
    max=sales[0];
    for (i=0;i<n;i++){
        if (max<sales[i]){
            max=sales[i];
        }
    
    }
    printf("%d",max);

}