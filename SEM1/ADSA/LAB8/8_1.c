# include <stdio.h>
int main(){
    int a[]={94,5,38,3,6,2,2,5,};
    int max,c;
    max=a[0];
    for(int i=1;i<sizeof(a)/sizeof(a[0]);i++){
        for(int j=i;j>0 && a[j-1]>a[j];j--){
            c=a[j-1];
            a[j-1]=a[j];
            a[j]=c;

        }
    }
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("%d\n",a[i]);
    }

}