#include<stdio.h>
#include<stdlib.h>

struct queue{
    int value;
    struct queue *next;
};

struct queue *front=NULL;
struct queue *rear=NULL;


void isempty();
void enqueue();
int dequeue();
void traverse();


int main(){
      printf("MENU\n 1.enqueue\n 2.dequeue\n 3.is empty\n  4.traverse\n 5.exit\n");
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
    case 4:traverse();
          goto start;
    case 5:printf("you are exited");
   }
    return 0;   

}

void isempty(){
    if(front==NULL){
        printf("queue is empty\n");
        return;
    }
    printf("queue is not empty\n");
}

void enqueue(){
    int k;
    printf("enter the value,you want to be enqueued:");
    scanf("%d",&k);

    struct queue *new;
    new=(struct queue*)malloc(sizeof(struct queue));
     if(new==NULL){
        printf("memory is not allocated\n");
        exit(-1);
    }
   
    new->value=k;
    new->next=NULL;
    if(rear==NULL||front==NULL){
        front=rear=new;
    }
    else{
        rear->next=new;
        rear=new;
    }
}

int dequeue(){
    int x;
    struct queue *temp;
     if(front==NULL){
        printf("queue underflow\n");
        return 0;
    }
    temp=front;
    x=front->value;
    front=front->next;
    free(temp);
    return x;
    
}

void traverse(){
    if(front==NULL){
        printf("queue is empty\n");
        
    }
    struct queue *i;
     for(i=front;i!=NULL;i=i->next){
        printf("%d ",i->value);
     }
     printf("\n");
}

