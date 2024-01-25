#include<stdio.h>
#include<stdlib.h>

struct cdll{
    struct cdll *pre;
    int data;
    struct cdll *next;
} ;

void create(struct cdll *node,struct cdll *head);
void create1(struct cdll *node1,struct cdll *head2);
void traverse(struct cdll *node,struct cdll *head);
int count(struct cdll *node,struct cdll *head);
void insert_before_any_position(struct cdll *node,struct cdll *head);
void insert_at_beginning(struct cdll **node, struct cdll **head,struct cdll **head1);
void insert_at_end(struct cdll *node,struct cdll *head);
void insert_after_any_position(struct cdll *node,struct cdll *head);
void insert_at_any_position(struct cdll *node,struct cdll *head);
void delete_at_beginning(struct cdll **node,struct cdll **head);
void delete_at_end(struct cdll *node,struct cdll *head);
void delete_after_any_position(struct cdll *node,struct cdll *head);
void delete_at_any_position(struct cdll *node,struct cdll *head);
void append_linked_lists(struct cdll *node,struct cdll *node1,struct cdll *head,struct cdll *head2);
void sort(struct cdll *node,struct cdll *head);
int search_node(struct cdll *node,struct cdll *head);

int main(){
    struct cdll *node;
    node=(struct cdll *)malloc(sizeof(struct cdll));
    if(node==NULL){
        printf("memory is not created.linked list is not created");
        exit(0);
    }

    struct cdll *head=node;
    struct cdll *head1=node;

    struct cdll *node1;
    node=(struct cdll *)malloc(sizeof(struct cdll));
    if(node==NULL){
        printf("memory is not created.linked list is not created");
        exit(0);
    }
    struct cdll *head2=node1;
    
    int option;
    printf("MENU\n 1.create list\n 2.traverse list\n 3.no. of nodes\n 4.insert before given position\n 5.insert at beginning\n 6.insert at end\n 7.insert after any position\n 8.insert at any position\n 9.delete at beginning\n 10.delete at end\n 11.delete after any position\n 12.delete at any position\n 13.append list\n 14.sort linked list\n 15.search linked list\n  16.Exit\n" );
    start:printf("enter option:");
    scanf("%d",&option);

    switch(option){
        case 1:create(node,head);
               break;
        case 2:create(node,head);
               traverse(node,head);
               break;
        case 3:create(node,head);
               printf("no. of nodes=%d",count(node,head));
               break;
        case 4:create(node,head);
               insert_before_any_position(node,head);
               traverse(node,head);
               break;
        case 5:create(node,head);
               insert_at_beginning(&node,&head,&head1);
               traverse(node,head);
               break;
        case 6:create(node,head);
               insert_at_end(node,head);
               traverse(node,head);
               break;
        case 7:create(node,head);
               insert_after_any_position(node,head);
               traverse(node,head);
               break;
        case 8:create(node,head);
               insert_at_any_position(node,head);
               traverse(node,head);
               break;
        case 9:create(node,head);
                delete_at_beginning(&node,&head);
                traverse(node,head);
                break;
        case 10:create(node,head);
                delete_at_end(node,head);
                traverse(node,head);
                break;
        case 11:create(node,head);
                delete_after_any_position(node,head);
                traverse(node,head);
                break;
        case 12:create(node,head);
                delete_at_any_position(node,head);
                traverse(node,head);
                break;
        case 13:create(node,head);
                create1(node1,head2);
                append_linked_lists(node,node1,head,head2);
                traverse(node,head);
                break; 
        case 14:create(node,head);
                sort(node,head);
                traverse(node,head);
                break;
        case 15:create(node,head);
               printf("element present at pos:%d",search_node(node,head));
               break;  
        case 16:printf("you are exited");
                break;
        default: 
               printf("you should only enter the option present in the given MENU to do stuff related to linked list\n");
            goto start;    
      }
    return 0;
}

