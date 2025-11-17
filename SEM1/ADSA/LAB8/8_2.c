# include <stdio.h>
int main(){
    int a[]={94,5,38,3,6,2,2,5,};
    int i,j,c,b,min;
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
        min=a[i];
        c=i;
        b=i;
        for(j=i+1;j<sizeof(a)/sizeof(a[0]);j++){
            if(a[j]<min){
                min=a[j];
                b=j;
        }
    }
        a[b]=a[i];
        a[i]=min;
}
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("%d\n",a[i]);
    }

}