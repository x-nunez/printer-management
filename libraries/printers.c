#include "printers.h"

void LoadPrinters(char file_name[], LIST *list) {
    FILE *file;
    file = fopen(file_name, "r");
    if (file  == NULL) {
        printf("File opening error");
        exit (2);
    }

    ELM_LIST element;
    LIST_POSITION position = FirstList(*list);
    while (fscanf(file, "%s ", element.name) != EOF) {
        fscanf(file, "%s ", element.brand);
        fscanf(file, "%s ", element.model);
        fscanf(file, "%s\n", element.location);
        CreateQueue(&element.print_spooler);
        InsertElemList(list, position, element);
        position = NextList(*list, position);
    }
    fclose(file);
}

void DisplayPrinters(LIST printers) {
    printf("\nAVAILABLE PRINTERS:\n\n");
    ELM_LIST element;
    LIST_POSITION position;

    if (!IsListEmpty(printers)) {
        position = FirstList(printers);
        for (int i = 0; i < LengthList(printers); i++) {
            RetrieveElemList(printers, position, &element);
            printf("  %s %s %s %s\n", element.name, element.brand, element.model, element.location);
            position = NextList(printers, position);
        }
    }
}

int RemovePrinter(LIST *printers, char printer_name[]) {
    int exists_printer;
    ELM_LIST element;
    LIST_POSITION position = SearchPrinter(*printers, printer_name, &exists_printer);

    if (exists_printer) {
        RetrieveElemList(*printers, position, &element);
        DestroyQueue(&element.print_spooler);
        DeleteElemList(printers, position);
        return 1;
    }
    else
        return 0;
}

LIST_POSITION SearchPrinter(LIST printers, char printer_name[], int *exist_printer) {
    ELM_LIST element;
    LIST_POSITION position;
    int i;
    *exist_printer = 0;

    if(IsListEmpty(printers))
        return position;

    position = FirstList(printers);
    for (i = 0; i < LengthList(printers); i++) {
        RetrieveElemList(printers, position, &element);
        if (strcmp(element.name, printer_name) == 0) {
            *exist_printer = 1;
            return position;
        }
        position = NextList(printers, position);
    }
    return position;
}

void DeletePrinters(LIST *printers) {
    ELM_LIST element;
    LIST_POSITION position;
    int i;

    if (!IsListEmpty(*printers)) {
        position = FirstList(*printers);
        for (i = 0; i < LengthList(*printers); i++) {
            RetrieveElemList(*printers, position, &element);
            DestroyQueue(&element.print_spooler);
            position = NextList(*printers, position);
        }
    }

    DestroyList(printers);
}

int AddPrinter(LIST *printers) {
    ELM_LIST printer;
    int exist_printer;
    printf("Enter the new printer data in the following format:\n");
    printf("NAME BRAND MODEL LOCATION\n");

    scanf("%s %s %s %s", printer.name, printer.brand, printer.model, printer.location);
    CreateQueue(&printer.print_spooler);

    SearchPrinter(*printers, printer.name, &exist_printer);
    LIST_POSITION end = EndList(*printers);
    if (!exist_printer) {
        InsertElemList(printers, end, printer);
        return 1;
    }
    else
        return 0;
}

void SavePrinters(char file_name[], LIST list) {
    FILE *file;
    file = fopen(file_name, "w");
    if (file  == NULL) {
        printf("File opening error");
        exit (2);
    }

    ELM_LIST element;
    LIST_POSITION position = FirstList(list);
    for (int i = 0 ; i < LengthList(list); i++) {
        RetrieveElemList(list, position, &element);
        fprintf(file, "%s ", element.name);
        fprintf(file, "%s ", element.brand);
        fprintf(file, "%s ", element.model);
        fprintf(file, "%s", element.location);
        position = NextList(list, position);
        if (i < (LengthList(list) - 1))
            fprintf(file, "\n");
    }
    fclose(file);
}

int RetrieveQueue(char printer_name[], LIST printers, QUEUE *queue) {
    int exist_printer = 1;
    LIST_POSITION position = SearchPrinter(printers, printer_name, &exist_printer);
    ELM_LIST element;

    if (exist_printer) {
        RetrieveElemList(printers, position, &element);
        *queue = element.print_spooler;
    }
   return exist_printer;
}

int SendJob(char printer_name[], LIST *printers) {
    QUEUE queue;
    ELM_QUEUE job;

    if(RetrieveQueue(printer_name, *printers, &queue)) {
        printf("Enter the job ID:\n");
        scanf(" %d", &job);
        AddElementQueue(&queue, job);
        return 1;
    }
    return 0;
}

void ShowPrintQueue(char printer_name[], LIST printers) {
    QUEUE queue;
    ELM_QUEUE job;
    int length;

    if(RetrieveQueue(printer_name, printers, &queue)) {
        if(!IsQueueEmpty(queue)) {
            printf("\n%s print queue:\n", printer_name);
            length = LengthQueue(queue);
            for (int i = 0; i < length; i++) {
                ExtractFirstElementQueue(queue, &job);
                printf("\n%d", job);
                DestroyFirstElementQueue(&queue);
                AddElementQueue(&queue, job);
            }
        }
        else
            printf("\nEmpty queue\n");
    }
    else
        printf("\nError: A printer with that name does not exist\n");
}

int PrintJob(char printer_name[], LIST *printers) {
    QUEUE queue;
    ELM_QUEUE job;

    if(RetrieveQueue(printer_name, *printers, &queue)) {
        if (IsQueueEmpty(queue))
            return -1;
        ExtractFirstElementQueue(queue, &job);
        DestroyFirstElementQueue(&queue);
        printf("\nJob %d has been printed\n", job);
        return 1;
    }
    return 0;
}

void ShowLowestWorkload(LIST printers) {
    ELM_LIST printer;
    LIST_POSITION position = FirstList(printers);
    int aux, lesser_tail_len, lesser_tail_rept = 1, list_len = LengthList(printers);

    RetrieveElemList(printers, position, &printer);
    lesser_tail_len = LengthQueue(printer.print_spooler);
    position = NextList(printers, position);

    for (int i = 1; i < list_len; i++) {
        RetrieveElemList(printers, position, &printer);
        aux = LengthQueue(printer.print_spooler);
        if (aux < lesser_tail_len) {
            lesser_tail_len = aux;
            lesser_tail_rept = 1;
        } else if (aux == lesser_tail_len)
            lesser_tail_rept++;
        position = NextList(printers, position);
    }

    if (lesser_tail_rept > 1)
        printf("\nThe minor load is %d pending jobs and has been found on the following %d printers:\n", lesser_tail_len, lesser_tail_rept);
    else
        printf("\nThe minor load is %d pending jobs and has been found on the following printer:\n", lesser_tail_len);

    position = FirstList(printers);
    for (int i = 0; i < list_len; i++) {
        RetrieveElemList(printers, position, &printer);
        aux = LengthQueue(printer.print_spooler);
        if (aux == lesser_tail_len)
            printf("%s\n",printer.name);
        position = NextList(printers, position);
    }
}