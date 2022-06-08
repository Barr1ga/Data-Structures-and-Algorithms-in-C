#include <stdio.h>
#include <string.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%15s | %5c | %15s}", p.name, p.sex, p.city);
} 




/* Static Array List*/


void init_SAL(PersonStaticArrayList *list){
    list->count=0;
}

void insert_first_SAL(PersonStaticArrayList *list, Person p){
    int i;
    if(list->count!=MAX_LIST){
        for(i=list->count; i>1; i--){
            list->data[i]=list->data[i-1];
        }
        list->data[0]=p;
        list->count+=1;
    }
    
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){
    if(list->count!=MAX_LIST){
        list->data[list->count]=p;
        list->count++;
    }
    
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
    int i;
    if(list->count!=MAX_LIST){
        for(i=list->count; i>index+1; i--){
            list->data[i]=list->data[i-1];
        }
        list->data[index]=p;
        list->count+=1;
    }
    
}

void delete_first_SAL(PersonStaticArrayList *list){
    int i;
    if(list->count>0){
        for(i=0;i<list->count;i++){
            list->data[i]=list->data[i+1];
        }
        list->count-=1;
    }
    
}

void delete_last_SAL(PersonStaticArrayList *list){
    if(list->count>0){
        list->count-=1;
    }
    
}

void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){
    int i,j;
    if(list->count>0){
        for(i=0; i<list->count; i++){
            if(list->data[i].sex=='f'){
                for(j=i; j<list->count; j++){
                    list->data[j]=list->data[j+1];
                }
                list->count-=1;
            }
        }
    }
    
} // all ocurrences

void display_SAL(PersonStaticArrayList list){
    int i;
    if(list.count>0){
        for(i=0;i<list.count; i++){
            displayPersonInfo(list.data[i]);
            printf("\n");
        }
    }
    
}








/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list){
    list->count=0;
    list->max=5;
    list->data=malloc(list->max * sizeof(Person));
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
    int i;
    if(list->count == list->max && list->max < MAX_LIST){
        list->data=realloc(list->data, (list->max*2)*sizeof(Person));
        list->max*=2;
    }
    if(list->count < list->max){
        for(i=list->count; i>1; i--){
            list->data[i]=list->data[i-1];
        }
        list->data[0]=p;
        list->count+=1;
    }
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
    int i;
    if(list->count == list->max && list->max < MAX_LIST){
        list->data=realloc(list->data, (list->max*2)*sizeof(Person));
        list->max*=2;
    }
    if(list->count < list->max){
        list->data[list->count]=p;
        list->count+=1;
    }
}

void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
    int i;
    if(list->count == list->max && list->max < MAX_LIST){
        list->data=realloc(list->data, (list->max*2)*sizeof(Person));
        list->max*=2;
    }
    if(list->count < list->max){
        for(i=list->count; i>index+1; i--){
            list->data[i]=list->data[i-1];
        }
        list->data[index]=p;
        list->count+=1;
    }
}

void delete_first_DAL(PersonDynamicArrayList *list){
    int i;
    if(list->count > 0){
        for(i=0; i<list->count; i++){
            list->data[i]=list->data[i+1];
        }
        list->count-=1;
    }
}

void delete_last_DAL(PersonDynamicArrayList *list){
    if(list->count > 0){
        list->count-=1;
    }
}

void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
    int i;
    if(list->count > 0){
        for(i=0; i<list->count; i++){
            if(strcmp(list->data[i].city, city)==0){
                for(;i<list->count; i++){
                    list->data[i]=list->data[i+1];
                }
                list->count-=1;
                break;
            }
        }
    }
} // first ocurrence

void display_DAL(PersonDynamicArrayList list){
    int i;
    for(i=0;i<list.count; i++){
        displayPersonInfo(list.data[i]);
        printf("\n");
    }
}







//(Note: Sir i am wondering why only init is **list and not the rest. 
//wouldnt the following functions be just the same with the previous version
//if it isnt accessed from a pointer pointing to a pointer?
//with PersonDynamicArrayList **list or *PersonDynamicArrayListPointer)


/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list){
    (*list)->count=0;
    (*list)->max=5;
    (*list)->data=malloc((*list)->max * sizeof(Person));
}

void insert_first_DAL_2(PersonDynamicArrayList *list, Person p){
    int i;
    if(list->count == list->max && list->max < MAX_LIST){
        list->data=realloc(list->data, (list->max*2)*sizeof(Person));
        list->max*=2;
    }
    if(list->count < list->max){
        for(i=list->count; i>1; i--){
            list->data[i]=list->data[i-1];
        }
        list->data[0]=p;
        list->count+=1;
    }
}

void insert_last_DAL_2(PersonDynamicArrayList *list, Person p){
    int i;
    if(list->count == list->max && list->max < MAX_LIST){
        list->data=realloc(list->data, (list->max*2)*sizeof(Person));
        list->max*=2;
    }
    if(list->count < list->max){
        list->data[list->count]=p;
        list->count+=1;
    }
}

void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index){
    int i;
    if(list->count == list->max && list->max < MAX_LIST){
        list->data=realloc(list->data, (list->max*2)*sizeof(Person));
        list->max*=2;
    }
    if(list->count < list->max){
        for(i=list->count; i>index+1; i--){
            list->data[i]=list->data[i-1];
        }
        list->data[index]=p;
        list->count+=1;
    }
}

