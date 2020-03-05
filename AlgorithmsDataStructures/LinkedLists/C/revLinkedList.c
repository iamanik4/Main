/*Problem Statement: Reverse a linked list
  Solution: Two ways:
        1. Naive Approach: 
            a. traverse the linked list
            b. copy the elements into an array
            c. traverse the linked list again
            d. starting from the last array element, copy the items into the linked list nodes
            * here we have to traverse the linked list twice and also need to use extra space
        2. Efficient Approach:
            a. Reverse the links
            b. Take the head as curr node and prev node and next node as NULL
            c. unless curr node does not reach the last node:
            d. make the next node for curr node as next
            e. make curr->next as prev
            f. make prev as curr
            g. make curr as next
            * here we have to traverse the linked list only once and no extra space is used.
        3. Recursive Efficient Approach:
            a. Reverse the links recursively starting from head, towards last node
            b. Pass the first node as current node and NULL as previous node
            c. Store the pointer to the next node of current node under next
            d. reverse the link between current node and previous node
            e. update previous node as current node
            f. update current node as next node
            g. call the recursive funtion again for the next two nodes
            h. for the base case, when curr=NULL, return prev
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

void revLLNaive(llnode *head){
    llnode *temp = head;
    int ar[100],i=0;
    while (temp){   //traverse till the last node unless temp becomes NULL
        ar[i] = temp->data;
        temp = temp->next;
        i++;
    }
    temp = head;
    while(temp){
        i--;    //since i was incremented till temp became null, move one step back
        temp->data = ar[i]; //replace data in linked list in reverse order
        temp = temp->next;
    }
}

void revLLEff(llnode **head){
    llnode *curr = *head, *prev = NULL, *next = NULL;
    while(curr){
        next = curr->next;  //store reference of the next element
        curr->next = prev;  //reversing the link of the current node
        prev = curr;        //incrementing previous to the current node
        curr = next;        //incrementing current to the next node
    }
    *head = prev;
}

llnode* revLLrec(llnode *curr, llnode *prev){
    llnode *next;
    if(curr == NULL)
        return prev;
    
    next = curr->next;  //store reference of the next element
    curr->next = prev;  //reversing the link of the current node
    revLLrec(next,curr);
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
    revLLNaive(head);
    printf("\n=============\n");
    display(head);
    revLLEff(&head);
    printf("\n=============\n");
    display(head);
    head = revLLrec(head,NULL);
    printf("\n=============\n");
    display(head);
}