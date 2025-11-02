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
    struct node*slow=head;
    struct node*fast=head;

        while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;
        }

        if (slow != NULL){
            printf("\nMiddle element is: %d\n", slow->x);
        }
        else{
            printf("\nList is empty.\n");
        }

        struct node *current = head;
        while (current != NULL) {
            struct node *next = current->next;
            free(current);
            current = next;
    }
}