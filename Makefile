CC=gcc
SDIR=./src
BDIR=./bin

$(BDIR)/ff: $(SDIR)/ff.c
	$(CC) $^ -o $@

clean:
	rm $(BDIR)/ff
