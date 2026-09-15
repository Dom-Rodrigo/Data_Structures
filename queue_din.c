#include <stdio.h>
#include <stdlib.h>

typedef struct TQueue {
    int value;
    struct TQueue *next;
} TQueue;

bool empty(TQueue* q){
    if (q == NULL)
        return true;
    return false;
}
TQueue* queue(TQueue* q, int value){

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

int print_queue(TQueue* q){
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

int main(void){

    TQueue* q = malloc(sizeof(TQueue));
    q = NULL;
    q = queue(q, 40);
    q = queue(q, 50);
    q = queue(q, 15);
    q = queue(q, 30);
    q = queue(q, 11);
    dequeue(&q);
    dequeue(&q);
    print_queue(q);
    return EXIT_SUCCESS;
}