#include <stdlib.h>
#include "adt_queue.h"

/*Definition of the type of element stored in the list*/
typedef struct ELM_LIST{
    char name[50];
    char brand[50];
    char model[50];
    char location[50];
    QUEUE print_spooler;
} ELM_LIST;
/*Structure for each node in the list*/
typedef struct listnode {
    ELM_LIST element;
    struct listnode *next;
} STNODELIST;
typedef STNODELIST *LIST_POSITION;
/*List structure*/
typedef struct {
    LIST_POSITION start;
    int length;
    LIST_POSITION end;
} STLIST;
typedef STLIST *LIST;

void CreateList(LIST *l) {
    *l = (LIST) malloc(sizeof(LIST));
    (*l)->start = (LIST_POSITION) malloc(sizeof(STNODELIST));
    (*l)->start->next = NULL;
    (*l)->end = (*l)->start;
    (*l)->length = 0;
}

void DestroyList(LIST *l) {
    (*l)->end = (*l)->start;
    while ((*l)->end != NULL) {
        (*l)->end = (*l)->end->next;
        free((*l)->start);
        (*l)->start = (*l)->end;
    }
    free(*l);
}

int IsListEmpty(LIST l) {
    return (l->length == 0);
}

LIST_POSITION FirstList(LIST l) {
    return l->start;
}

LIST_POSITION EndList(LIST l) {
    return l->end;
}

LIST_POSITION NextList(LIST l, LIST_POSITION p) {
    return p->next;
}

void RetrieveElemList(LIST l, LIST_POSITION p, ELM_LIST *e) {
    *e = p->next->element;
}

int LengthList(LIST l) {
    return l->length;
}

void InsertElemList(LIST *l, LIST_POSITION p, ELM_LIST e) {
    LIST_POSITION q = p->next;
    p->next = (STNODELIST *) malloc(sizeof(STNODELIST));
    p->next->element = e;
    p->next->next = q;
    if (q == NULL) {
        (*l)->end = p->next;
    }
    (*l)->length++;
}

void DeleteElemList(LIST *l, LIST_POSITION p) {
    LIST_POSITION q = p->next;
    p->next = q->next;
    if (p->next == NULL) {
        (*l)->end = p;
    }
    free(q);
    (*l)->length--;
}

void ModifyElemList(LIST *l, LIST_POSITION p, ELM_LIST e) {
    p->next->element = e;
}