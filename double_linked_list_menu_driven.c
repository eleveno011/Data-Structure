#include<stdio.h>
#include<stdlib.h>

struct dll{
    struct dll *pre;
    int data;
    struct dll *next;
};

void create(struct dll *node);
void create1(struct dll *node1);
void traverse(struct dll *node);
void traverse1(struct dll *node2);
int count(struct dll *node);
void insert_before_given_position(struct dll *node);
void insert_at_beginning(struct dll **node);
void insert_at_end(struct dll *node);
void insert_after_any_position(struct dll *node);
void insert_at_any_position(struct dll *node);
void delete_at_beginning(struct dll **node);
void delete_at_end(struct dll *node);
void delete_after_any_position(struct dll *node);
void delete_at_any_position(struct dll *node);
void reverse_list(struct dll **node);
void append_linked_lists(struct dll *node,struct dll *node1);
void sort(struct dll *node);
int search_node(struct dll *node);

int main(){
    struct dll *node;
    node=(struct dll*)malloc(sizeof(struct dll));
    if(node==NULL){
        printf("memory is not allocated.list is not created");
        exit(0);
    }

    struct dll *node1;
    node=(struct dll*)malloc(sizeof(struct dll));
    if(node1==NULL){
        printf("memory is not allocated.list is not created");
        exit(0);
    }

    struct dll *node2;
    node=(struct dll*)malloc(sizeof(struct dll));
    if(node1==NULL){
        printf("memory is not allocated.list is not created");
        exit(0);
    }

    int option;
    printf("MENU\n 1.create list\n 2.traverse list\n 3.no. of nodes\n 4.insert before given position\n 5.insert at beginning\n 6.insert at end\n 7.insert after any position\n 8.insert at any position\n 9.delete at beginning\n 10.delete at end\n 11.delete after any position\n 12.delete at any position\n 13.reverse list\n 14.append list\n 15.sort linked list\n 16.search linked list\n  17.Exit\n" );
   start: printf("Enter option:");
    scanf("%d",&option);

    switch(option){
        case 1:create(node);
               break;
        case 2:create(node);
               traverse(node);
               break;
        case 3:create(node);
               printf("no. of nodes=%d",count(node));
               break;
        case 4:create(node);
               insert_before_given_position(node);
               traverse(node);
               break;
        case 5:create(node);
               insert_at_beginning(&node);
               traverse(node);
               break;
        case 6:create(node);
               insert_at_end(node);
               traverse(node);
               break;
        case 7:create(node);
               insert_after_any_position(node);
               traverse(node);
               break;
        case 8:create(node);
               insert_at_any_position(node);
               traverse(node);
               break;
        case 9:create(node);
               delete_at_beginning(&node);
               traverse(node);
               break;
        case 10:create(node);
               delete_at_end(node);
               traverse(node);
               break;
        case 11:create(node);
                delete_after_any_position(node);
                traverse(node);
                break;
        case 12:create(node);
                delete_at_any_position(node);
                traverse(node);
                break;
        case 13:create(node);
                reverse_list(&node);
                traverse(node);
                break;
        case 14:create(node);
                create1(node1);
                append_linked_lists(node,node1);
                traverse(node);
                break;
        case 15:create(node);
                sort(node);
                traverse(node);
                break;
        case 16:create(node);
                printf("element present at the node:%d",search_node(node));
                break;
        case 17:printf("you are exited");
                break;
        default: printf("you should only enter the option present in the given MENU to do stuff related to linked list\n");
            goto start;
    }
   
    return 0;
}

void create(struct dll *node){
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
        node->next=(struct dll*)malloc(sizeof(struct dll));
        if(node->next==NULL){
           printf("memory is not allocated.");
           printf("next node can not be created");
           exit(0);
        }
        struct dll *newnode=node;
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
}

void create1(struct dll *node1){
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
        node1->next=(struct dll*)malloc(sizeof(struct dll));
        if(node1->next==NULL){
           printf("memory is not allocated.");
           printf("next node can not be created");
           exit(0);
        }
        struct dll *newnode=node1;
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
}

void traverse(struct dll *node){
     printf("linked list:");
     while(node!=NULL){
        printf("%d\t",node->data);
        node=node->next;
     }
}

void traverse1(struct dll *node2){
    if(node2==NULL){
        printf("linked list is empty");
        return;
    }
    printf("Linked List:");
    while(node2!=NULL){
        printf("%d\t",node2->data);
        node2=node2->next;
    }
}

int count(struct dll *node){
    int count=0;
    while(node!=NULL){
        count++;
        node=node->next;
    }
    return count;
}

