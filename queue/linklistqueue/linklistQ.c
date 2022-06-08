#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

typedef struct node{
    Person elem;
    struct node *next;
} PersonNode, *PersonLinkedList; //link list

typedef struct{
    PersonLinkedList front;
    PersonLinkedList rear;
}Queue;

Person createPerson(String name, char sex, String city){
    Person ret;
    strcpy(ret.name, name);
    ret.sex=sex;
    strcpy(ret.city, city);
    return ret;
}

typedef struct{
    int M;
}S, *P;



void initQueue(Queue *list){
    list->front=NULL;
    list->rear=NULL;
}

bool enqueue(Queue *list, Person p){
    PersonLinkedList temp;
    bool ret=false;
    temp=malloc(sizeof(PersonNode));
    if(temp!=NULL){
        ret=true;
        temp->elem=p;
        temp->next=NULL;
        if(list->front!=NULL){
            list->rear->next=temp;
        }else{
            list->front=temp;
        }
        list->rear=temp;
    }
    return ret;
}

bool dequeue(Queue *list){
    PersonLinkedList temp;
    bool ret=false;
    temp=list->front;
    if(temp!=NULL){
        list->front=temp->next;
        free(temp);
        if(list->front==NULL){
            list->rear=NULL;
        }
    }
}

bool is_empty(Queue list){
    bool ret;
    return ret=(list.front==NULL)? true : false;
}

Person front(Queue list){
    Person p=list.front->elem;
    return p;
}

bool insertSorted(Queue *list, Person p){
    Queue tempList;
    PersonLinkedList temp;
    initQueue(&tempList);

    while(list->front!=NULL && strcmp(list->front->elem.name, p.name)<0){
        temp=list->front;
        list->front=list->front->next;
        temp->next=NULL;
        if(tempList.rear==NULL){
            tempList.front=temp;
        }else{
            tempList.rear->next=temp;
        }
        tempList.rear=temp;
    }

    temp=malloc(sizeof(PersonNode));
    if(temp!=NULL){
        temp->elem=p;
        temp->next=NULL;
        if(tempList.rear==NULL){
            tempList.front=temp;
        }else{
            tempList.rear->next=temp;
        }
        tempList.rear=temp;
    }
}

void displayPersonInfo(Person p){
    printf("%30s | %c | %15s", p.name, p.sex, p.city);
}

void visualization(Queue list){
    PersonLinkedList trav;
    if(is_empty==false){
        for(trav=list.front; trav!=NULL; trav=trav->next){
            printf("test");
            printf("%s",trav->elem.name);
            displayPersonInfo(trav->elem);
        }
    }
    
}