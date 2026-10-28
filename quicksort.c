#include <stdio.h>


// Quick Sort
int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *A, int p, int r){
    int x = A[r]; // pivot
    int i = p - 1;

    for (int j = p; j < r; j++){

        if (A[j] < x){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[r], &A[i+1]);
    return i + 1;

}

int quicksort(int *A, int p, int r){

    int q;
    if (p < r){

        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
    return 0;
}

int main(void){
    int A[10] = {8, 8, 9, 81, 53, 5, 4, 3, 6, 4};
    quicksort(A, 0, 9);
    for (int i = 0; i < 10; i++) printf("%d\n", A[i]);
    return 0;
}