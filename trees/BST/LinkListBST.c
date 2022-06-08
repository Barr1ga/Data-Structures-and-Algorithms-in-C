#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;
typedef struct node {
    Elemtype elem;
    struct node *left;
    struct node *right;
}nodetype, *BST;

void initBST(BST *head);
void insertBST(BST *head, Elemtype data);
void deleteBST(BST *head, Elemtype data);
void DelBSTmin(BST *head);
void DelBSTmax(BST *head);
int member(BST *head, Elemtype data);
Elemtype min(BST head);
Elemtype max(BST head);

void recursiveInsertBST(BST *head, Elemtype data);
Elemtype recursiveDeleteBST(BST *head, Elemtype data);
void recDelBSTmin(BST *head);
void recDelBSTmax(BST *head);
int recursiveMember(BST head, Elemtype data);
Elemtype recursiveMin(BST head);
Elemtype recursiveMax(BST head);

// void recursiveInsertPreOrder(BST *head);

void preOrder(BST head);
void inOrder(BST head);
void postOrder(BST head);

void initBST(BST *head){
    *head = NULL;
}

int isCoursings(BST *head, Elemtype data1, Elemtype data2){
    BST *trav1=head, *trav2=head, temp;
    int relationship=0;
    while(*trav1 != NULL && trav2 != NULL && trav1 == trav2){
        trav1 = ((*trav1)->elem < data1)? &(*trav1)->right: &(*trav1)->left;
        trav2 = ((*trav2)->elem < data2)? &(*trav2)->right: &(*trav2)->left;
    }

    if(*trav1!=NULL && trav2!=NULL){
        if(((*trav1)->left->elem == data1 || (*trav1)->right->elem == data1)){
            relationship++;
        }
        if(((*trav2)->left->elem == data2 || (*trav2)->right->elem == data2)){
            relationship++;
        }
    }

    if(relationship/2 == 1){
        printf("The elements are cousins");
    }else{
        printf("The elements are not cousing");
    }
    system("PAUSE");
    return relationship/2;
}

int subTreeHeight(BST head){
    int lheight=0;
    int rheight=0;
    if(head!=NULL){ 
        lheight=subTreeHeight(head->left);
        rheight=subTreeHeight(head->right);
        if(lheight>rheight){
            return lheight+1;
        }else{
            return rheight+1;
        }
    }else{
        return 0;
    }
}//[4] [3] [7] [8] [6]




// Non recursive

void insertBST(BST *head, Elemtype data){
    BST *trav=head;
    while(*trav!=NULL && (*trav)->elem!=data){
        trav = ((*trav)->elem < data)? &(*trav)->right : &(*trav)->left;
    }
    if(*trav==NULL){
        *trav=(BST)calloc(1, sizeof(nodetype));
        if(*trav!=NULL){
            (*trav)->elem=data;
        }
    }
}

void deleteBST(BST *head, Elemtype data){
    BST *trav=head, *trav2, temp;
    while(*trav!=NULL && (*trav)->elem!=data){
        trav = ((*trav)->elem < data)? &(*trav)->right : &(*trav)->left;
    }

    if(*trav!=NULL){
        if((*trav)->left==NULL){
            temp=*trav;
            *trav=temp->right;
            free(temp);
        }else if((*trav)->right==NULL){
            temp=*trav;
            *trav=temp->left;
            free(temp);
        }else{
            for(trav2=&(*trav)->right; (*trav2)->left!=NULL; trav2=&(*trav2)->left){}
            temp=*trav2;
            *trav2=temp->right;
            (*trav)->elem=temp->elem;
            free(temp);
        }
    }
}

void DelBSTmin(BST *head){
    BST *trav=head, temp;
    while((*trav)->left!=NULL){
        trav=&(*trav)->left;
    }
    if(*trav!=NULL){
        temp=*trav;
        *trav=(*trav)->right;
        free(temp);
    }
}

void DelBSTmax(BST *head){
    BST *trav=head, temp;
    while((*trav)->right!=NULL){
        trav=&(*trav)->right;
    }
    if(*trav!=NULL){
        temp=*trav;
        *trav=(*trav)->left;
        free(temp);
    }
}

int member(BST *head, Elemtype data){
    BST *trav=head;
    while(*trav!=NULL && (*trav)->elem!=data){
        trav=((*trav)->elem < data)? &(*trav)->right: &(*trav)->left;
    }
    return (*trav==NULL)? 0 : 1;
}

Elemtype min(BST head){
    BST trav=head;
    while(trav->left!=NULL){
        trav=trav->left;
    }
    return trav->elem;
}

Elemtype max(BST head){
    BST trav=head;
    while(trav->right!=NULL){
        trav=trav->right;
    }
    return trav->elem;
}


// Recursive

void recursiveInsertBST(BST *head, Elemtype data){
    BST *trav=head;

    if(*trav!=NULL){
        if((*trav)->elem < data && (*trav)->elem!=data){
            recursiveInsertBST(&(*trav)->right, data);
        }else{ 
            recursiveInsertBST(&(*trav)->left, data);
        }
    }else{
        *trav=(BST)calloc(1, sizeof(nodetype));
        if(*trav!=NULL){
            (*trav)->elem=data;
        }
    }
}

