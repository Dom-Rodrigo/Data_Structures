#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* prox;
} Node;

typedef struct {
    Node* first;
    Node* last;
} DoublyLinkedList;

Node* init_node(int value){
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->prev = NULL;
    node->prox = NULL;
    return node;
}
DoublyLinkedList* init_dllist(){
    DoublyLinkedList* dblist = malloc(sizeof(DoublyLinkedList));
    dblist->first = NULL;
    dblist->last = NULL;
    return dblist;
}


DoublyLinkedList* insertatf(int value, DoublyLinkedList* d){

    Node* node = init_node(value);
    // Empty doubly linked list
    if (d->first == NULL){
        d->first = node;
        d->last = node;
    }
    else{
        Node* temp = d->first;
        node->prox = temp;
        temp->prev = node;
        d->first = node;
    }
    return d;
}

// DoublyLinkedList* insertatl(int value, DoublyLinkedList* d){

// }

int deleteatp(Node* p, DoublyLinkedList* d){
    Node* temp = p;

    if (temp == d->first)
        d->first = temp->prox;
    if (temp == d->last)
        d->last = temp->prev;
    Node* b = temp->prev;
    Node* a = temp->prox;
    b->prox = a;
    a->prev = b;

    free(temp);
    return EXIT_SUCCESS;

}

Node* search(int value, DoublyLinkedList* d){

    Node* temp = d->first;

    // Search from first to last
    while (temp != NULL && temp->value != value){
        temp = temp->prox;
    }
    return temp;
}

int p_first2last(DoublyLinkedList* d){

    Node* temp = d->first;
    printf("(first->last) dll[]\t\t");
    while(temp != NULL){
        printf("%d\t", temp->value);
        temp = temp->prox;
    }
    printf("\n");
    return EXIT_SUCCESS;
}
int main(void){

    DoublyLinkedList* dllist = init_dllist();
    dllist = insertatf(10, dllist);    dllist = insertatf(20, dllist);
    dllist = insertatf(20, dllist); dllist = insertatf(50, dllist); dllist = insertatf(10, dllist); 
    deleteatp(search(50, dllist), dllist);
    p_first2last(dllist);
    return EXIT_SUCCESS;
}