void create(struct cdll *node,struct cdll *head){
    char ch='y';
    int i=1;
    node->pre=NULL;
    printf("enter data of node %d:",i);
    scanf("%d",&node->data);
    node->next=NULL;
    i++;
    printf("would you like to continue to give data of another node? (y for yes/n for no):");
    getchar();
    ch=getchar();
    if(ch !='y' && ch != 'n'){
        printf("enter (y for yes/n for no):");
        getchar();
        ch=getchar();
    }

    while(ch!='n'){
        node->next=(struct cdll*)malloc(sizeof(struct cdll));
        if(node->next==NULL){
           printf("memory is not allocated.");
           printf("next node can not be created");
           exit(0);
        }
        struct cdll *newnode=node;
        node=node->next; 
        node->pre=newnode;
        printf("enter data of node %d:",i);
        scanf("%d",&node->data);
         node->next=NULL;
         i++;
         printf("would you like to continue to give data of another node? (y for yes/n for no):");
         getchar();
         ch=getchar();
         if(ch !='y' && ch != 'n'){
        printf("enter (y for yes/n for no):");
        getchar();
        ch=getchar();

         }  
    }
    node->next=head;
}

void create1(struct cdll *node1,struct cdll *head2){
    char ch='y';
    int i=1;
    node1->pre=NULL;
    printf("second linked list:\n");
    printf("enter data of node %d:",i);
    scanf("%d",&node1->data);
    node1->next=NULL;
    i++;
    printf("would you like to continue to give data of another node? (y for yes/n for no):");
    getchar();
    ch=getchar();
    if(ch !='y' && ch != 'n'){
        printf("enter (y for yes/n for no):");
        getchar();
        ch=getchar();
    }

    while(ch!='n'){
        node1->next=(struct cdll*)malloc(sizeof(struct cdll));
        if(node1->next==NULL){
           printf("memory is not allocated.");
           printf("next node can not be created");
           exit(0);
        }
        struct cdll *newnode=node1;
        node1=node1->next; 
        node1->pre=newnode;
        printf("enter data of node %d:",i);
        scanf("%d",&node1->data);
         node1->next=NULL;
         i++;
         printf("would you like to continue to give data of another node? (y for yes/n for no):");
         getchar();
         ch=getchar();
         if(ch !='y' && ch != 'n'){
        printf("enter (y for yes/n for no):");
        getchar();
        ch=getchar();

         }  
    }
    node1->next=head2;
}

void traverse(struct cdll *node,struct cdll *head){
    if(node==NULL){
        printf("linked list is empty");
        return;
    }
    printf("linked list:");
    do {
        printf("%d\t",node->data);
        node=node->next;
    }
    while(node!=head);   
}

int count(struct cdll *node,struct cdll *head){
    int count=0;
    do{
        count++;
        node=node->next;
    }
    while(node!=head);
    return count;
}

