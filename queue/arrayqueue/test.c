#include <stdio.h>
#include <string.h>
#include "Exercise1.c"
#include "Person.c"
#include "CircularArrayQ.c"

int main(void) 
{
    Person p;
    bool ret;
    int i;

    PersonDynamicArrayList maleList;
    PersonLinkedList femaleList;
    CircularArrayQueue list;

    list=create_array_queue();
    init_array_queue(&list);
    
    p=createPerson("horeb", 'm', "cebu");
    ret=enqueue(&list, p);

    p=createPerson("gab", 'f', "danao");
    ret=enqueue(&list, p);

    p=createPerson("dyedo", 'f', "mandaw");
    ret=enqueue(&list, p);

    p=createPerson("daina", 'm', "mandaw");
    ret=enqueue(&list, p);

    displayqueue(list);

    p=createPerson("marvin", 'm', "mandaw");
    ret=enqueuebottom(&list, p);

    displayqueue(list);
    
// Problem 1

    // printf("\nCircArr size [%d]", get_queue_length(list));


// Problem 2

    // femaleList=get_all_females(list);

    // printf("\nfront [%d]\nrear [%d]\n", list.front, list.rear);
    // for(i=0; i<MAX; i++){
    //     printf("\n%2d ",i);
    //     displayPersonInfo(list.data[i]);
    // }

    // printf("\n\nFemale List\n");
    //     display_LL(femaleList);
    //     printf("\n");



    
// Problem 3
     
    // maleList=remove_all_males(&list);

    // printf("\nfront [%d]\nrear [%d]\n", list.front, list.rear);
    // for(i=0; i<MAX; i++){
    //     printf("\n%2d ",i);
    //     displayPersonInfo(list.data[i]);
    // }

    // display_DAL(maleList);


// Link List
    // PersonLinkedList tempList;
    // p=createPerson("AA", 'm', "cebu");
    // insert_last_LL(&tempList, p);

    // p=createPerson("BB", 'f', "danao");
    // insert_last_LL(&tempList, p);

    // p=createPerson("CC", 'f', "mandaw");
    // insert_last_LL(&tempList, p);

    // p=createPerson("EE", 'm', "cebu");
    // insert_last_LL(&tempList, p);

    // p=createPerson("DD", 'm', "cebu");
    // insert_after_LL(&tempList, p, "EE");
    
    // delete_first_LL(&tempList);
    // delete_last_LL(&tempList);
    // delete_by_city_LL(&tempList, "mandaw");

    // display_LL(tempList);


// VSpace

    // VSpace vs;
    // PersonCusorBasedList CBlist=-1;
    // init_vspace(&vs);
    
    // p=createPerson("AA", 'm', "cebu");
    // insert_first_CBL(&vs, &CBlist, p);

    // p=createPerson("BB", 'm', "cebu");
    // insert_first_CBL(&vs, &CBlist, p);

    // p=createPerson("DD", 'm', "cebu");
    // insert_first_CBL(&vs, &CBlist, p);

    // p=createPerson("EE", 'f', "cebu");
    // insert_last_CBL(&vs, &CBlist, p);

    // p=createPerson("FF", 'f', "cebu");
    // insert_last_CBL(&vs, &CBlist, p);

    // p=createPerson("G", 'm', "cebu");
    // insert_last_CBL(&vs, &CBlist, p);

    // delete_first_CBL(&vs, &CBlist);
    // delete_last_CBL(&vs, &CBlist);
    // delete_by_sex_CBL(&vs, &CBlist, 'f');
    
    // // p=createPerson("BB", 'm', "cebu");
    // // insert_first_CBL(&vs, &CBlist, p);
    
    // // p=createPerson("CC", 'm', "cebu");
    // // insert_first_CBL(&vs, &CBlist, p);

    // printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "LINK");
    // for(i=0; i<MAX_VSPACE; i++){
    //     printf("%15d | %15s | %15d\n", i, vs.data[i].elem.name, vs.data[i].next);
    // }
    // printf("available [%d]", vs.avail);

    // display_CBL(vs, CBlist);    


//Dynamic Arr List

    // init_DAL(&maleList);
    // display_DAL(maleList);
    // printf("%d",maleList.count);
    // printf("%d",maleList.max);
    

    return 0;
} 