void insert_before_given_position(struct dll *node){
      struct dll *newnode;
    newnode=(struct dll*)malloc(sizeof(struct dll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
    } 
    int c,i=1; 
    c=count(node);
    int pos;
    start:
    printf("Enter the position before which you want to insert:");
     scanf("%d",&pos);
     if(pos<=1 || pos>=c+1){
         if(pos==1){
            printf("you are trying to insert at beginning.so,please choose the option 5.insert at beginning\n");
            exit(0);
        }
        printf("Enter position between 1 and %d\n",c+1);
        goto start;
     }
    
    printf("Enter data of new node:");
    scanf("%d",&newnode->data);
    newnode->pre=NULL;
    newnode->next=NULL;
    while(node!=NULL){
        if((pos-1)==i){
           newnode->pre=node;
           newnode->next=node->next;
           node->next->pre=newnode;
           node->next=newnode;
         return;
        }
        node=node->next;
        i++;
    }
}

void insert_at_beginning(struct dll **node){
     struct dll *newnode;
    newnode=(struct dll*)malloc(sizeof(struct dll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
    } 
    printf("enter data to be inserted at the beginning:");
    scanf("%d",&newnode->data);
    newnode->pre=NULL;
     newnode->next=NULL;
     //if linked list is empty
    if(node==NULL){
        *node=newnode;
        return;
    }
    (*node)->pre=newnode;
    newnode->next=*node;
    *node=newnode;
}

void insert_at_end(struct dll *node){
    struct dll *newnode;
    newnode=(struct dll*)malloc(sizeof(struct dll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
    } 
     printf("enter data of newnode:");
    scanf("%d",&newnode->data);
    newnode->pre=NULL;
    newnode->next=NULL;
      //if linked list is empty
     if(node==NULL){
        node=newnode;
        return;
    }
    //else we traverse to the last 
     while(node->next!=NULL){
        node=node->next;
     }
     newnode->pre=node;
     node->next=newnode;     
}

void insert_after_any_position(struct dll *node){
      struct dll *newnode;
    newnode=(struct dll*)malloc(sizeof(struct dll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
    } 
    int c,i=1; 
    c=count(node);
    int pos;
    start:
    printf("Enter the position after which you want to insert:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c){
         if(pos==c){
            printf("you are trying to insert at end.so,please choose the option 6.insert at end\n");
            exit(0);
        printf("Enter position between 1 and %d\n",c);
        goto start;
     }
      printf("Enter data of new node:");
    scanf("%d",&newnode->data);
    newnode->pre=NULL;
    newnode->next=NULL;
    while(node!=NULL){
        if(pos==i){
        newnode->pre=node;
        newnode->next=node->next;
        node->next->pre=newnode;
        node->next=newnode;
         return;
        }
        node=node->next;
        i++;
    } 
  }
}

void insert_at_any_position(struct dll *node){
     struct dll *newnode;
    newnode=(struct dll*)malloc(sizeof(struct dll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
    } 
    int c,i=1; 
    c=count(node);
    int pos;
    start:
    printf("Enter the position at which you want to insert:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c+1){
        printf("Enter position between 0 and %d\n",c+1);
        goto start;
     }
      printf("Enter data of new node:");
    scanf("%d",&newnode->data);
    newnode->pre=NULL;
    newnode->next=NULL;
    while(node!=NULL){
        if(pos==i){
       node->data=newnode->data;
         return;
        }
        node=node->next;
        i++;
    } 
}

void delete_at_beginning(struct dll **node){
      struct dll *newnode;
     newnode=(struct dll*)malloc(sizeof(struct dll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     newnode->next=NULL;
     newnode->next=*node;
     *node=(*node)->next;
     free(newnode);
}

void delete_at_end(struct dll *node){
      struct dll *pre_node;

     while(node->next!=NULL){
        pre_node=node;
        node=node->next;   
     }
          free(node);
     pre_node->next=NULL;   
}

void delete_after_any_position(struct dll *node){
      int c,i=1;
   
    struct dll *newnode;
     newnode=(struct dll*)malloc(sizeof(struct dll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node);
    int pos;
    start:
    printf("Enter the position after which you want to delete:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c+1){
        printf("Enter position between 0 and %d\n",c);
        goto start;
     }
        
        while(node!=NULL){
            if(i==pos){
               newnode->next=node->next;
               node->next=NULL;
               free(newnode);
                return;
            }
            node=node->next;
            i++;
         }
}

void delete_at_any_position(struct dll *node){
     int c;
    c=count(node);
    int pos;
    start:
    printf("Enter the position at which you want to delete:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c+1){
        printf("Enter position between 0 and %d\n",c);
        goto start;
     }

    while(pos>2){
          
        node=node->next;
         pos--;
      }
    node->next=node->next->next;  
}

void reverse_list(struct dll **node){
    struct dll *current=*node;
     struct dll *next=NULL;
      struct dll *prev=NULL;
     
     while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
     }
     *node=prev;    
}

void append_linked_lists(struct dll *node,struct dll *node1){
    //if first list is empty
    if(node==NULL){
        node=node1;
    }
    //traversing to the last of first linked list
     while(node->next!=NULL){
        node=node->next;
     }
     //appending two linked list
     node->next=node1;
}

void sort(struct dll *node) {

        struct dll *i,*j;
        
        for( i=node;i!=NULL;i=i->next){
           for ( j =i->next; j!=NULL; j=j->next) {
               if (i->data >j->data) {
                   // Swap the data values of the current and nextNode
                   int temp = i->data;
                   i->data = j->data;
                   j->data = temp;
            }              
        }
    }
}

int search_node(struct dll *node){
    int x,i=1;
    printf("Enter data to be searched in node:");
    scanf("%d",&x);

    while(node!=NULL){
        if(x==node->data){
           return i;
        }
        node=node->next;
        i++;
    }
    return -1;
}
