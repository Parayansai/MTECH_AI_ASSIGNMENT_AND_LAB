# include <stdio.h>
# include <string.h>
void reverse(char x[]);

int main(){
    char x[]="parayan";
    reverse(x);// reverse x only points out to the first element or points to the first element &x[0] 
    printf("reversed string is %s",x);//

}
void reverse(char x[]){
    int len = strlen(x);
    int left = 0;
    int right = len-1;
    char temp;
    while(right>left){
        temp=x[left];//x[i] means *(x+i) goes i steps from the first element
        x[left]=x[right];
        x[right]=temp;
        right--;
        left++;

    }
    return;


}