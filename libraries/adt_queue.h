#ifndef ADT_QUEUE_H
#define ADT_QUEUE_H

/*Defining the type of element stored in the queue*/
typedef int ELM_QUEUE;
/*Queue structure*/
typedef void *QUEUE;

/**
 * Reserve memory for a data queue with type [ELM_QUEUE].
 *
 * @param q pointer to the queue to create.
 */
void CreateQueue(QUEUE *q);

/**
 * Destroys (frees reserved memory) the queue [q] and all the elements it stores.
 *
 * @param q pointer to the queue to destroy.
 */
void DestroyQueue(QUEUE *q);

/**
 * Checks if queue [q] is empty.
 *
 * @param q queue to check if it is empty.
 * @return 1 if the queue is empty, 0 if not.
 */
int IsQueueEmpty(QUEUE q);

/**
 * Extract the first element of the queue [q], if any, and stores it in [e], without removing it from the queue.
 *
 * @param q queue from which to extract the first element.
 * @param e pointer to the variable where to store the first element of the queue.
 */
void ExtractFirstElementQueue(QUEUE q, ELM_QUEUE *e);

/**
 * Destroys (frees reserved memory) of the first element in the queue.
 *
 * @param q pointer to the queue from which to destroy the first element.
 */
void DestroyFirstElementQueue(QUEUE *q);

/**
 * Adds element [e] to queue [q].
 *
 * @param q queue pointer to which to add the element.
 * @param e element to add.
 */
void AddElementQueue(QUEUE *q, ELM_QUEUE e);

/**
 * Query the length of the queue [q].
 *
 * @param q queue to query the length of.
 * @return integer with the value of the length of the queue.
 */
int LengthQueue(QUEUE q);

#endif