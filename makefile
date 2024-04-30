OUTPUT = main
HEADER_FILES_DIR = ./libraries
LIB_HEADERS = $(HEADER_FILES_DIR)/adt_list.h $(HEADER_FILES_DIR)/adt_queue.h $(HEADER_FILES_DIR)/printers.h

INCLUDES = -I $(HEADER_FILES_DIR)
SRCS = main.c $(LIB_HEADERS:.h=.c)
OBJS = $(SRCS:.c=.o)

$(OUTPUT): $(OBJS)
	gcc -Wall -o $(OUTPUT) $(OBJS) $(LIBS)

%.o: %.c $(LIB_HEADERS)
	gcc -Wall -c -o $@ $< $(INCLUDES)

cleanall: clean
	rm -f $(OUTPUT)

clean:
	rm -f *.o $(HEADER_FILES_DIR)/*.o *~

exe: $(OUTPUT)
	./$(OUTPUT) printers