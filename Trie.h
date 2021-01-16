#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define NUM_LETTERS ((int)26)







typedef struct node {

	char letter;

	long unsigned int count;

	struct node* children[NUM_LETTERS];

	char *current_str;



} node;











node* createNode();

void addNode(node*trie, char*str);

void toLower(char* str);

void freeTrie(node* trie);

void printTrie(node* trie);

int isWord(node* n);

void printTrieinReverse(node* trie );