void delete_first_DAL_2(PersonDynamicArrayList *list){
    int i;
    if(list->count > 0){
        for(i=0; i<list->count; i++){
            list->data[i]=list->data[i+1];
        }
        list->count-=1;
    }
}

void delete_last_DAL_2(PersonDynamicArrayList *list){
    if(list->count > 0){
        list->count-=1;
    }
}

void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name){
    int i,j;
    if(list->count > 0){
        for(i=0; i<list->count; i++){
            if(strcmp(list->data[i].name, name)==0){
                j=i;
            }
        }
        for(i=j; i<list->count; i++){
            list->data[i]=list->data[i+1];
        }
        list->count-=1;
    }
} // last ocurrence

void display_DAL_2(PersonDynamicArrayList list){
    int i;
    for(i=0;i<list.count; i++){
        printf("\n");
        displayPersonInfo(list.data[i]);
    }
}







/* Singly Linked List */

void insert_first_LL(PersonLinkedList *list, Person p){
    PersonLinkedList temp;
    temp=malloc(sizeof(PersonNode));
    if(temp!=NULL){
        temp->elem=p;
        temp->next=*list;
        *list=temp;
    }
}

void insert_last_LL(PersonLinkedList *list, Person p){
    PersonLinkedList temp, *trav;
    temp=malloc(sizeof(PersonNode));
    if(temp!=NULL){
        for(trav=list; *trav!=NULL; trav=&(*trav)->next){
        }
        temp->elem=p;
        temp->next=*trav;
        *trav=temp;
    }
}

void insert_after_LL(PersonLinkedList *list, Person p, String name){
    PersonLinkedList temp, *trav;
    temp=malloc(sizeof(PersonNode));
    temp->elem=p;
    if(temp!=NULL){
        for(trav=list; *trav!=NULL && strcmp((*trav)->elem.name, name)<0; trav=&(*trav)->next){
        }
        temp->next=*trav;
        *trav=temp;
    }
}

void delete_first_LL(PersonLinkedList *list){
    PersonLinkedList temp;
    temp=*list;
    *list=temp->next;
}

void delete_last_LL(PersonLinkedList *list){
    PersonLinkedList *trav;
    for(trav=list; (*trav)->next!=NULL; trav=&(*trav)->next){
    }
    free(*trav);
    *trav=NULL;
}

void delete_by_city_LL(PersonLinkedList *list, String city){
    PersonLinkedList *trav, temp;
    for(trav=list; *trav!=NULL; trav=&(*trav)->next){
        if(strcmp((*trav)->elem.city, city)==0){
            temp=*trav;
            *trav=temp->next;
            free(temp);
        }
    }
} // all ocurrences

void display_LL(PersonLinkedList list){
    PersonLinkedList trav;
    for(trav=list; trav!=NULL; trav=trav->next){
        printf("\n");
        displayPersonInfo(trav->elem);
    }
}








/* Implement all VSpace conncept and Cusor Based List*/

void init_vspace(VSpace *vs){
    int i;
    for(i=MAX_VSPACE-1; i>=0; --i){
        vs->data[i].next=i-1;
    }
    vs->avail=MAX_VSPACE-1;
}

Position alloc_space(VSpace *vs){
    Position ret;
    if(vs->avail!=-1){
        ret=vs->avail;
        vs->avail=vs->data[ret].next;
    }
    return ret;
}

void free_space(VSpace *vs, Position index){
    vs->data[index].next=vs->avail;
    vs->avail=index;
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    Position temp;
    temp=alloc_space(vs);
    if(temp!=-1){
        vs->data[temp].elem=p;
        vs->data[temp].next=*list;
        *list=temp;
    }
}

void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    Position *i, temp;
    temp=alloc_space(vs);
    if(temp!=-1){
        for(i=list; *i!=-1; i=&(vs->data[*i].next)){
        }
        vs->data[temp].elem=p;
        vs->data[temp].next=*i;
        *i=temp;
    }
}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index){
    Position i;
    if(vs->avail!=-1){
        for(i=0; i<MAX_VSPACE; i++){

        }

    }
    
}

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
    Position temp;
    if(*list!=-1){
        temp=*list;
        *list=vs->data[*list].next;
        free_space(vs, temp);
    }
}

void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){
    Position *i;
    if(*list!=-1){
        for(i=list; vs->data[*i].next!=-1; i=&(vs->data[*i].next)){
        }
        free_space(vs, *i);
        *i=-1;
    }
}

void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex){
    Position *i, temp;
    if(*list!=-1){ 
        i=list;
        while(*i!=-1){
            if(vs->data[*i].elem.sex=='f'){
                temp=*i;
                *i=vs->data[*i].next;
                free_space(vs, temp);
            }else{
                i=&(vs->data[*i].next);
            }
        }
    }
} // all ocurrences

void display_CBL(VSpace vs, PersonCusorBasedList list){
    int i;
    for(i=list; i!=-1; i=vs.data[i].next){
        printf("\n");
        displayPersonInfo(vs.data[i].elem);
    }
}