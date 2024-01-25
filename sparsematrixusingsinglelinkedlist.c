#include<stdio.h>
#include<stdlib.h>
struct sparse3tuple{
    int row;
    int column;
    int data;
    struct sparse3tuple *next;
};

void create(struct sparse3tuple *node,int **arr,int m,int n,int count);

int main(){
    int m,n;
    printf("enter size of sparse matrix:");
    scanf("%d %d",&m,&n);
   
    
    int **arr;
    arr=(int **)malloc(m*sizeof(int *));

    for(int i=0;i<m;i++){
        arr[i]=(int *)malloc(n*sizeof(int));
    }
    
    printf("enter elements of sparse matrix:");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    struct sparse3tuple *node;
    node=(struct sparse3tuple *)malloc(sizeof(struct sparse3tuple));

    if(node==NULL){
        printf("memory is not allocated");
        exit(-1);
    }

    int count=0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    
   create(node,arr,m,n,count);

    printf("sparse matrix in 3 tuple format\n");
    while(node!=NULL){
        printf("%d ",node->row);
        printf("%d ",node->column);
        printf("%d\n",node->data);
        node=node->next;
    }

    return 0;
}

void create(struct sparse3tuple *node,int **arr,int m,int n,int count){
      node->row=m;
    node->column=n;
    node->data=count;
    node->next=NULL;
    node->next=(struct sparse3tuple *)malloc(sizeof(struct sparse3tuple));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
           if(arr[i][j]!=0){
             node->next=(struct sparse3tuple *)malloc(sizeof(struct sparse3tuple));  
              node=node->next;
              node->row=i;
              node->column=j;
              node->data=arr[i][j];
               node->next=NULL;
           }
    }
}