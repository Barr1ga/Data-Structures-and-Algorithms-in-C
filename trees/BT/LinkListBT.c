#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;
typedef struct node {
    Elemtype elem;
    struct node *left;
    struct node *right;
}nodetype, *BT;

Elemtype inputData();
void preOrderCreatePOINTER(BT *root);       //v1
void inOrderCreatePOINTER(BT *root);        //v1
void postOrderCreatePOINTER(BT *root);      //v1
BT preOrderCreate();                   //v2
BT inOrderCreate();                    //v2
BT postOrderCreate();                  //v2
int display(BT root);
void preOrderDisplay(BT root);
void inOrderDisplay(BT root);
void postOrderDisplay(BT root);


Elemtype inputData(){
    Elemtype ret;
    printf("*Enter -1 to stop*\n");
    printf("Child: ");
    scanf("%d", &ret);
    return ret;
}


void preOrderCreatePOINTER(BT *root){
    Elemtype ret=inputData();
    if(ret!=-1){
        *root=(BT)calloc(1, sizeof(nodetype));
        
        printf("\nPost Assigning data %d...\n", ret);
        if(*root!=NULL){
            (*root)->elem=ret;
        }
        
        printf("\nEnter LEFT child of parent [%d]\n ", ret);
        preOrderCreatePOINTER(&(*root)->left);

        printf("\nEnter RIGHT child of parent [%d]\n", ret);
        preOrderCreatePOINTER(&(*root)->right);
    }
}

void inOrderCreatePOINTER(BT *root){
    Elemtype ret=inputData();
    if(ret!=-1){
        *root=(BT)calloc(1, sizeof(nodetype));

        printf("\nEnter LEFT child of parent [%d]\n ", ret);
        inOrderCreatePOINTER(&(*root)->left);

        printf("\nPost Assigning data %d...\n", ret);
        if(*root!=NULL){
            (*root)->elem=ret;
        }

        printf("\nEnter RIGHT child of parent [%d]\n", ret);
        inOrderCreatePOINTER(&(*root)->right);
    }
}

void postOrderCreatePOINTER(BT *root){
    Elemtype ret=inputData();
    if(ret!=-1){
        *root=(BT)calloc(1, sizeof(nodetype));
        
        printf("\nEnter LEFT child of parent [%d]\n ", ret);
        postOrderCreatePOINTER(&(*root)->left);

        printf("\nEnter RIGHT child of parent [%d]\n", ret);
        postOrderCreatePOINTER(&(*root)->right);
        
        printf("\nPost Assigning data %d...\n", ret);
        if(*root!=NULL){
            (*root)->elem=ret;
        }
    }
}

 
BT preOrderCreate(){
    BT node;
    Elemtype ret=inputData();
    if(ret!=-1){
        node=(BT)calloc(1, sizeof(nodetype));

        printf("\nPost Assigning data %d...\n", ret);
        node->elem=ret;
        
        printf("\nEnter LEFT child of parent [%d]\n ", ret);
        node->left=preOrderCreate();

        printf("\nEnter RIGHT child of parent [%d]\n", ret);
        node->right=preOrderCreate();
        return node;
    }else{
        return NULL;
    }
}

BT inOrderCreate(){
    BT node;
    Elemtype ret=inputData();
    if(ret!=-1){
        node=(BT)calloc(1, sizeof(nodetype));

        printf("\nEnter LEFT child of parent [%d]\n ", ret);
        node->left=inOrderCreate();

        printf("\nPost Assigning data %d...\n", ret);
        node->elem=ret;

        printf("\nEnter RIGHT child of parent [%d]\n", ret);
        node->right=inOrderCreate();
        return node;
    }else{
        return NULL;
    }
}

BT postOrderCreate(){
    BT node;
    Elemtype ret=inputData();
    if(ret!=-1){
        node=(BT)calloc(1, sizeof(nodetype));
        
        printf("\nEnter LEFT child of parent [%d]\n ", ret);
        node->left=postOrderCreate();

        printf("\nEnter RIGHT child of parent [%d]\n", ret);
        node->right=postOrderCreate();

        printf("\nPost Assigning data %d...\n", ret);
        
        node->elem=ret;
        return node;
    }else{
        return NULL;
    }
}

// display

int display(BT root){
    int choose;
    printf("\n\nDisplay in...\n");
    printf("[0] Exit\n");
    printf("[1] Pre-order\n");
    printf("[2] In-order\n");
    printf("[3] Post-order\n");

    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case 1:
            preOrderDisplay(root);
            break;
        case 2: 
            inOrderDisplay(root);
            break;
        case 3:
            postOrderDisplay(root);
            break;
    }
    return choose;
}

void preOrderDisplay(BT root){
    if(root!=NULL){
        printf("%d ", root->elem);
        preOrderDisplay(root->left);
        preOrderDisplay(root->right);
    }
}

void inOrderDisplay(BT root){
    if(root!=NULL){
        preOrderDisplay(root->left);
        printf("%d ", root->elem);
        preOrderDisplay(root->right);
    }
}

void postOrderDisplay(BT root){
    if(root!=NULL){
        preOrderDisplay(root->left);
        preOrderDisplay(root->right);
        printf("%d ", root->elem);

    }
}

void main(){
    BT root=NULL;
    int choose;
    printf("\n\nCreate Tree in...\n");
    printf("[1] Pre-order -- *w/ pointers*\n");
    printf("[2] In-order -- *w/ pointers*\n");
    printf("[3] Post-order -- *w/ pointers*\n");

    printf("[4] Pre-order -- *w/ return node*\n");
    printf("[5] In-order -- *w/ return node*\n");
    printf("[6] Post-order -- *w/ return node*\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case 1:
            printf("Enter root node data\n");
            preOrderCreatePOINTER(&root);
            break;
        case 2: 
            printf("Enter root node data\n");
            inOrderCreatePOINTER(&root);
            break;
        case 3:
            printf("Enter root node data\n");
            postOrderCreatePOINTER(&root);
            break;
        case 4:
            printf("Enter root node data\n");
            root=preOrderCreate();
            break;
        case 5: 
            printf("Enter root node data\n");
            root=inOrderCreate();
            break;
        case 6:
            printf("Enter root node data\n");
            root=postOrderCreate();
            break;
    }
    
    do{
        choose=display(root);
    }while(choose!=0);
    
}