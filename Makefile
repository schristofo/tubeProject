CC=gcc
SDIR=./src
BDIR=./bin

$(BDIR)/5f: $(SDIR)/5f.c
	$(CC) $^ -o $@

clean:
	rm $(BDIR)/5f
