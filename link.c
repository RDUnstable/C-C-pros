#include <stdio.h>
#include <stdlib.h>

struct noe{
    int data;
    struct noe *link;
};
int length = 0;
typedef struct noe node;

node *start = NULL;

void add(int n){
   node *temp,*curr;
   temp = (node *)malloc(sizeof(node));
   temp->data = n;
   temp->link = NULL;
   if(start == NULL){
    start = temp;
    length++;
   }
   else{
    curr = start;
    while(curr->link!=NULL){
        curr = curr->link;
    }
    curr->link = temp;
    length++;
   }
}

void dellast(void){
    node *curr;
    if(start == NULL){
        printf("\nNothing to delete");
    }
    else{
        curr = start;
        while(curr->link->link != NULL){
            curr = curr->link;
        }
        free(curr->link);
        curr->link = NULL;
        length--;
    }
}

void display(void){
    node *curr;
    if(start == NULL){
        printf("\nNothing to display");
    }
    else{
        curr = start;
        while(curr!=NULL){
            printf("\t%d",curr->data);
            curr = curr->link;
        }
    }

}

void delfirst(void){
   if(start == NULL){
    printf("\nNothing in list");
   }
   else{
    node *curr;
    curr = start;
    start = start->link;
    free(curr);
    length--;
   }
}

void delval(int n){
   node *curr;
   curr = start;
   while(curr->link->data != n){
    curr = curr->link;
    if(curr == NULL){
        break;
    }
   }

   if(curr->link->data == n){
    node *temp;
    temp = curr->link;
    curr->link = temp->link;
    free(temp);
    length--;
   }
   else if (curr == NULL ){
    printf("\nValue not in list");
   }
}

void delpos(int pos){
   if(pos > length){
        printf("\nInvalid position");
    }
   int i = 1;
   node *curr,*temp;
   if(start == NULL){
    printf("\nThe list is empty");
   }
   else{
    curr = start;
    while(curr!=NULL){
        if(i == pos - 1){
            break;
        }
        else{
            curr = curr->link;
            i++;
        }
    }
    temp = curr->link;
    curr->link = temp->link;
    free(temp);
    length--;
   }
}

void addbeg(int n){
    node *temp,*curr;
    temp = (node *)malloc(sizeof(node));
    temp->data = n;
    curr = temp;
    temp->link = start;
    temp = temp->link;
    start = curr;
    start->link = temp;
    length++;
}

void addpos(int pos){
    int i = 1;
    if(pos > lwngth){
        printf("\nInvalid position");
    }
    else{
        node *temp,*curr;
        temp = (node *)malloc(sizeof(node));
        printf("\nEnter data: ");
        scanf("%d",&temp->data);
        curr = start;
        while(i != pos - 1){
            curr = curr->link;
            i++;
        }
        temp->link = curr->link;
        curr->link = temp;
        length++;
    }
}

int main(){
    while(1){
    printf("\n1>add(),2>dellast(),3>display(),4>delfirst(),5>delval(),6>delpos(),7>addbeg(),8>addpos()");
    int c;
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    switch(c){

        case 1:printf("\nEnter data: ");
               int d;
               scanf("%d",&d);
               add(d);
               printf("\nThe length of the list is %d currently",length);
               break;

        case 2:dellast();
               printf("\nThe length of the list is %d currently",length);
               break;

        case 3:display();
               printf("\nThe length of the list is %d currently",length);
               break;

        case 4:delfirst();
               printf("\nThe length of the list is %d currently",length);
               break;

        case 5:printf("\nEnter value to delete: ");
               int del;
               scanf("%d",&del);
               delval(del);
               printf("\nThe length of the list is %d currently",length);
               break;

        case 6:printf("\nEnter position: ");
               int pos;
               scanf("%d",&pos);
               delpos(pos);
               printf("\nThe length of the list is %d currently",length);
               break;

        case 7:printf("\nEnter data: ");
               int f;
               scanf("%d",&f);
               addbeg(f);
               printf("\nThe length of the list is %d currently",length);
               break;

        case 8:printf("\nEnter the position of enering: ");
               int po;
               scanf("%d",&po);
               addpos(po);
               printf("\nThe length of the list is %d currently",length);
               break;



        case 0:
            exit(0);
            break;
   }
}
return 0;
}

