#include <stdio.h>

int main() {
    int n;
    printf("Enter the no. of row in sparse matrix:");
    scanf("%d", &n);
    int mat[n][3];

    printf("Enter sparse matrix in 3-tuple format\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int a = mat[0][0];
    int b = mat[0][1];
    int mat1[a][b];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            mat1[i][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        int k = mat[i][0];
        int l = mat[i][1];
        mat1[k][l] = mat[i][2];
    }

    int mat2[n][3];
    printf("Enter another sparse matrix in 3-tuple format\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    int c = mat2[0][0];
    int d = mat2[0][1];
    int mat3[c][d];

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            mat3[i][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        int e = mat2[i][0];
        int f = mat2[i][1];
        mat3[e][f] = mat2[i][2];
    }

    int mat4[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            mat4[i][j] = mat1[i][j] + mat3[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (mat4[i][j] != 0) {
                count++;
            }
        }
    }

    int mat5[count + 1][3];
    mat5[0][0] = a;
    mat5[0][1] = b;
    mat5[0][2] = count;

    int m = 1;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (mat4[i][j] != 0) {
                mat5[m][0] = i;
                mat5[m][1] = j;
                mat5[m][2] = mat4[i][j];
                m++;
            }
        }
    }

    printf("Resultant sparse matrix:\n");

    for (int i = 0; i < count + 1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat5[i][j]);
        }
        printf("\n");
    }

    return 0;
}