# include <stdio.h>
# include <stdlib.h>
struct node{
    int x;
    struct node*next;
};
int main(){
    int h;
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
    printf("list of numbers before insertion\n");
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->x);
        temp=temp->next;
    }
    // Insertion At Beginning
    struct node*t=malloc(sizeof(struct node));
    printf("enter number you want to insert in the beginning");
    scanf("%d",&t->x);
    t->next=head;
    head=t;
    struct node *temp1=head;
    printf("list of numbers after inserting at beginning:\n");
    while(temp1!=NULL){
    printf("%d\n",temp1->x);
    temp1=temp1->next;
    }


    // insertion at end
    struct node*k = malloc(sizeof(struct node));
    struct node*dummy=head;
    printf("enter number to be inserted at end\n");
    scanf("%d",&k->x);
    while(dummy->next!=NULL){
        dummy=dummy->next;
    }
    dummy->next=k;
    k->next=NULL;

    struct node *temp2=head;
    printf("list of numbers after inserting at ending:\n");
    while(temp2!=NULL){
    printf("%d\n",temp2->x);
    temp2=temp2->next;
    }
    // insertion in between

    struct node*j = malloc(sizeof(struct node));
    struct node*dummy1=head;
    printf("enter number to be inserted at middle\n");
    scanf("%d",&j->x);
    printf("enter after which number should the new number be inserted");
    scanf("%d",&h);

    while(dummy1 != NULL && dummy1->x != h){
        dummy1=dummy1->next;
    }
    j->next=dummy1->next;
    dummy1->next=j;

    struct node *temp3=head;
    printf("list of numbers after inserting at middle:\n");
    while(temp3!=NULL){
    printf("%d\n",temp3->x);
    temp3=temp3->next;
    }
    struct node*current=head;
    struct node*next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }


    

    





}
