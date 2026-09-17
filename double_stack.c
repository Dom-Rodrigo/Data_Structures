#include <stdio.h>
#include <stdlib.h>


typedef struct TStack {
    int value;
    struct TStack *next;
} TStack;

typedef struct  {
    struct TStack* first;
    struct TStack* second;
} TDoubleStack;


// Allocates memory for another stack structure and links it to the last or NULL
TStack* push(TStack* s, int value){
    TStack* new = (TStack*)malloc(sizeof(TStack));
    new->value = value;

     // stack is empty
    if (s == NULL){
        new->next = NULL;
    }
    else{
        new->next = s;
    }
    return new;

}

// Pops a value of the stack
int pop(TStack** s){

    if (s == NULL || *s == NULL){
        return -1;
    }
    else{
        TStack* t = *s;
        int value = t->value;
        *s = t->next;
        free(t);
        return value;
    }
}

// Print the stack values
int print_stack(TStack* s){
    if (s == NULL){
        return EXIT_FAILURE;
    }
    else{
        TStack* temp = s;
        while (temp != NULL){
            printf("%d\t", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }

    return EXIT_SUCCESS;

}

TDoubleStack* push_d(TDoubleStack* s, int value){
    s->first = push(s->first, value);
    return s;
}

int pop_first(TDoubleStack* s){
    while (s->first != NULL){
        s->second = push(s->second, pop(&s->first));
    }
    return pop(&s->second);
}


int main(void){

    TDoubleStack* dstack = malloc(sizeof(TDoubleStack));
    dstack = push_d(dstack, 10);
    dstack = push_d(dstack, 20);
    dstack = push_d(dstack, 30);
    dstack = push_d(dstack, 40);    
    dstack = push_d(dstack, 50);

    print_stack(dstack->first);
    

    int popped = pop_first(dstack);
    printf("%d\n", popped);


    EXIT_SUCCESS;
}
