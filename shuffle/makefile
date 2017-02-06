CC=clang++
CFLAGS=-std=c++11 -pedantic-errors

SRCDIR=src
ODIR=obj

_OBJ=shuffle.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

EXECUTABLE=shuffle

$(ODIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o	\
	rm -f $(EXECUTABLE)
