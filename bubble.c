#include <stdio.h>


// Bubble Sort
int swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubble(int* A, int n){
    int swaps = 0;
    for (int i = 0; i < n; i++){

        for (int j = 1; j < n; j++){
            if (A[j-1] > A[j]){
                swap(&A[j-1], &A[j]);
                swaps = 1;
            }
        }

        if (swaps == 0)
            break;
        else
            swaps = 0;
    }
}

int main(void){

    int A[10] = {8, 8, 9, 81, 53, 5, 4, 3, 6, 4};
    bubble(A, 10);
    for (int i = 0; i < 10; i++) printf("%d\n", A[i]);

}