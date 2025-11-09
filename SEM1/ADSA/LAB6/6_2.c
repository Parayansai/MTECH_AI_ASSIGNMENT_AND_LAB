# include <stdio.h>
# include <stdlib.h>
struct node{
    int x;
    struct node*next;
    struct node*prev;
};
int main(){
    int i;
    struct node *y;
    struct node *head=NULL;
    struct node *tail=NULL; 
    for(i=0;i<10;i++){
        y=malloc(sizeof(struct node));
        y->x=i;
        if(head==NULL){
            head=tail=y;
            y->prev=NULL;
            y->next=NULL;
        }
        else{
            tail->next=y;
            y->prev=tail;
            y->next=NULL;
            tail=y;
        }

        }
    printf("print numbers of double linked list");
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->x);
        temp=temp->next;
    }
    int pos;
    printf("Enter the position after which you want to insert: ");
    scanf("%d", &pos);

    struct node *new2;
    new2 = malloc(sizeof(struct node));
    printf("Enter the number to insert: ");
    scanf("%d", &new2->x);

    struct node *temp3 = head;

    for (i = 1; i < pos && temp3 != NULL; i++) {
        temp3 = temp3->next;
}

    new2->next = temp3->next;
    new2->prev = temp3;

    if (temp3->next != NULL)
        temp3->next->prev = new2;

    temp3->next = new2;

    printf("Printing numbers after inserting in between:\n");
    temp3 = head;
    while (temp3 != NULL) {
        printf("%d\n", temp3->x);
        temp3 = temp3->next;
}
    struct node*current=head;
    struct node*next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
}