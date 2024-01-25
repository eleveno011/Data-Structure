#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack_arr[max];
int top=-1;

void push();
int pop();
int isempty();
int isfull();
void traverse();


int main(){

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
    if(top==max-1){
      printf("stack overflow\n");
      return;
    }
    top+=1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(top==-1){
      printf("stack underflow");
      exit(1);
    }
    value=stack_arr[top];
    top--;
    return value;
}

int isempty(){
    if(top==-1){
        printf("true\n");
        return 0;
    }
    printf("false\n");
}

int isfull(){
    if(top==max-1){
        printf("true\n");
        return 0;
    }
     printf("false\n");
}

void traverse(){
      
     printf("elements of stack is:");
     for(int i=0;i<=top;i++){
         printf("%d ",stack_arr[i]);
     } 
     printf("\n");
}





