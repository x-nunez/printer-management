#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_queue.h"
#include "adt_list.h"
#include "printers.h"

int main(int argc, char const *argv[]) {
    if(argc != 2) {
        printf("Missing argument\n");
        exit(1);
    }

    LIST printers_data;
    CreateList(&printers_data);
    LoadPrinters(argv[1], &printers_data);
    DisplayPrinters(printers_data);

    char menu, name[50];
    int aux;
    do {
        printf("\n\n------------------\n");
        printf("Main menu\n");
        printf("------------------\n");
        printf("Choose an option:\n");
        printf("  a) Delete printer\n");
        printf("  b) Add printer\n");
        printf("  c) Submit job\n");
        printf("  d) Show print queue\n");
        printf("  e) Print job\n");
        printf("  f) Find low-load printer(s)\n");
        printf("  i) Show printer list\n");
        printf("  x) Exit\n");
        printf("------------------\n");
        scanf(" %c", &menu);
        switch (menu) {
            case 'a':
                DisplayPrinters(printers_data);
                printf("Enter the name of a printer:\n");
                scanf("%s",name);
                if (RemovePrinter(&printers_data, name)) {
                    printf("\nPrinter successfully removed\n");
                    DisplayPrinters(printers_data);
                }
                else {
                    printf("\nError: a printer with that name does not exist\n");
                    DisplayPrinters(printers_data);
                }
                break;
            case 'b':
                if (AddPrinter(&printers_data)) {
                    printf("\nPrinter added successfully\n");
                    DisplayPrinters(printers_data);
                }
                else {
                    printf("\nError: a printer with that name already exists\n");
                    DisplayPrinters(printers_data);
                }
                break;
            case 'c':
                DisplayPrinters(printers_data);
                printf("Enter the name of the printer to send the job to:\n");
                scanf("%s", name);
                if (SendJob(name, &printers_data))
                    printf("\nSuccessfully added work\n");
                else
                    printf("\nError: a printer with that name does not exist\n");
                break;
            case 'd':
                DisplayPrinters(printers_data);
                printf("Enter the name of the printer to query the print queue:\n");
                scanf("%s", name);
                ShowPrintQueue(name, printers_data);
                break;
            case 'e':
                DisplayPrinters(printers_data);
                printf("Enter the name of the printer where to print:\n");
                scanf("%s", name);
                aux = PrintJob(name, &printers_data);
                if (aux == 1)
                    ShowPrintQueue(name, printers_data);
                else if (aux == -1){
                    printf("\nError: no jobs queued for printing\n");
                } else {
                    printf("\nError: a printer with that name does not exist\n");
                }
                break;
            case 'f':
                ShowLowestWorkload(printers_data);
                break;
            case 'i':
                DisplayPrinters(printers_data);
                break;
            case 'x':
                printf("\nLeaving\n");
                SavePrinters(argv[1], printers_data);
                printf("\nSaved data\n");
                DeletePrinters(&printers_data);
                break;
            default:
                printf("\nInvalid option\n");
                break;
        }
    } while (menu != 'x');
    return 0;
}