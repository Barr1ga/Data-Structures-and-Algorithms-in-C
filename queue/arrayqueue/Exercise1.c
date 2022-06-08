#include "Exercise1.h"

int get_queue_length(CircularArrayQueue list){
    int size;
    return size = (list.rear>list.front)? (list.rear-list.front)+1 : MAX+1-(list.front-list.rear);
}

PersonLinkedList get_all_females(CircularArrayQueue list){
    PersonLinkedList femaleList=NULL, tempPersonNode;
    Person frontSaved;
    int temp=list.rear;
    printf("\ntemp = %d",temp);
    while(list.front!=temp){
        frontSaved=front(list);
        if(frontSaved.sex=='f'){
            tempPersonNode=malloc(sizeof(PersonNode));
            if(tempPersonNode!=NULL){
                tempPersonNode->elem=frontSaved;
                tempPersonNode->next=femaleList;
                femaleList=tempPersonNode;
            }
        }
        dequeue(&list);
        enqueue(&list, frontSaved);
    }
    return femaleList;
}

PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
    Person frontSaved;
    int i=0;
    PersonDynamicArrayList newMaleList;
    init_DAL(&newMaleList);
    int temp=list->rear;
    while((list->front-1)%MAX!=temp){
        frontSaved=list->data[list->front];//save front
        if(frontSaved.sex=='m'){
            newMaleList.data[i]=frontSaved;
            i++;
            
        }else{
            list->rear=(list->rear+1)%MAX;//move rear
            list->data[list->rear]=frontSaved;//copy saved to rear
        }
        list->front=(list->front+1)%MAX;//move front
    }
    return newMaleList;
}