void insert_before_any_position(struct cdll *node,struct cdll *head){
     int c,i=1;
   
    struct cdll *newnode;
     newnode=(struct cdll*)malloc(sizeof(struct cdll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node,head);
    int pos;
    start:
    printf("Enter the position before which you want to insert:");
     scanf("%d",&pos);
     if(pos<=1 || pos>=c+1){
        if(pos==1){
            printf("you are trying to insert at beginning.so,please choose the option 3.insert at beginning\n");
            exit(0);
        }
        printf("Enter position between 1 and %d\n",c+1);
        goto start;
     }
    
         printf("Enter data to be inserted:");
         scanf("%d",&newnode->data);
         newnode->next=NULL;
        
        struct cdll *temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
}

void insert_at_beginning(struct cdll **node, struct cdll **head,struct cdll **head1) {
    struct cdll *temp=*node;
    struct cdll *newnode;
    newnode = (struct cdll *)malloc(sizeof(struct cdll));
    if (newnode == NULL) {
        printf("Memory allocation failed. New node cannot be created.");
        exit(0);
    }
    printf("Enter data of newnode to be inserted at beginning:");
    scanf("%d", &newnode->data);
   
    newnode->next=NULL;
    newnode->next=*node;
    *node=newnode;
    *head=newnode;
     while(temp->next!=*head1){
        temp=temp->next;
    }
    temp->next=newnode;     
}

void insert_at_end(struct cdll *node,struct cdll *head){
     struct cdll *newnode;
    newnode = (struct cdll *)malloc(sizeof(struct cdll));
    if (newnode == NULL) {
        printf("Memory allocation failed. New node cannot be created.");
        exit(0);
    }
     printf("Enter data of newnode: ");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    while(node->next!=head){
        node=node->next;
    }
    newnode->next=node->next;// or newnode->next=head;
    node->next=newnode;
    /* or node->next=newnode;
          newnode->next=head; */
    
}

void insert_after_any_position(struct cdll *node,struct cdll *head){
     int c,i=1;
   
    struct cdll *newnode;
     newnode=(struct cdll*)malloc(sizeof(struct cdll));
     if(newnode==NULL){
        printf("memory is not allocated\n");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node,head);
    int pos;
    start:
    printf("Enter the position after which you want to insert:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c+1){
        printf("Enter position between 0 and %d\n",c+1);
        goto start;
     }
    
         printf("Enter data to be inserted:");
         scanf("%d",&newnode->data);
         newnode->next=NULL;
        
        struct cdll *temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;    
}

void insert_at_any_position(struct cdll *node,struct cdll *head){
     int c,i=1;
   
    struct cdll *newnode;
     newnode=(struct cdll*)malloc(sizeof(struct cdll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node,head);
    int pos;
    start:
    printf("Enter the position at which you want to insert:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c+1){
       
        printf("Enter position between 0 and %d\n",c+1);
        goto start;
     }
    
         printf("Enter data to be inserted:");
         scanf("%d",&newnode->data);
         newnode->next=NULL;
        
        struct cdll *temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->data=newnode->data;
}

void delete_at_beginning(struct cdll **node,struct cdll **head){
      struct cdll *newnode;
     newnode=(struct cdll*)malloc(sizeof(struct cdll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     newnode->next=NULL;
     newnode->next=*node;
     *node=(*node)->next;
     if(*node==*head){
        *node=NULL;
        return;
     }
     free(newnode);
}

void delete_at_end(struct cdll *node,struct cdll *head){
      struct cdll *pre_node;
     
     while(node->next!=head){
        pre_node=node;
        node=node->next;  
     }
          free(node);
     pre_node->next=head;  
}

void delete_after_any_position(struct cdll *node,struct cdll *head){
      int c,i=1;
   
    struct cdll *newnode;
     newnode=(struct cdll*)malloc(sizeof(struct cdll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node,head);
    int pos;
    start:
    printf("Enter the position after which you want to delete:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c+1){
        printf("Enter position between 0 and %d\n",c);
        goto start;
     }
        
        /*struct cdll *temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=head;
        free(newnode);*/
         while(node->next!=head){
            if(i==pos){
               newnode->next=node->next;
               node->next=head;
               free(newnode);
                return;
            }
            node=node->next;
            i++;
        }
}

void delete_at_any_position(struct cdll *node,struct cdll *head){
    int c;
    c=count(node,head);
    int pos;
    start:
    printf("Enter the position at which you want to delete:");
     scanf("%d",&pos);
     if(pos<=1 || pos>=c+1){
        if(pos==1){
            printf("you are trying to delete at beginning.so,please choose option 10.delete at beginning");
            exit(0);
        }
        printf("Enter position between 1 and %d\n",c+1);
        goto start;
     }
    while(pos>2){
        node=node->next;
        pos--;
      }
    node->next=node->next->next;     
} 

void append_linked_lists(struct cdll *node,struct cdll *node1,struct cdll *head,struct cdll *head2){
    //if first list is empty
    if(node==NULL){
        node=node1;
    }
    //traversing to the last of first linked list
     while(node->next!=head){
        node=node->next;
     }
     //appending two linked list
     node->next=node1;
      while(node1->next!=head2){
        node1=node1->next;
     }
     node1->next=head;
}

void sort(struct cdll *node,struct cdll *head) {

        struct cdll *i,*j;
        
        for( i=node;i->next!=head;i=i->next){
           for ( j =i->next; j!=head; j=j->next) {
               if (i->data >j->data) {
                   // Swap the data values of the current and nextNode
                   int temp = i->data;
                   i->data = j->data;
                   j->data = temp;
            }              
        }
    }
}

int search_node(struct cdll *node,struct cdll *head){
     int x,i=1;
    printf("Enter data to be searched in node:");
    scanf("%d",&x);

    do{
        if(x==node->data){
           return i;
        }
        node=node->next;
        i++;
    }
    while(node!=head);
    return -1;

}