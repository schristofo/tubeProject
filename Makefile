CC=gcc
SDIR=./src
BDIR=./bin

$(BDIR)/skata: $(SDIR)/skata.c
	$(CC) $^ -o $@

clean:
	rm $(BDIR)/skata
