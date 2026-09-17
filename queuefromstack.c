#include <stdio.h>
#include <stdlib.h>


typedef struct TStack {
    int value;
    struct TStack *next;
} TStack;

typedef struct  {
    struct TStack* main;
    struct TStack* aux;
} TQueuefromStack;


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
int printstack(TStack* s){
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

TQueuefromStack* enqueue(TQueuefromStack* s, int value){
    s->main = push(s->main, value);
    return s;
}

int pop_aux(TQueuefromStack* s){
    while (s->main != NULL){
        s->aux = push(s->aux, pop(&s->main));
    }
    return pop(&s->aux);
}

int dequeue(TQueuefromStack* ds){
    int v = pop_aux(ds);
    while (ds->aux != NULL){
        ds->main = push(ds->main, pop(&ds->aux));
    }
    return v;
}

int main(void){

    TQueuefromStack* q = malloc(sizeof(TQueuefromStack));
    q = enqueue(q, 10);
    q = enqueue(q, 20);
    q = enqueue(q, 30);
    q = enqueue(q, 40);    
    q = enqueue(q, 50);

    printstack(q->main);
    

    int popped = dequeue(q);
    printf("%d\n", popped);

    printstack(q->main);


    EXIT_SUCCESS;
}
