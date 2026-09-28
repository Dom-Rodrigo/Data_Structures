#include <stdio.h>

typedef struct stack {
    int top;
    int a[10];
} TPStack;

int push(TPStack* s, int m){
    s->top++;
    s->a[s->top] = m;
    return 0;
}

int pop(TPStack* s){
    if (s->top == -1)
        return -1;
    else {
        s->top--;
        return s->a[s->top+1];
    }
}
int fat(TPStack* s, int n){
    L1: 
        if(n < 0){
            push(s, -1); goto L2;
        }
        if (n <= 1){
            push(s, 1); goto L2;
        }
        push(s, n);
        n--;
        goto L1;
    L2:
        int m1, n1;
        m1 = pop(s); n1 = pop(s);
        if (s->top >= 0 && n >=1){
            push(s, n1*m1); 
            printf("%d\n", n1*m1);
            goto L2;
        }
        return(n1*m1);
}
int main(void){

    TPStack pilha;
    pilha.top = -1;
    fat(&pilha, 8);

}