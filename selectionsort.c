#include <stdio.h>

// Selection Sort
int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int selectionsort(int* A, int n){
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (A[i] > A[j]){
                swap(&A[i], &A[j]);
            }
        }
    }
}
int main(void){
    int A[10] = {8, 8, 9, 81, 53, 5, 4, 3, 6, 4};
    selectionsort(A, 10);
    for (int i = 0; i < 10; i++) printf("%d\n", A[i]);
}