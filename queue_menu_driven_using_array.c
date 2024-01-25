#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=0;
int rear=-1;

void isempty();
void isfull();
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

void isempty(){
    if(rear<front){
        printf("queue is empty\n");
        return;
    }
    
    printf("queue is not empty\n");  
}

void isfull(){
    if(rear==MAX-1){
        printf("queue is full\n");
        return;
    }
    printf("queue is not full\n");
}

void enqueue(){
    int k;
    printf("enter the value,you want to be enqueued:");
    scanf("%d",&k);

     if(rear==MAX-1){
        printf("queue is full\n");
        return;
    }

    rear++;
    queue[rear]=k;
}

int dequeue(){
     if(rear<front){
        printf("queue is empty\n");
        return 0;
    }
    
    int temp;
    temp=queue[front];
    front++;
    return temp;
}

void traverse(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}