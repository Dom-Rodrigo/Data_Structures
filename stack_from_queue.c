#include <stdio.h>
#include <stdlib.h>

typedef struct TQueue {
    int value;
    struct TQueue *next;
} TQueue;

typedef struct {
    struct TQueue* main;
    struct TQueue* aux;
} TStackfromQueue;

bool empty(TQueue* q){
    if (q == NULL)
        return true;
    return false;
}
TQueue* enqueue(TQueue* q, int value){

    TQueue* new = malloc(sizeof(TQueue));
    new->value = value;
    if (empty(q)){
        new->next = NULL;
        return new;
    }
    else{
        TQueue* temp = q;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        return q;
    }
}

int dequeue(TQueue** q){
    if (q == NULL || *q == NULL){
        return -1;
    }
    else{
        TQueue* temp = *q;
        int value = temp->value;
        *q = temp->next;
        free(temp);
        return value;
    }
}

int printqueue(TQueue* q){
    if (empty(q)){
        return EXIT_FAILURE;
    }
    else {
        TQueue* temp = q;

        while (temp != NULL){
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
        return EXIT_SUCCESS;
    }

}

TStackfromQueue* push(TStackfromQueue* q, int value){
    q->main = enqueue(q->main, value);
    return q;
}
int pop_aux(TStackfromQueue* q){
    while (q->main != NULL){
        q->aux = enqueue(q->aux, dequeue(&q->main));
    }
    return dequeue(&q->aux);
}

int pop(TStackfromQueue* q){
    int temp = pop_aux(q);
    while (q->aux != NULL){
        q->main = enqueue(q->main, dequeue(&q->aux));
    }
    return temp;
}

int main(void){

    TStackfromQueue* q = malloc(sizeof(TStackfromQueue));
    q = push(q, 40);
    q = push(q, 50);
    q = push(q, 15);
    q = push(q, 30);
    q = push(q, 11);
    printqueue(q->main);

    pop(q);

    printqueue(q->main);

    return EXIT_SUCCESS;
}