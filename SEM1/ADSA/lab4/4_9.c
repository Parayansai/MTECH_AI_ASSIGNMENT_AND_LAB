#include <stdio.h>
#include <stdlib.h>

struct numbers { 
    int num; 
};

int main(void) {
    int rows = 4, cols = 5, i, j;
    struct numbers **x = malloc(rows*sizeof(*x));
    for(i=0;i<cols;i++){
        x[i]=malloc(cols*sizeof(*x[i]));
    }
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            x[i][j].num=j*i;
        }
    }
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d",x[i][j].num);
        }
        printf("\n");
    }
    for(i=0;i<rows;i++){
        free(x[i]);
    }
    free(x);
}




/*
int main(){
    int rows=4,cols=5,i,j;
    struct numbers *x=malloc(rows*sizeof(struct numbers));;
    for(int i=0;i<rows;i++){
        x[i].num=i*10;

    }
    for(int i=0;i<rows;i++){
        printf("%d\n",x[i].num);

    }
    free(x);

}
    */