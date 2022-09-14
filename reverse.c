#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL, *newnode, *temp, *prevnode, *currnode, *nextnode;

void create(){
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newnode->data);
        if(head==NULL){
            head=newnode;
            temp=newnode;   
        }else{
            temp->next=newnode;
            temp=newnode;   
        }

        printf("Do u want to continue : ");
        scanf("%d", &choice);
    }
}

void traverse(){
    temp=head;
    while(temp!=0){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(){
    prevnode=NULL;
    currnode=head;
    nextnode=head;
    while(nextnode->next!=0){
        nextnode=currnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    currnode->next=prevnode;
    head=nextnode;
    while(nextnode!=0){
        printf("%d ", nextnode->data);
        nextnode=nextnode->next;
    }
    printf("\n");
}

int main(){
    create();
    printf("LINKED LIST IS : \n");
    traverse();
    printf("REVERSE LINKED LIST IS : \n");
    reverse();
}