#include<stdio.h>
#include<stdlib.h>
#define max 5

struct stack{
    int top;
    int stack_arr[max];
};

struct stack *s;

void push();
int pop();
int isempty();
int isfull();
void traverse();


int main(){
    s=(struct stack*)malloc(sizeof(struct stack));
   s->top=-1;
   printf("MENU\n 1.push\n 2.pop\n 3.is empty\n 4.is full\n 5.traverse\n 6.exit\n");
   int option;
   start:printf("enter option:");
   scanf("%d",&option);

   switch(option){
    case 1:push();
          goto start;
    case 2:printf("element deleted:%d\n",pop());
          goto start;
    case 3:isempty();
          goto start;
    case 4:isfull();
           goto start;
    case 5:traverse();
          goto start;
    case 6:printf("you are exited");
   }
    return 0;
}

void push(){
    int data;
    printf("enter element to be pushed into the stack:");
    scanf("%d",&data);
    if(s->top==max-1){
      printf("stack overflow\n");
      return;
    }
    s->top+=1;
    s->stack_arr[s->top]=data;
}

int pop(){
    int value;
    if(s->top==-1){
      printf("stack underflow");
      exit(1);
    }
    value=s->stack_arr[s->top];
    s->top--;
    return value;
}

int isempty(){
    if(s->top==-1){
        printf("true\n");
        return 0;
    }
    printf("false\n");
}

int isfull(){
    if(s->top==max-1){
        printf("true\n");
        return 0;
    }
     printf("false\n");
}

void traverse(){
      
     printf("elements of stack is:");
     for(int i=0;i<=s->top;i++){
         printf("%d ",s->stack_arr[i]);
     } 
     printf("\n");
}





