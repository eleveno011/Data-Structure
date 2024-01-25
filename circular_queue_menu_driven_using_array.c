#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

int isempty();
int isfull();
void enqueue();
int dequeue();
void traverse();

int main(){
     printf("MENU\n 1.enqueue\n 2.dequeue\n 3.is empty\n 4.is full\n 5.traverse\n 6.exit\n");
   int option;
   start:printf("enter option:");
   scanf("%d",&option);

   switch(option){
    case 1:enqueue();
          goto start;
    case 2:printf("element dequeued is :%d\n",dequeue());
          goto start;
    case 3:printf("%d\n",isempty());
          goto start;
    case 4:printf("%d\n",isfull());
           goto start;
    case 5:traverse();
          goto start;
    case 6:printf("you are exited");
   }
    return 0;  
}

int isempty(){
    if(front==-1 && rear==-1 ){
        return 1;
    }
    return 0; 
}

int isfull(){
    if(front==(rear+1)%MAX){
        return 1;
    }
    return 0;
}

void enqueue(){
    int k;
    printf("enter the value,you want to be enqueued:");
    scanf("%d",&k);

     if(front==(rear+1)%MAX){
        printf("queue overflow\n");
    }
    else  if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=k;
    }

    else{
        rear=(rear+1)%MAX;
    queue[rear]=k;
    }
}

int dequeue(){
        int temp;
     if(front==-1 && rear==-1){
        printf("queue underflow\n");
    }
    else if(front==rear){
        temp=queue[front];
        front=-1;
        rear=-1;
    }

    else{
        temp=queue[front];
    front=(front+1)%MAX;
    return temp;
    }
    
}

void traverse(){
    if(front==-1 && rear==-1 ){
        printf("queue is empty\n");
        return;
    }
    int i=front;
    while(i!=rear){
        printf("%d ",queue[i]);
        i=(i+1)%MAX;
    }
    printf("%d",queue[rear]);
   printf("\n");
}