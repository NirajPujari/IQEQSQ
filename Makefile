CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Iinclude
SRCDIR = src
OBJ = $(SRCDIR)/main.o $(SRCDIR)/iq.o $(SRCDIR)/eq.o $(SRCDIR)/sq.o

all: IQEQSQ

IQEQSQ: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(SRCDIR)/*.o IQEQSQ
