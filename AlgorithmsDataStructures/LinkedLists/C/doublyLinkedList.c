#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *next, *prev;
    int data;
}dllnode;

void insertAtBeg(dllnode **head, int data){
    dllnode *temp;
    temp = (dllnode *)malloc(sizeof(dllnode));
    temp->data = data;
    temp->next= *head;
    temp->prev = NULL;
    *head = temp;
}

void insertAtEnd(dllnode **head, int data){
    dllnode *temp,*newNode;
    newNode = (dllnode *)malloc(sizeof(dllnode));
    newNode->data = data;
    if(*head == NULL){
        newNode->next = *head;
        *head = newNode;
        newNode->prev = NULL;
        return;
    }
    newNode->next = NULL;
    temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void display(dllnode *head){
    while (head){
        printf("%d ",head->data);
        head = head->next;
    }
}

int main(){
    dllnode *head = NULL;
    insertAtEnd(&head,0);
    insertAtBeg(&head,1);
    insertAtBeg(&head,2);
    insertAtBeg(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    display(head);
}