# include <stdio.h>
int main(){
    int i,j,c,large,sales[]={1,2,9,8,7,6,5};
    int n=sizeof(sales)/sizeof(sales[0]);
   // printf("%d",n);

    for (i=0;i<n;i++){
        large=sales[0];
        for(j=0;j<n-i-1;j++){
            if (sales[j]>sales[j+1]){
                c=sales[j+1];
                sales[j+1]=sales[j];
                sales[j]=c;
                 }
        

    }
    
    }
    //for(i=0;i<n;i++){
       // printf("%d",sales[i]);
   // }
    printf("%d",sales[n-1]);


}