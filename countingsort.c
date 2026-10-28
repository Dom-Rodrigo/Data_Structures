#include <stdio.h>

// Counting Sort
int countingsort(int* A, int*B, int k, int n){
    int C[k+1];

    // clears C

    for (int i = 0; i < k + 1; i++){
        C[i] = 0;
    }
    // histogram

    for (int j = 0; j < n; j++){
        C[A[j]] = C[A[j]] + 1;
    }
    // prefixsum
    for (int i = 1; i < k  + 1; i++){
        C[i] = C[i] + C[i-1];
    }
    // transverse from the right
    for (int j = n - 1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

}

int main(void){
    int A[10] = {8, 8, 9, 81, 53, 5, 4, 3, 6, 4};
    int B[10];
    countingsort(A, B, 81, 10);
    for (int i = 0; i < 10; i++) printf("%d\n", B[i]);
}