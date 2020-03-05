#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *next;
    int data;
}llnode;

void insertAtBeg(llnode **head, int data){
    llnode *temp;
    temp = (llnode *)malloc(sizeof(llnode));
    temp->data = data;
    temp->next = *head;
    *head=temp;
}

void display(llnode *head){
    while (head){
        printf("%d ",head->data);
        head = head->next;
    }
}

llnode* findIntsec2(llnode *head1, llnode *head2){
    llnode *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    int l1,l2,max,min,i;
    l1=l2=0;
    
    if(head1==NULL || head2==NULL)
        return NULL;

    while(temp1){
        l1++;
        temp1 = temp1->next;
    }

    while(temp2){
        l2++;
        temp2 = temp2->next;
    }

    max = l1>=l2?l1:l2;
    min = l1<=l2?l1:l2;

    if(max==l1){
        temp1 = head1;
        temp2 = head2;
    }

    else{
        temp1 = head2;
        temp2 = head1;
    }

    for(i=0;i<max-min;i++)
        temp1 = temp1->next;

    while(temp1){
        if(temp1==temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
}

int main(){
    llnode *intsecNode;
    llnode *head1 = NULL;
    llnode *head2 = NULL;
    insertAtBeg(&head1,0);
    insertAtBeg(&head1,1);
    insertAtBeg(&head1,2);
    insertAtBeg(&head2,0);
    insertAtBeg(&head2,1);
    insertAtBeg(&head2,2);
    head2 = head1;
    insertAtBeg(&head1,3);
    insertAtBeg(&head1,4);
    insertAtBeg(&head1,5);
    display(head1);
    printf("\n");
    insertAtBeg(&head2,6);
    insertAtBeg(&head2,7);
    insertAtBeg(&head2,8);
    display(head2);
    printf("\n");

    llnode *head3 = NULL;
    insertAtBeg(&head3,6);
    insertAtBeg(&head3,7);
    insertAtBeg(&head3,8);
    insertAtBeg(&head3,9);
    insertAtBeg(&head3,10);
    insertAtBeg(&head3,11);
    display(head3);
    printf("\n");

    printf("Intersection of linkedlist1 and linkedlist2: ");
    intsecNode = findIntsec2(head1,head2);
    if(intsecNode)
        printf("%d",intsecNode->data);
    printf("\n");
    printf("Intersection of linkedlist1 and linkedlist3: ");
    intsecNode = findIntsec2(head1,head3);
    if (intsecNode)
        printf("%d",intsecNode->data);
}