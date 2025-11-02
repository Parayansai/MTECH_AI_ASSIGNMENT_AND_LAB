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
    printf("enter the number you want to search:");
    scanf("%d",&y);
    struct node *temp=head;

    while(temp !=NULL && temp->x!=y){ // we cant switch statement like a,b to b,a in this case , if we did temp->x check for y when temp=null which is undefined behaviour
        temp=temp->next;
        count=count+1;
    }
    if(temp==NULL){
        printf("the number %d is not found",y);
    }
    else{
    printf("the number %d is found at position %d in the list",y,count);
    }
    struct node*current=head;
    struct node*next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }

}