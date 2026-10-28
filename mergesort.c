#include <stdio.h>

// In place mergesort

#define maxN 10
int aux[maxN];

void merge(int* A, int l, int m, int r){

    int i, j, k;
    // lefts to aux  ------
    for (i = m+1; i > l; i--){
        aux[i-1] = A[i-1];
    }
    // rights reversed  (r + m -j) -> j + 1 ++++
    for (j = m; j < r; j++){
        aux[r + m - j] = A[j+1];
    }

    // [j] < [i]
    for (k = l; k <= r; k++){

        if (aux[j] < aux[i])
            A[k] = aux[j--];
        else 
            A[k] = aux[i++];

    }


}
void mergesort(int* A, int l, int r){
    int m = (l+r)/2;
    if (l >= r) return;
    mergesort(A, l, m);
    mergesort(A, m+1, r);
    merge(A, l, m, r);
}
int main(void){

    int A[10] = {8, 8, 9, 81, 53, 5, 4, 3, 6, 4};
    mergesort(A, 0, 9);
    for (int i = 0; i < 10; i++) printf("%d\n", A[i]);
    return 0;
}