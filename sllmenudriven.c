#include<stdio.h>
#include<stdlib.h>

struct sll{
    int data;
    struct sll *next;
};

void create(struct sll *node);
void create1(struct sll *node);
void traverse(struct sll *node);
void traverse1(struct sll *node2);
void insert_at_beginning(struct sll **node);
int count(struct sll *node);
void insert_at_end(struct sll *node);
int search_node(struct sll *node);
void insert_after_any_position(struct sll *node);
void insert_at_any_position(struct sll *node);
void delete_at_beginning(struct sll **node);
void delete_at_end(struct sll *node);
void delete_after_any_position(struct sll *node);
void delete_at_any_position(struct sll *node);
void reverse_list(struct sll **node);
void append_linked_lists(struct sll *node,struct sll *node1);
void merge(struct sll *node,struct sll *node1,struct sll *node2);
void sort(struct sll *node);
void insert_before_any_position(struct sll *node);

int main(){
    struct sll *node;
    node=(struct sll*)malloc(sizeof(struct sll));
    
    if(node==NULL){
        printf("memory is not allocated.");
        printf("list cannot be created");
        exit(0);
    }

     struct sll *node1;
    node1=(struct sll*)malloc(sizeof(struct sll));
    
    if(node1==NULL){
        printf("memory is not allocated.");
        printf("list cannot be created");
        exit(0);
    }

    struct sll *node2;
    node2=(struct sll*)malloc(sizeof(struct sll));
    
    if(node2==NULL){
        printf("memory is not allocated.");
        printf("list cannot be created");
        exit(0);
    }

      printf("MENU\n 1.create list\n 2.traverse list\n 3.insert at beginning\n 4.To know no. of nodes\n 5.insert at end\n 6.search node\n 7.insert after any position\n 8.insert at any position\n 9.delete at beggining\n 10.delete at end\n 11.delete after any position\n 12.delete at any position\n 13.reverse list\n14.append linked lists\n 15.sorting of linked list\n 16.merge into one list\n 17.insert before any element\n 18.Exit\n");

    int option;
    start: printf("Enter option:");
    scanf("%d",&option);

    switch(option){
    case 1: create(node);
            break; 
    case 2:create(node);
           traverse(node);
           break;
    case 3:create(node);
           insert_at_beginning(&node);
           traverse(node);
           break;
    case 4:create(node);
          printf("No of nodes: %d",count(node));
          break;
    case 5:create(node);
           insert_at_end(node);
           traverse(node);
           break;
    case 6:create(node);
           printf("Data present at node: %d",search_node(node));
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
            create(node1);
            merge(node,node1,node2);
            traverse1(node2);
            break;
    case 17:create(node);
            insert_before_any_position(node);
            traverse(node);
            break;
    case 18: printf("you are exited");
             break;
    default:printf("you should only enter the option present in the given MENU  to do stuff related to linked list\n");
            goto start;
    }
    return 0;
}

