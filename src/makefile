IDIR = ../include
CC = gcc
CFLAGS = -Wall -I$(IDIR) -g

ODIR = obj
LDIR =../lib

LIBS = -lm

_DEPS = indices.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = indices.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

projeto: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

