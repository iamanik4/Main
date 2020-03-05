/* 
*Find the middle element of a linked list
*Incase of odd number of elements, take the last of the 2 middle elements
*Incase of only one element, return the element
*Incase of 2 elements, return the 2nd element
*Incase of no elements, return NULL


*Naive Approach: 
    *Count number of elements (n) in the node.
    *From head move (n/2) elements and print the node value.
    *No elements case has to be handled seperately.
*Disadvantages:
    *Traverse the linkedList twice

*Efficient Approach: Slow Fast moving pointers
    *Start with two pointers A,B pointing to head.
    *A moves 2 nodes at a time and B moves one node at a time.
    *When A reaches end, B is at middle. Return value of node pointed by B.
*Advantages:
    *Traverse the linkedList once
*/

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

int midOfLLNaive(llnode *head){
    int count = 0,i;
    llnode *temp = head;
    if(head==NULL){ // No elements case
        printf("Empty Linked List. Return Value: ");
        return -1;
    }
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    temp = head;
    for(i=0;i<count/2;i++){
        temp = temp->next;
    }
    return temp->data;

}

int midOfLLEff(llnode *head){
    llnode *fast=head, *slow=head;
    if(head==NULL){ // No elements case  
        printf("Empty Linked List. Return Value: "); 
        return -1;
    }
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main(){
    llnode *head = NULL;
    insertAtBeg(&head,1);
    insertAtBeg(&head,2);
    insertAtBeg(&head,3);
    insertAtBeg(&head,4);
    insertAtBeg(&head,5);
    insertAtBeg(&head,6);
    insertAtBeg(&head,7);
    display(head);
    printf("\n%d\n",midOfLLNaive(head));
    printf("%d\n\n",midOfLLEff(head));

    llnode *head2 = NULL;
    printf("%d\n",midOfLLNaive(head2));
    printf("%d\n\n",midOfLLEff(head2));

    llnode *head3 = NULL;
    insertAtBeg(&head3,1);
    insertAtBeg(&head3,2);
    insertAtBeg(&head3,3);
    insertAtBeg(&head3,4);
    display(head3);
    printf("\n%d\n",midOfLLNaive(head3));
    printf("%d\n\n",midOfLLEff(head3));
    
}