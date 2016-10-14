#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m,k;
    int *A,*B,*C,*arr;
    int i,temp1,temp2;


    scanf("%d %d %d",&n,&m,&k);
    
    A = (int*)malloc(sizeof(int) * k);
    B = (int*)malloc(sizeof(int) * k);
    C = (int*)malloc(sizeof(int) * (m+1));
    arr = (int*)malloc(sizeof(int) * n);


    for (i = 0; i < m ; i++) {
        C[i] = 0;
    }

    for (i = 0; i < k; i++) {
    scanf("%d %d", &A[i], &B[i]); 
    
    /*
    scanf("%d %d", &temp1, &temp2);
    A[i] = temp1;
    B[i] = temp2;
    */

    }

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        C[arr[i]] += 1;
    }

    for (i = 1; i < m; i++) {
        C[i] = C[i] + C[i-1];
    }

    for (i = 0; i < k; i++) {
        printf("%d\n", C[B[i]] - C[A[i]-1]);
    }

    free(A);
    free(B);
    free(C);
    free(arr);

    return 0;

}

