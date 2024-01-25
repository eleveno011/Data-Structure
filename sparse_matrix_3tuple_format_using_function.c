#include<stdio.h>
void convert_to_3_tuple_format(int mat[][5],int m,int n,int count,int mat1[][3]){
		
	mat1[0][0]=m;
      mat1[0][1]=n;
      mat1[0][2]=count;	
	 
	int k=1,i,j;   
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]!=0){
				mat1[k][0]=i;
				mat1[k][1]=j;
				mat1[k][2]=mat[i][j];
				k++;
               
			}
		}
	  }
    
}




void print_3_tuple_sparse_matrix(int mat1[][3],int row_of_mat1){
	    	int a,b;
		for( a=0;a<row_of_mat1;a++){
		for( b=0;b<3;b++){
			printf("%d ",mat1[a][b]);
		}
		printf("\n");
	}
}

		

int main(){
	int m,n,count=0;
	printf("enter size sparse matrix:");
	scanf("%d",&m);
	scanf("%d",&n);
	int mat[m][n];
	
	int i,j;
 
	
	printf("elements of sparse matrix:");
	for( i=0;i<m;i++){
		for( j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0){
				count++;
			}
		}
	}
    
	
    int mat1[count+1][3];
    	convert_to_3_tuple_format(mat, m, n,count,mat1);
        int row_of_mat1=count+1;
         
    
    
	
		
		print_3_tuple_sparse_matrix(mat1,row_of_mat1 );
		
    return 0;

}
