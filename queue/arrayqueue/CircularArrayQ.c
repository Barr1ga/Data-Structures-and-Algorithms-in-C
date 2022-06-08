
#include "CircularArrayQ.h"

CircularArrayQueue create_array_queue(){
    CircularArrayQueue arrQ;
    arrQ.front=-1;
    arrQ.rear=-1;
    return arrQ;
}

void init_array_queue(CircularArrayQueue *list){
    int i;
    for(i=0;i<MAX;i++){
        list->data[i]=
    }
    list->front=1;
    list->rear=0;
}

bool enqueue(CircularArrayQueue *list, Type p){
    bool ret=false;
    if(is_full(*list)==false){
        list->rear=(list->rear+1)%MAX;
        list->data[list->rear]=p;
        ret=true;
    }
    return ret;
}

bool dequeue(CircularArrayQueue *list){
    bool ret=false;
    if(is_empty(*list)==false){
        list->front = (list->front+1)%MAX;
        ret=true;
    }
    return ret;
}

bool is_empty(CircularArrayQueue list){
    bool ret=false;
    if((list.rear+1)%MAX == list.front){
        ret=true;
    }
    return ret;
}

bool is_full(CircularArrayQueue list){
    bool ret=false;
    if((list.rear+2)%MAX == list.front){
        ret=true;
    }
    return ret;
}

Type front(CircularArrayQueue list){
    Type ret=list.data[list.front];
    return ret;
}

void displayqueue(CircularArrayQueue list){
    int i;
    for(i=0;i<MAX; i++){
        printf("%d [%s]\n",i, list.data[i].name);
    }
    printf("front [%d]\n",list.front);
    printf("rear [%d]",list.rear);
    printf("\n\n");
}

bool enqueuebottom(CircularArrayQueue *list, Person p){
    bool ret=false;
    int tempNew;
    tempNew=list->rear;
    list->rear=(list->rear+1)%MAX;
    list->data[list->rear]=p;
    if((list->rear+2)%MAX!=list->front){
        ret=true;
        while((list->front-1)%MAX!=tempNew){
            list->rear=(list->rear+1)%MAX;
            list->data[list->rear]=list->data[list->front];
            list->front=(list->front+1)%MAX;
        }
    }
}