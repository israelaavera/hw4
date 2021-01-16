CC=gcc
FLAGS=-Wall -g 
OBJECT_MAIN=main.o
OBJECT_TRIE=Trie.o

all: frequency $(OBJECT_MAIN) $(OBJECT_TRIE)

frequency: $(OBJECT_MAIN) $(OBJECT_TRIE)
	$(CC) $(OBJECT_MAIN) $(OBJECT_TRIE) -o frequency 

$(OBJECT_MAIN): main.c Trie.h
	$(CC) $(FLAGS) -c main.c -o $(OBJECT_MAIN)

$(OBJECT_TRIE): Trie.c Trie.h
	$(CC) $(FLAGS) -c Trie.c -o $(OBJECT_TRIE)

clean:
	rm -f frequency *.o
  



