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

    // insert at beginning
    struct node*new;
    new=malloc(sizeof(struct node));
    printf("enter the number you want to insert in the beginning:\n");
    scanf("%d",&new->x);
    new->prev=NULL;
    new->next=head;
    if (head != NULL) {
    head->prev = new;
} 
    else{
       tail = new;
}
    head = new;
    printf("printing numbers after inserting in first positio\n");
    struct node*temp1=head;
    while(temp1!=NULL){
        printf("%d\n",temp1->x);
        temp1=temp1->next;
    }
    // insert at end
    struct node *new1;
    new1 = malloc(sizeof(struct node));
    printf("Enter the number you want to insert at the end: ");
    scanf("%d", &new1->x);

    new1->next = NULL;     
    new1->prev = tail;    
    tail->next = new1;     
    tail = new1;           

    printf("Printing numbers after inserting at end:\n");
    struct node *temp2 = head;
    while (temp2 != NULL) {
        printf("%d\n", temp2->x);
        temp2 = temp2->next;
}

    // insert in between
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