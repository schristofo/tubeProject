CC=gcc
DFLAGS=
SDIR=./src
BDIR=./bin
IDIR=./inc
INCLUDES = -I$(IDIR)

$(BDIR)/tube: $(SDIR)/main.c $(SDIR)/lex.o $(IDIR)/lex.h
	$(CC) -o $@ $^ $(DFLAGS)

$(SDIR)/lex.o: $(SDIR)/lex.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	rm $(BDIR)/tube; rm $(SDIR)/lex.o
