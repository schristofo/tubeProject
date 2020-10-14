CC=gcc
DFLAGS= 
SDIR=./src
BDIR=./bin

$(BDIR)/5f: $(SDIR)/5f.c
	$(CC) $^ -o $@ $(DFLAGS)

clean:
	rm $(BDIR)/5f
