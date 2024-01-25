#include<stdio.h>
int main(){
    int n,a,b,k,l,count=0,m=1;
    printf("Enter no. of row in sparse matrix");
    scanf("%d",&n);
    int mat[n][3];
    printf("Enter sparse matrix in 3-tuple format" );
    for(int i=0;i<n;i++){
       for(int j=0;j<3;j++){
        scanf("%d",&mat[i][j]);
       }
    }
    
      a=mat[0][0];
      b=mat[0][1];


    int mat1[a][b];
          
       for(int i=0;i<a;i++){
         for(int j=0;j<b;j++){
           mat1[i][j]=0;
       }
    }     
   
   for(int i=1;i<n;i++){
      k=mat[i][0];
      l=mat[i][1];
      mat1[k][l]=mat[i][2]; 
   }
   

   int mat2[b][a];
      for(int i=0;i<b;i++){
         for(int j=0;j<a;j++){
             mat2[i][j]=mat1[j][i];
       }
       
    }
   
    for(int i=0;i<b;i++){
         for(int j=0;j<a;j++){
            if(mat2[i][j]!=0){
               count++;
            }
       }
    }

   int mat3[count+1][3];
       mat3[0][0]=b;
       mat3[0][1]=a;
       mat3[0][2]=count;

   for(int i=0;i<b;i++){
         for(int j=0;j<a;j++){
             if(mat2[i][j]!=0){
                mat3[m][0]=i;
                mat3[m][1]=j;
                mat3[m][2]=mat2[i][j];
             
             m++;
             }
       }
   }
  printf("Transpose of sparse matrix:\n");
  
  for(int i=0;i<count+1;i++){
     for(int j=0;j<3;j++){
      printf("%d ",mat3[i][j]);
     }
     printf("\n");
  }

return 0;
    
}


