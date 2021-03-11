#EXEC     = $(shell basename $$(pwd))
EXEC     = test
CC       = g++

#CFLAGS   = -std=gnu11 -O3 -Wall -Wextra -Wpedantic -Wstrict-aliasing
#CFLAGS  += $(shell pkg-config --cflags glib-2.0 gio-2.0)
#LDFLAGS  = $(shell pkg-config --libs   glib-2.0 gio-2.0)
CFLAGS   = 
CFLAGS  += 
LDFLAGS  = 

SRC      = $(wildcard *.c)
OBJ      = $(SRC:.c=.o)

all: $(EXEC)


buba: 
	- echo $(SRC)
	- echo %.o

${EXEC}: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
