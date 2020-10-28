CC=gcc
DFLAGS=-lm
SDIR=./src
ODIR=./obj
BDIR=./bin
IDIR=./inc
INCLUDES = -I$(IDIR)

$(BDIR)/tube: $(ODIR)/main.o $(ODIR)/lex.o $(ODIR)/utils.o
	$(CC) -o $@ $^ $(DFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^ $(DFLAGS)

clean:
	rm $(BDIR)/tube; rm $(ODIR)/*.o
