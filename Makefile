CC=gcc
CFLAGS= -std=c99
DFLAGS=-lm
SDIR=./src
BDIR=./bin
INCLUDES = -I$(SDIR)

tube: $(BDIR)/main.o $(BDIR)/lex.o $(BDIR)/utils.o $(BDIR)/tube.o
	$(CC) -o $@ $^ $(DFLAGS);

$(BDIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^ $(DFLAGS)

clean:
	rm ./tube; rm $(BDIR)/*.o