void create(struct sll *node){
    char ch='y';
    int i=1;
    //taking data of first node
    printf("Enter data of node %d:",i);
    scanf("%d",&node->data);
    i++;
    node->next=NULL;
     printf("would you like to continue to give data of another node? (y for yes/n for no):");
    getchar();
    ch=getchar();
    if(ch !='y' && ch != 'n'){
        printf("enter (y for yes/n for no):");
        getchar();
        ch=getchar();
    }
    while(ch!='n'){
         node->next=(struct sll*)malloc(sizeof(struct sll));
    if(node->next==NULL){
        printf("memory is not allocated.");
        printf("next node can not be created");
        exit(0);
    }
     node=node->next;
    printf("Enter data of node %d:",i);
    scanf("%d",&node->data);
    i++;
    node->next=NULL;
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

void create1(struct sll *node1){
    char ch='y';
    int i=1;
    printf("second linked list:\n");
    printf("Enter data of node %d:",i);
    scanf("%d",&node1->data);
    i++;
    node1->next=NULL;
     printf("would you like to continue? (y for yes/n for no):");
    getchar();
    ch=getchar();
    if(ch !='y' && ch != 'n'){
        printf("enter (y for yes/n for no):");
        getchar();
        ch=getchar();
    }
    while(ch!='n'){
         node1->next=(struct sll*)malloc(sizeof(struct sll));
    if(node1->next==NULL){
        printf("memory is not allocated.");
        printf("next node can not be created");
        exit(0);
    }
     node1=node1->next;
    printf("Enter data of node %d :",i);
    scanf("%d",&node1->data);
    i++;
    node1->next=NULL;
    printf("would you like to continue? (y for yes/n for no):");
    getchar();
    ch=getchar();
    if(ch !='y' && ch != 'n'){
        printf("enter (y for yes/n for no):");
        getchar();
        ch=getchar();
    }
  }
}

void traverse(struct sll *node){
    if(node==NULL){
        printf("linked list is empty");
        exit(0);
    }
    printf("Linked List:");
    while(node!=NULL){
        printf("%d\t",node->data);
        node=node->next;
    }
}

void traverse1(struct sll *node2){
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

void insert_at_beginning(struct sll **node){
    struct sll *newnode;
    newnode=(struct sll*)malloc(sizeof(struct sll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
    }  

    printf("Enter data of new node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    //if linked list is empty
    if(node==NULL){
        *node=newnode;
        return;
    }
    newnode->next=*node;
    *node=newnode;    

}
 
int count(struct sll *node){
    int count=0;
    while(node!=NULL){
        count++;
        node=node->next;
    }
    return count;
}

void insert_at_end(struct sll *node) {
    struct sll *newnode;
    newnode = (struct sll *)malloc(sizeof(struct sll));
    if (newnode == NULL) {
        printf("\nMemory is not allocated");
         printf("newnode cannot be created");
        exit(0);
    }
    printf("\nEnter the data of the new node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    //if linked list is empty
     if(node==NULL){
        node=newnode;
        return;
    }
    //else we traverse to the last 
    while (node->next!= NULL) {
        node = node->next;
    }
    node->next = newnode;
}

int search_node(struct sll *node){
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

void insert_after_any_position(struct sll *node){
     int c,i=1;
   
    struct sll *newnode;
     newnode=(struct sll*)malloc(sizeof(struct sll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node);
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
         while(node!=NULL){
            if(i==pos){
                newnode->next=node->next;
                node->next=newnode;
                break;
            }
            node=node->next;
            i++;
         }
}

void insert_at_any_position(struct sll *node){
     int c,i=1;
   
    struct sll *newnode;
     newnode=(struct sll*)malloc(sizeof(struct sll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node);
    int pos;
    start:
    printf("Enter the position after which you want to insert:");
     scanf("%d",&pos);
     if(pos<=0 || pos>=c+1){
        printf("Enter position between 0 and %d\n",c);
        goto start;
     }
    
         printf("Enter data to be inserted:");
         scanf("%d",&newnode->data);
         newnode->next=NULL;

          while(node!=NULL){
            if(i==pos){
                node->data=newnode->data;
                return;
            }
            node=node->next;
            i++;
         }
}

void delete_at_beginning(struct sll **node) {
    if (*node == NULL) {
        printf("The linked list is empty\n");
        return;
    }
    struct sll *newnode=*node;
    *node=(*node)->next;
    free(newnode);
    
}

void delete_at_end(struct sll *node){
    if(node==NULL){
        printf("list is empty");
        return;
    }
    if(node->next==NULL){
        struct sll *newnode=node;
        free(newnode);
        node=NULL;
        printf("only element present  in the list is deleted.NOW the list is empty");
    }
    while(node->next->next != NULL){
        node=node->next;
    }
     struct sll *newnode=node->next;
        free(newnode);
     node->next=NULL;

}

void delete_after_any_position(struct sll *node){
      int c,i=1;
   
    struct sll *newnode;
     newnode=(struct sll*)malloc(sizeof(struct sll));
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

void delete_at_any_position(struct sll *node){
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

void reverse_list(struct sll **node){
    struct sll *current=*node;
     struct sll *next=NULL;
      struct sll *prev=NULL;
     
     while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
     }
     *node=prev;    
}

void append_linked_lists(struct sll *node,struct sll *node1){
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

void merge(struct sll *node,struct sll *node1,struct sll *node2){
    struct sll *newnode;
    node2->data=node->data;
    node=node->next;
    node2->next=NULL;
  
    while(node!=NULL){
        newnode=(struct sll*)malloc(sizeof(struct sll));
        if(newnode==NULL){
           printf("memory is not allocated");
           printf("newnode cannot be created");
           exit(0);
         } 
         node2->next=newnode;
         node2=node2->next;     
         node2->data=node->data;
         node2->next=NULL; 
         node=node->next;     

    }
    while(node1!=NULL){
        newnode=(struct sll*)malloc(sizeof(struct sll));
        if(newnode==NULL){
           printf("memory is not allocated");
           printf("newnode cannot be created");
           exit(0);
         } 
         node2->next=newnode; 
         node2=node2->next;    
         node2->data=node1->data;
         node2->next=NULL;
         node1=node1->next; 
        
    }
}

void sort(struct sll *node) {

        struct sll *i,*j;
        
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

void insert_before_any_position(struct sll *node){
     int c,i=1;
   
    struct sll *newnode;
     newnode=(struct sll*)malloc(sizeof(struct sll));
     if(newnode==NULL){
        printf("memory is not allocated");
        printf("newnode cannot be created");
        exit(0);
     }
     
     c=count(node);
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
        
        struct sll *temp=node;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
     
}


