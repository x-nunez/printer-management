#include <stdlib.h>
#include <stdio.h>

/*Defining the type of element stored in the queue*/
typedef int ELM_QUEUE;
/*Structure for each node in the queue*/
typedef struct queuenode {
    ELM_QUEUE data;
    struct queuenode *next;
} STNODEQUEUE;
/*Queue structure*/
typedef struct {
    STNODEQUEUE *first;
    STNODEQUEUE *last;
} STQUEUE;
typedef STQUEUE *QUEUE;

void CreateQueue(QUEUE *q) {
    *q = (QUEUE) malloc(sizeof(STQUEUE));
    (*q)->first = NULL;
    (*q)->last = NULL;
}

int IsQueueEmpty(QUEUE q) {
    return (q->last == NULL) && (q->first == NULL);
}

void ExtractFirstElementQueue(QUEUE q, ELM_QUEUE *e) {
    if (IsQueueEmpty(q)) {
        printf("\nERROR, queue has no elements\n");
    }
    else {
        *e = (q->first)->data;
    }
}

void DestroyFirstElementQueue(QUEUE *q) {
    STNODEQUEUE *aux;

    if (IsQueueEmpty(*q)) {
        printf("\nERROR, queue has no elements\n");
    }
    else {
        aux = (*q)->first;
        (*q)->first = aux->next;
        if ((*q)->first == NULL) {
            (*q)->last = NULL;
        }
        free(aux);
    }
}

void DestroyQueue(QUEUE *q) {
    while (!IsQueueEmpty(*q)) {
        DestroyFirstElementQueue(q);
    }
    free(*q);
}

void AddElementQueue(QUEUE *q, ELM_QUEUE e) {
    STNODEQUEUE *aux;

    aux = (STNODEQUEUE *) malloc(sizeof(STNODEQUEUE));
    aux->data = e;
    aux->next = NULL;

    if (IsQueueEmpty(*q)) {
        (*q)->first = aux;
    }
    else {
        (*q)->last->next = aux;
    }
    (*q)->last = aux;
}

int LengthQueue(QUEUE q) {
    int length = 0;
    STNODEQUEUE *aux;
    aux = q->first;

    while (aux) {
        aux = aux->next;
        length++;
    }

    return length;
}