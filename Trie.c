#include "Trie.h"





node* createNode() {



	int i;

	node* created = (node*)malloc(1*sizeof(node));

	if(created==NULL)

	{

		exit(1);

	}

	for (i = 0; i < NUM_LETTERS; i++) {

		created->children[i] = NULL;

	}

	created->current_str=(char*)malloc(1*sizeof(char));

	if(created->current_str==NULL)

	{

		exit(1);

	}

	*(created->current_str)= ' ';

	created->count = 0;

	created->letter = '\0';//for the root

	return created;

}



void addNode(node*trie, char* str) {

	toLower(str);

	if(trie== NULL)//if the trie is not exist

	{

		trie= createNode();

	}

	node* currentNode = trie;

	node* inserted=NULL;

	char* temp = str;



	while (*temp != '\0') {	

		if (currentNode->children[(*temp) - 'a'] == NULL) {

			inserted = createNode();

			inserted->letter = (*temp);

			currentNode->children[(*temp) - 'a'] = inserted;

		}

		currentNode = currentNode->children[(*temp) - 'a'];

		temp++;

		if(*temp =='\0')

		{

			break;

		}

	}

	temp--;

	currentNode ->count++;

	if(currentNode->count ==1)

	{

		currentNode->current_str=realloc(currentNode->current_str,strlen(str)*sizeof(char)+1);

		if(currentNode->current_str==NULL)

		{

			exit(1);

		}

		//currentNode->current_str=(char*)malloc(strlen(str)*sizeof(char));

		strcpy(currentNode->current_str,str);

	}

}



int isWord(node* n){

	if(n->count>0)

	{

		return 1;// a word

	}

	else

	{

		return 0;//not a word

	}

}

void toLower(char* str) {

	char* temp = str;

	while (*temp != '\0') {

		if (*temp >= 'A' && *temp <= 'Z') {

			(*temp) += 'a' - 'A';

		}

		temp++;

	}

}

// void freeTrie(node* trie) {

// 	if (trie == NULL) {

// 		return;

// 	}

// 	int i;

// 	for (i = 0; i < NUM_LETTERS; i++) {

// 		freeTrie(trie->children[i]);

// 		// if(trie->children[i]!=NULL)

// 		// {

//         //   free(trie->children[i]->current_str);

// 		//   free(trie->children[i]);

// 		// }

// 	}

// 	// if(trie->letter=='\0')

// 	// {

// 	//printf("this is the root\n");

// 		 //free(trie->current_str);

// 	// }

// 	// else{

//     //   printf("the letter is %c\n",trie->letter);

// 	// }



//      free(trie->children[i]->current_str);

//      free(trie);

// }



void freeTrie(node* trie)

{

	if(trie == NULL)

	{

		return;

	}

	free(trie->current_str);

	for(int i = 0; i < NUM_LETTERS; ++i)

	{

		freeTrie(trie->children[i]);

	}

	free(trie);

}



void printTrie(node* trie) {

	if (trie == NULL)

    {

		return;

	}

	if(isWord(trie))

	{

		printf("%s %ld\n",trie->current_str,trie->count );

		return;

	}

	int i;

	for (i = 0; i < NUM_LETTERS; i++) 

	{

		printTrie(trie->children[i]);

	}

}





void printTrieinReverse(node* trie ) {

	if (trie == NULL)

    {

		return;

	}

	if(isWord(trie))

	{

		printf("%s %ld\n",trie->current_str,trie->count );

		return;

	}

	int i;

	for (i =NUM_LETTERS-1; i>=0; i--) {

		printTrieinReverse(trie->children[i]);

	}

}



