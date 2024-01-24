#include<stdio.h>
int main(){
	int m,n;
	printf("Enter size sparse matrix:");
	scanf("%d",&m);
	scanf("%d",&n);
	int mat[m][n];
	
	
	printf("Enter elements of sparse matrix:");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	int count=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]!=0){
				count++;
			}
		}
	}
	printf("non zero elments: %d",count);
	printf("\n");
	int mat1[count+1][3];
	    mat1[0][0]=m;
		mat1[0][1]=n;
		mat1[0][2]=count;
		int k=1;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
			       if(mat[i][j]!=0){
				      mat1[k][0]=i;
				      mat1[k][1]=j;
				      mat1[k][2]=mat[i][j];
					  k++;
			}
		}
	  
			
	}
	printf("sparse matrix in 3 tuple format:\n");
	for(int i=0;i<count+1;i++){
		for(int j=0;j<3;j++){
			printf("%d ",mat1[i][j]);
		}
		printf("\n");
	}
    return 0;

}