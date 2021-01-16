#include <stdio.h>
#include <stdlib.h>
#include"Trie.h"
#define NUM_LETTERS ((int)26)
typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;

// typedef struct node
// {
//     char letter;
//     long unsigned int count;
//     struct node *children[NUM_LETTERS];
// } node;

int main(int argc, char **argv)
{
   node* trie=createNode();
    while (1)
    {
        int n = 1;
        char *temp = (char *)malloc(n * sizeof(char));
       
        if (temp == NULL)
        {
             printf("error in memory allocate\n");
             exit(1);
        }
        int index = 0;
        char got = '\0';
        while (((got = getchar()) != ' ') && (got != '\n') && (got != '\t') && (got != EOF))
        {
            if (((65 <= got) && (got <= 90)) || ((97 <= got) && (got <= 122)))
            {
                n = n + 1;
                temp = realloc(temp, n);
                if (temp == NULL)
                {
                    printf("error in memory allocate\n");
                    exit(1);
                }
                // If the input is an uppercase char:
                if ((65 <= got) && (got <= 90))
                {
                    // By adding 32, we add the same char in ASCII but lowercase.
                    temp[index] = got + 32;
                    index = index + 1;
                }
                else if ((97 <= got) && (got <= 122))
                {
                    // The input is one of a,b,c,...,z letters.
                    temp[index] = got;
                    index = index + 1;
                }
            }
        }
        if ((index != 0) && ((got == EOF) || (got == ' ') || (got == '\t') || (got == ('\n'))))
        {
            temp[index] = '\0';
            // printf("%s\n", temp);
            addNode(trie,temp);
        }
        free(temp);
        if (got == EOF)
        {
            break;
        }
    }
    if (argc >= 2)
    {
        if (argv[1][0] == 'r')
        {
            //printf("print reverse\n");
            printTrieinReverse(trie );
        }
    }
    else
    {
       // printf("print normal\n");
        printTrie(trie);
    }
    freeTrie(trie);
    return 0;
}