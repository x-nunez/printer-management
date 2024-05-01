#ifndef ADT_LIST_H
#define ADT_LIST_H

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
/*Structure for a list position*/
typedef void *LIST_POSITION;
/*Structure for the list*/
typedef void *LIST;

/**
 * Reserve memory for a data list with type [ELM_LIST].
 *
 * @param l pointer to the list to create.
 */
void CreateList(LIST *l);

/**
 * Destroys (frees reserved memory) the list [l] and all the elements it stores.
 *
 * @param l pointer to the list to destroy.
 */
void DestroyList(LIST *l);

/**
 * Checks if list [l] is empty.
 *
 * @param l list to check if it is empty.
 * @return 1 if the list is empty, 0 if not.
 */
int IsListEmpty(LIST l);

/**
 * Recover the first position in the list.
 *
 * @param l list from which to recover the first position.
 * @return the first position type [LIST_POSITION] of the list [l].
 */
LIST_POSITION FirstList(LIST l);

/**
 * Recovers the position of the end of the list.
 *
 * @param l list from which to recover its ending.
 * @return the position of the end type [LIST_POSITION] of the list [l].
 */
LIST_POSITION EndList(LIST l);

/**
 * Returns the position next to [p] in list [l].
 *
 * @param l list in which to search for the next position.
 * @param p reference position to return the next.
 * @return the position following [p].
 */
LIST_POSITION NextList(LIST l, LIST_POSITION p);

/**
 * Retrieves the element stored at position [p].
 *
 * @param l list from which to retrieve the element.
 * @param p position from which to retrieve the element.
 * @param e pointer to the variable in which to store the retrieved element.
 */
void RetrieveElemList(LIST l, LIST_POSITION p, ELM_LIST *e);

/**
 * Query the length of the list [l].
 *
 * @param l list to query the length of.
 * @return integer with the value of the length of the list.
 */
int LengthList(LIST l);

/**
 * Inserts element [e] in the position following position [p] of the list [l].
 *
 * @param l pointer to the list into which the element is to be inserted.
 * @param p position after which the element will be inserted.
 * @param e element to insert.
 */
void InsertElemList(LIST *l, LIST_POSITION p, ELM_LIST e);

/**
 * Deletes the element at position [p] from list [l].
 *
 * @param l pointer to the list from which the element will be deleted.
 * @param p position of the element to be deleted.
 */
void DeleteElemList(LIST *l, LIST_POSITION p);

/**
 * Modifies the value of the element stored at position [p] by saving the new element [e].
 *
 * @param l pointer to the list from which the element is to be modified.
 * @param p position of the value to be modified.
 * @param e new value to save in position [p].
 */
void ModifyElemList(LIST *l, LIST_POSITION p, ELM_LIST e);

#endif