#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 10
#define TRUE 1
#define FALSE 0
#define MAX 30

typedef int Boolean;

typedef struct{
    char f[NAME];
    char m;
    char l[NAME];
}Fullname;

typedef struct{
    int ID;
    Fullname name;
    Boolean active;
}Person;

typedef struct node{
    Person info;
    struct node *link;
}Node, *NP;

typedef int LList;

typedef int Top;

void inputLLrecord(NP *temp);

void initlist(NP *head){
    *head=NULL;
}

void push(NP *head, int ID){
    NP temp;
    temp=malloc(sizeof(Node));
    if(temp!=NULL){
        temp->info.ID=ID;
        temp->link=*head;
        *head=temp;
    }
}


void pop(NP *head){
    NP temp;
    if(head!=NULL){
        temp=*head;
        *head=temp->link;
        free(temp);
    }
}

void visualizelist(NP head){
    NP trav;
    for(trav=head; trav!=NULL; trav=trav->link){
        printf("\nID [%d]", trav->info.ID);
    }
    printf("print\n\n");
}

void insertlast(NP *head, int ID){
    NP temphead=NULL, temp;
    while(*head!=NULL){
        temp=*head;
        *head=temp->link;
        temp->link=temphead;
        temphead=temp;
    }
    push(head, ID);
    
    while(temphead!=NULL){
        temp=temphead;
        temphead=temp->link;
        temp->link=*head;
        *head=temp;
    }
}

void main(){
    NP head;
    initlist(&head);
    push(&head,100);
    push(&head,200);
    push(&head,300);
    visualizelist(head);
    insertlast(&head, 50);
    visualizelist(head);
}