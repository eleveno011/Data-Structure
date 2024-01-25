#include<stdio.h>
#define MAX 5

int dequeue[MAX];
int rear=-1;
int front=-1;

void enqueuefront();
void enqueuerear();
int dequeuefront();
int dequeuerear();
void traverse();

int main(){
    printf("MENU\n 1.enqueue at front\n 2.enqueue at rear\n 3.dequeue at front\n 4.dequeue at rear\n 5.traverse\n 6.exit\n");
    int option;
    start:printf("enter option:");
    scanf("%d",&option);
    
    switch(option){
        case 1:enqueuefront();
               goto start;
               break;
        case 2:enqueuerear();
               goto start;
               break;
        case 3:printf("element dequeued at front is:%d\n",dequeuefront());
              goto start;
              break;
        case 4:printf("element dequeued at rear is:%d\n",dequeuerear());
              goto start;
              break;
        case 5:traverse();
               goto start;
               break;
        case 6:printf("you are exited");

    }

}

void enqueuefront(){
    int x;
    printf("value to be enqueued at front:");
    scanf("%d",&x);

    if(front==(rear+1)%MAX){
        printf("queueoverflow\n");
    }
    else if(front==-1 && rear==-1){
        rear=0;
        front=0;
        dequeue[front]=x;
    }
    else if(front==0){
         front=MAX-1;
         dequeue[front]=x;
    }
    else{
        front--;
        dequeue[front]=x;
    }   
}

void enqueuerear(){
    int x;
    printf("value to be enqueued at rear:");
    scanf("%d",&x);
    
    if(front==(rear+1)%MAX){
        printf("queueoverflow\n");
    }
    else if(front==-1 && rear==-1){
        rear=0;
        front=0;
        dequeue[rear]=x;
    }
    else if(rear==MAX-1){
           rear=0;
           dequeue[rear]=x;
    }
    else{
        rear++;
        dequeue[rear]=x;
    }
}

int dequeuefront(){
    int temp;
    if(front==-1 && rear==-1){
        printf("dequeue is empty\n");
    }
    else if(rear==front){
        temp=dequeue[front];
        rear=-1;
        front=-1;
        return temp;
    }
    else if(front==MAX-1){
        temp=dequeue[front];
        front=0;
        return temp;
    }
    else{
        temp=dequeue[front];
        front++;
        return temp;
    }
}

int dequeuerear(){
    int temp;
    if(front==-1 && rear==-1){
        printf("dequeue is empty\n");
    }
    else if(rear==front){
        temp=dequeue[rear];
        rear=-1;
        front=-1;
        return temp;
    }
    else if(rear==0){
        temp=dequeue[rear];
        rear=MAX-1;
        return temp;
    }
     else{
        temp=dequeue[rear];
        rear--;
        return temp;
    }
}


void traverse(){
     if(front==-1 && rear==-1){
        printf("dequeue is empty\n");
        return;
    }
    int i=front;
    while(i!=rear){
        printf("%d ",dequeue[i]);
        i=(i+1)%MAX;
    }
    printf("%d",dequeue[rear]);
    printf("\n");
}


