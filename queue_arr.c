#include <stdio.h>
#include <stdlib.h>

#define QUEUE_LIMIT 100


typedef struct {
    int values[QUEUE_LIMIT];
    int tail;
    int head;
} TQueue;

bool empty(TQueue* q){
    if (q->tail == q->head-1)
        return true;
    return false;
}
int queue(TQueue* q, int value){

    if (q->tail == QUEUE_LIMIT-1){
        return EXIT_FAILURE;
    }
    q->values[++(q->tail)] = value;
    return EXIT_SUCCESS;
}

int dequeue(TQueue* q){
    if (empty(q)){
        return EXIT_FAILURE;
    }
    return q->values[(q->head)++];
}

int print_queue(TQueue* q){
    for (int i = q->head; i <= q->tail; i++){
        printf("%d ", q->values[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

int main(void){

    TQueue* q = malloc(sizeof(TQueue));
    q->tail = -1; // Empty queue
    q->head = 0;
    queue(q, 20);
    queue(q, 30);
    queue(q, 40);
    dequeue(q);
    dequeue(q);
    queue(q, 20);
    queue(q, 30);
    queue(q, 40);
    queue(q, 20);
    queue(q, 30);
    queue(q, 40);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    print_queue(q);
    return EXIT_SUCCESS;
}