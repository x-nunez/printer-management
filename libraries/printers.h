#ifndef PRINTERS_H
#define PRINTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_queue.h"
#include "adt_list.h"

/**
 * Loads printer names from a file into a list.
 *
 * @param file_name file name.
 * @param list pointer to the list where you want to save the read printers.
 */
void LoadPrinters(char file_name[], LIST *list);

/**
 * Displays the printer names in the list.
 *
 * @param printers list with the printers to display.
 */
void DisplayPrinters(LIST printers);

/**
 * Removes a printer from the list given the name.
 *
 * @param printers List pointer from which you want to remove the printer.
 * @param printer_name name of the printer to delete.
 * @return 1 if the printer has been removed, 0 otherwise.
 */
int RemovePrinter(LIST *printers, char printer_name[]);

/**
 * Search for a printer in the list given the name.
 *
 * @param printers list where you want to search for the printer.
 * @param printer_name name of the printer to search for.
 * @param exist_printer pointer to an integer that will be 1 if the printer exists, 0 otherwise.
 * @return the position of the printer in the list if it exists, an empty position otherwise.
 */
LIST_POSITION SearchPrinter(LIST printers, char printer_name[], int *exist_printer);

/**
 * Delete the list of printers with the queues they contain.
 *
 * @param printers pointer to the list to delete.
 */
void DeletePrinters(LIST *printers);

/**
 * Add a printer to the list.
 *
 * @param printers list pointer in which the printer is added.
 * @return 1 if the printer has been added, 0 otherwise.
 */
int AddPrinter(LIST *printers);

/**
 * Saves printer names from a list in a file.
 *
 * @param file_name name of the file where you want to save the data.
 * @param list list with printers.
 */
void SavePrinters(char file_name[], LIST list);

/**
 * Retrieves a list item queue given the printer name.
 *
 * @param printer_name name of the printer from which to obtain the print queue.
 * @param printers list with printers.
 * @param queue pointer to the queue to assign to the printer.
 * @return 1 if the printer exists, 0 in another case.
 */
int RetrieveQueue(char printer_name[], LIST printers, QUEUE *queue);

/**
 * Add a job to the indicated printer.
 *
 * @param printer_name name of the printer from which to obtain the print queue.
 * @param printers pointer to the list with printers.
 * @return 1 if the printer exists, 0 in another case.
 */
int SendJob(char printer_name[], LIST *printers);

/**
 * Shows the print queue for a printer.
 *
 * @param printer_name name of the printer from which to obtain the print queue.
 * @param printers list with printers.
 */
void ShowPrintQueue(char printer_name[], LIST printers);

/**
 * Prints a job from the indicated printer.
 *
 * @param printer_name name of the printer from which to obtain the print queue.
 * @param printers pointer to the list with printers.
 * @return 1 if the printer exists, -1 if the queue is empty, 0 otherwise.
 */
int PrintJob(char printer_name[], LIST *printers);

/**
 * Prints the printer or printers with the lowest workload.
 *
 * @param printers list with printers.
 */
void ShowLowestWorkload(LIST printers);

#endif