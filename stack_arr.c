#include <stdio.h>
#include <stdlib.h>

#define STACK_LIMIT 100

typedef struct {
    int values[STACK_LIMIT];
    int top;
} TStack;

// Returns true if the stack is empty
bool empty(TStack* s){
    if (s->top == -1)
        return true;
    return false;
}
// Pushes a value onto the stack
int push(TStack* s, int value){
    if (s->top == STACK_LIMIT-1)
        return EXIT_FAILURE;
    else{
        s->values[++(s->top)] = value;
    }
    return EXIT_SUCCESS;
}

// Returns the last pushed value
int pop(TStack* s){
    if (empty(s))
        return EXIT_FAILURE;
    else{
        return s->values[(s->top)--];
    }
    return EXIT_SUCCESS;
}

int print_stack(TStack* s){
    if (empty(s)){
        return EXIT_FAILURE;
    }
    else{
        for (int i = s->top; i > -1; --i){
            printf("%d\t", s->values[i]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}


int main(void){

    TStack* s = malloc(sizeof(TStack));
    s->top = -1;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    pop(s);
    print_stack(s);
    return EXIT_SUCCESS;
}