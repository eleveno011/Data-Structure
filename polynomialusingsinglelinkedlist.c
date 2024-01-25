#include<stdio.h>
#include<stdlib.h>

struct polynomial{
    int coefficient;
    int degree;
    struct polynomial *next;
};

void create(struct polynomial *node);

int main(){
    struct polynomial *node;
    node=(struct polynomial *)malloc(sizeof(struct polynomial));
    if(node==NULL){
        printf("memory is not allocated");
        exit(-1);
    }
    create(node);
    printf("Resultant polynomial:");
    while(node!=NULL){
        printf("%dx^%d+ ",node->coefficient,node->degree);
        node=node->next;
    }
}

void create(struct polynomial *node){
    int n,i=1;
    printf("no. of terms in polynomial:");
    scanf("%d",&n);
    printf("enter coffecient of term %d:",i);
     scanf("%d",&node->coefficient);
     printf("enter degree of term %d:",i);
     scanf("%d",&node->degree);
      node->next=NULL;

    for(int i=2;i<=n;i++){
     node->next=(struct polynomial *)malloc(sizeof(struct polynomial));
     node=node->next;
      printf("enter coffecient of term %d:",i);
     scanf("%d",&node->coefficient);
     printf("enter degree of term %d:",i);
     scanf("%d",&node->degree);
      node->next=NULL;
    
    }
} 