Elemtype recursiveDeleteBST(BST *head, Elemtype data){
    BST *trav=head, temp;
    if(*trav!=NULL && (*trav)->elem!=data){
        if((*trav)->elem < data){
            recursiveDeleteBST(&(*trav)->right, data);
        }else{
            recursiveDeleteBST(&(*trav)->left, data);
        }
    }else{
        if((*trav)->left == NULL){
            temp=*trav;
            *trav=temp->right;
            free(temp);
        }else if((*trav)->right == NULL){
            temp=*trav;
            *trav=temp->left;
            free(temp); 
        }else{
            temp=*trav;
            (*trav)->elem=recursiveDeleteBST(&(*trav)->right, data);
        }
    }
}

void recDelBSTmin(BST *head){
    BST *trav=head, temp;
    Elemtype ret;
    if((*trav)->left!=NULL){
        recDelBSTmin(&(*trav)->left);
    }else{
        temp=*trav;
        *trav=temp->right;
        ret=temp->elem;
        free(temp);
    }
}

void recDelBSTmax(BST *head){
    BST *trav=head, temp;
    Elemtype ret;
    if((*trav)->right!=NULL){
        recDelBSTmin(&(*trav)->right);
    }else{
        temp=*trav;
        *trav=temp->left;
        ret=temp->elem;
        free(temp);
    }
}

int recursiveMember(BST head, Elemtype data){
    BST trav=head;
    Elemtype ret=0;
    if(trav!=NULL && (trav)->elem!=data){
        if(trav->elem < data){
            ret=recursiveMember(trav->right, data);
        }else{
            ret=recursiveMember(trav->left, data);
        }
    }else{
        ret=1;
    }
    return ret;
}

Elemtype recursiveMin(BST head){
    Elemtype ret;
    if(head->left!=NULL){
        ret=recursiveMin(head->left);
    }else{
        ret=head->elem;
    }
    return ret;
}

Elemtype recursiveMax(BST head){
    Elemtype ret;
    if(head->right!=NULL){
        ret=recursiveMax(head->right);
    }else{
        ret=head->elem;
    }
    return ret;
}

void preOrder(BST head){
    if(head!=NULL){
        printf("[%d] ", head->elem);
        preOrder(head->left);
        preOrder(head->right);
    }
}//10 6 1 0 4 3 5 7 8 9 17 12 11 19

void inOrder(BST head){
    if(head!=NULL){
        inOrder(head->left);
        printf("[%d] ", head->elem);
        inOrder(head->right);
    }
}//0 1 3 4 5 6 7 8 9 10 11 12 17 19
 
void postOrder(BST head){
    if(head!=NULL){
        postOrder(head->left);
        postOrder(head->right);
        printf("[%d] ", head->elem);
    }
}//0 3 5 4 1 9 8 7 6 11 12 19 17 10



void inputData(){

}

void main (){
    BST head;
    Elemtype data, ret, data1, data2;
    //10 5 8 17 12 19
    initBST(&head);
    int choose;
    do{
        system("CLS");
        printf("\n\nDo operation...\n");
        printf("[0] Exit\n");
        printf("[1] Insert\n");
        printf("[2] Delete\n");
        printf("[3] Delete Min\n");
        printf("[4] Delete Max\n");
        printf("[5] Is Member\n");
        printf("[6] Get Max\n");
        printf("[7] Get Max\n");
        printf("[8] recursive Insert\n");
        printf("[9] recursive Delete\n");
        printf("[10] recursive Delete Min\n");
        printf("[11] recursive Delete Max\n");
        printf("[12] recursive Is Member\n");
        printf("[13] recursive Get Min\n");
        printf("[14] recursive Get Max\n");
        printf("[15] preOrder\n");
        printf("[16] inOrder\n");
        printf("[17] postOrder\n");
        printf("[18] is Cousins\n");
        printf("Choose: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBST(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteBST(&head, data);
                system("PAUSE");
                break;
            case 3:
                DelBSTmin(&head);
                system("PAUSE");
                break;
            case 4:
                DelBSTmax(&head);
                system("PAUSE");
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                ret=member(&head, data);
                printf("Is member = [%d]", ret);
                system("PAUSE");
                break;
            case 6:
                ret=min(head);
                printf("Recursive Max = [%d]", ret);
                system("PAUSE");
                break;
            case 7:
                ret=max(head);
                printf("Recursive Max = [%d]", ret);
                system("PAUSE");
                break;
            case 8:
                printf("Enter data: ");
                scanf("%d", &data);
                recursiveInsertBST(&head, data);
                break;
            case 9:
                printf("Enter data: ");
                scanf("%d", &data);
                recursiveDeleteBST(&head, data);
                system("PAUSE");
                break;
            case 10:
                recDelBSTmin(&head);
                system("PAUSE");
                break;
            case 11:
                recDelBSTmax(&head);
                system("PAUSE");
                break;
            case 12:
                printf("Enter data: ");
                scanf("%d", &data);
                ret=recursiveMember(head, data);
                printf("Is member = [%d]", ret);
                system("PAUSE");
                break;
            case 13:
                ret=recursiveMin(head);
                printf("Recursive Min = [%d]", ret);
                system("PAUSE");
                break;
            case 14:
                ret=recursiveMax(head);
                printf("Recursive Max = [%d]", ret);
                system("PAUSE");
                break;
            case 15:
                preOrder(head);
                system("PAUSE");
                break;
            case 16:
                inOrder(head);
                system("PAUSE");
                break;
            case 17:
                postOrder(head);
                system("PAUSE");
                break;
            case 18:
                printf("\nEnter data1: ");
                scanf("%d", &data1);
                printf("\nEnter data1: ");
                scanf("%d", &data2);
                isCoursings(&head, data1, data2);
        }
    }while(choose!=0);
}