# include <stdio.h>
# include <stdlib.h>
struct node{
    int x;
    struct node*next;
};
int main(){
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
    while(temp!=NULL){
        printf("%d\n",temp->x);
        temp=temp->next;
    }

// reverse the linked list
struct node*prev=NULL;
struct node*current1=head;
struct node*next1;
while(current1!=NULL){
    next1=current1->next;
    current1->next=prev;
    prev=current1;
    current1=next1;

}
head=prev;
struct node*temp1=head;
while(temp1!=NULL){
    printf("%d",temp1->x);
    temp1=temp1->next;
}
struct node*current=head;
struct node*next;
while(current!=NULL){
    next=current->next;
    free(current);
    current=next;
    }


}