#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;
typedef struct node {
    Elemtype elem;
    struct node *left;
    struct node *right;
}nodetype, *AVL;

void initAVL(AVL *head);
void insertAVL(AVL *head, Elemtype data);
void deleteAVL(AVL *head, Elemtype data);
void DelAVLmin(AVL *head);
void DelAVLmax(AVL *head);
int member(AVL *head, Elemtype data);
Elemtype min(AVL head);
Elemtype max(AVL head);

void recursiveInsertAVL(AVL *head, Elemtype data);
Elemtype recursiveDeleteAVL(AVL *head, Elemtype data);
void recDelAVLmin(AVL *head);
void recDelAVLmax(AVL *head);
int recursiveMember(AVL head, Elemtype data);
Elemtype recursiveMin(AVL head);
Elemtype recursiveMax(AVL head);

// void recursiveInsertPreOrder(AVL *head);

void preOrder(AVL head);
void inOrder(AVL head);
void postOrder(AVL head);

void initAVL(AVL *head){
    *head=NULL;
}

int recursiveInsertAVL(AVL *head, Elemtype data){
    AVL *trav=head, temp;
    int bal=0;
    if(*trav!=NULL && (*trav)->elem!=data){
        if((*trav)->elem < data){
            bal=recursiveInsertAVL(&(*trav)->right, data);
            if(bal==-2){
                
            }
            if((*trav)->left==NULL){
                bal-=1;
            }
        }else{
            bal=recursiveInsertAVL(&(*trav)->left, data);
            if((*trav)->right==NULL){
                bal+=1;
            }
        }
    }else{
        *trav=(AVL)calloc(1, sizeof(nodetype));
        if(*trav!=NULL){
            (*trav)->elem=data;
        }
    }
    return bal;
}

int getBal(AVL *head){
    int bal=1;
    if(*head!=NULL){
        if((*head)->left!=NULL){
            bal+=1;
            bal+=getBal(&(*head)->left);
        }else if((*head)->right!=NULL){
            bal+=1;
            bal+=getBal(&(*head)->right);
        }
    }
    return bal;    
}

//bgbarriga20@gmail.com

void deleteAVL(AVL *head, Elemtype data){
    AVL *trav=head, *trav2, temp;
    while(*trav!=NULL && (*trav)->elem!=data){
        trav=((*trav)->elem < data)? &(*trav)->right: &(*trav)->left;
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
            (*trav)->elem=temp->elem;
            *trav2=temp->right;
            free(temp);
        }
    }
}




void main (){
    AVL head;
    Elemtype data, ret;
    //10 5 8 17 12 19
    initAVL(&head);
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
        printf("Choose: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAVL(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteAVL(&head, data);
                system("PAUSE");
                break;
            case 3:
                DelAVLmin(&head);
                system("PAUSE");
                break;
            case 4:
                DelAVLmax(&head);
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
                recursiveInsertAVL(&head, data);
                break;
            case 9:
                printf("Enter data: ");
                scanf("%d", &data);
                recursiveDeleteAVL(&head, data);
                system("PAUSE");
                break;
            case 10:
                recDelAVLmin(&head);
                system("PAUSE");
                break;
            case 11:
                recDelAVLmax(&head);
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
        }
    }while(choose!=0);
}