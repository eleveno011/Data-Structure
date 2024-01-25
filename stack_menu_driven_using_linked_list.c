#include<stdio.h>
#include<stdlib.h>

struct stack{
   int value;
   struct stack *next;
};

void isempty(struct stack *top);
void push(struct stack **top);
int pop(struct stack **top);
void traverse(struct stack *top);


int main(){
    struct stack *top=NULL;

     printf("MENU\n 1.push\n 2.pop\n 3.isempty\n 4.traverse\n 5.EXIT\n");

    int option;
   start:printf("enter option:");
    scanf("%d",&option);

    switch(option){
        case 1:push(&top);
               goto start;
        case 2:printf("element deleted is:%d\n",pop(&top));
               goto start;
        case 3:isempty(top);
               goto start;
        case 4:traverse(top);
               goto start;
        case 5:printf("you are exited");
    }
    return 0;
}

void isempty(struct stack *top){
    if(top==NULL){
      printf("stack is empty\n");
      exit(0);
    }
    
    printf("stack is not empty\n");
    
}

void push(struct stack **top){
     int k;
     printf("enter the value,you want to be pushed:");
     scanf("%d",&k);

     struct stack *new;
     new=(struct stack*)malloc(sizeof(struct stack));

     if(new==NULL){
        printf("memory is not allocated\n");
        exit(-1);
     }
        new->value=k;
        new->next=*top;
        *top=new;
     
}

int  pop(struct stack **top){

    if(*top==NULL){
        printf("stack underflow\n");
        return 0;
    }

    struct stack *temp=*top;
    int  k=(*top)->value;
    *top=(*top)->next;
    free(temp);
    return k;
}

void traverse(struct stack *top){
    if(top==NULL){
        printf("stack is empty");
        exit(-1);
    }
    while(top!=NULL){
        printf("%d ",top->value);
        top=top->next;
    }
    printf("\n");
}

