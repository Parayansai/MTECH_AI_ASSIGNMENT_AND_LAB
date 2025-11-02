# include <stdio.h>
# include <stdlib.h>
struct node{
    int x;
    struct node*next;
};
int main(){
    int n;
    struct node *head=NULL,*tail=NULL;
    struct node*newnode;
    printf("print the number of elements you want in the list");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
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
    while(temp!=NULL){
        printf("%d\n",temp->x);
        temp=temp->next;
    }

    struct node*current=head;
    struct node*next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
}