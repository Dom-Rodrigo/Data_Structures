#include <stdio.h>
#include <stdlib.h>


typedef struct TStack {
    int value;
    struct TStack *next;
} TStack;


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

int main(void){

    TStack* s = malloc(sizeof(TStack));
    s = NULL;
    s = push(s, 10);
    s = push(s, 20);
    s = push(s, 30);
    s = push(s, 30);
    s = push(s, 30);
    s = push(s, 40);
    int popped = pop(&s);
    printf("Value popped is %d\n", popped);
    // printf("%d\n", (s->next)->value);
    print_stack(s);
    return EXIT_SUCCESS;
}