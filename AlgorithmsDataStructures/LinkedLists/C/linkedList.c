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

/*In the display function below, contrary to as it may seem, the actual head remains the same.
Only the formal parameter changes, hence it is alright to do so*/

void display(llnode *head){
    while (head){
        printf("%d ",head->data);
        head = head->next;
    }
}

void display2(llnode *head){
    llnode *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void insertAtEnd(llnode **head, int data){
    llnode *temp,*newNode;
    newNode = (llnode *)malloc(sizeof(llnode));
    newNode->data = data;
    if(*head == NULL){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    newNode->next = NULL;
    temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

int main(){
    llnode *head = NULL;
    insertAtEnd(&head,0);
    insertAtBeg(&head,1);
    insertAtBeg(&head,2);
    insertAtBeg(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    display(head);
    //display2(head);
}