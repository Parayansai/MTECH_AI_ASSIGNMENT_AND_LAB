# include <stdio.h>
int main(){
    int arr[5],max,second,n,i,len,j,temp,k;
    //printf("enter the number of elements you want");
    //scanf("%d",&n);
    for (i=0;i<5;i++){
        printf("enter a number");
        scanf("%d",&arr[i]);

    }
    len = sizeof(arr)/sizeof(arr[0]);
    max=arr[0];
    second=arr[1];
    for (j=0;j<5;j++){
        int x= arr[j];
        if (x>max){
            second=max;
            max=x;

        }
        else if(x>second && x<max){
            second=x;
        }
    }
printf("second largest element is %d",second);
}