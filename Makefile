CC=gcc
CFLAGS=-c -Wall -Wextra -Wchkp -Wpedantic -Wlogical-op -Werror -std=c11
SOURCES=customer.c product.c result.c shop.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.c.o: $(CC) $(CFLAGS) $< -o $@
