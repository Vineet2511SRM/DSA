// Matrix Multiplication in C
#include<stdio.h>
int main(){
    int a[2][2], b[2][2], result[2][2];
    int m,n,p,q;

    printf("Enter the number of rows and columns for first matrix (m n): ");
    scanf("%d %d", &m, &n);

    printf("Enter the number of rows and columns for second matrix (p q): ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    printf("Enter elements of first matrix (%dx%d):\n", m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix (%dx%d):\n", p, q);
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix multiplication
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < q; j++) {
            result[i][j] = 0; // Initialize result matrix element
            for(int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Resultant matrix (%dx%d):\n", m, q);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}