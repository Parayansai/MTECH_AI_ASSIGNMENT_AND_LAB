# include <stdio.h>
# include <stdlib.h>
struct node{
    int x;
    struct node*next;
};
int main(){
    int y,count=0;
    struct node *head=NULL,*tail=NULL;
    struct node*newnode;
    for(int i=0;i<10;i++){
        newnode=malloc(sizeof(struct node));
        newnode->x=i;
        newnode->next=NULL;
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }

    }

    struct node *temp=head;
    while(temp !=NULL ){ // we cant switch statement like a,b to b,a in this case , if we did temp->x check for y when temp=null which is undefined behaviour
        printf("%d\n",temp->x);
        temp=temp->next;
        count=count+1;
    }
    printf("total number of elements in list is %d",count);
}