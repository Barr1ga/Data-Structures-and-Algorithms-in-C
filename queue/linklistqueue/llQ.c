#include "linklistQ.c"


void main(){
    Queue list;
    Person p;
    bool truthval;
    initQueue(&list);

    p=createPerson("F", 'n', "ffffffff");
    truthval=enqueue(&list, p);

    p=createPerson("E", 'm', "eeeeeee");
    truthval=enqueue(&list, p);

    p=createPerson("D", 'm', "ccccccc");
    truthval=enqueue(&list, p);

    p=createPerson("C", 'm', "bbbbb");
    truthval=enqueue(&list, p);

    p=createPerson("B", 'm', "aaaaaa");
    truthval=enqueue(&list, p);

    p=createPerson("A", 'm', "aaaaaa");
    truthval=enqueue(&list, p);

    visualization(list);
    

    
}