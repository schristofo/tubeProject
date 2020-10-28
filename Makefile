CC=gcc
DFLAGS=
SDIR=./src
BDIR=./bin
IDIR=./inc
INCLUDES = -I$(IDIR)

$(BDIR)/tube: $(SDIR)/main.o $(SDIR)/lex.o $(SDIR)/utils.o
	$(CC) -o $@ $^ $(DFLAGS)

$(SDIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	rm $(BDIR)/tube; rm $(SDIR)/*.o
