#include "pendu.h"

word_t *createWord_t(OffsetTable_t *table)
{
    assert(table != NULL);
    word_t *word_table = malloc(sizeof(word_t));
    if (word_table == NULL)
        return NULL;

    word_table->Offset_table = table;
    return word_table;
}

int initPendu(word_t* word_table)
{
    assert(word_table != NULL);

    srand(time(NULL));
    word_table->Offset_table->table_fd = fopen("IndexTable.txt", "r");
    if (word_table->Offset_table->table_fd == NULL)
        return -1;
    return 0;

}
int chooseRandomWord(word_t* word_table, char **input)
{
    assert(word_table != NULL);
    int random = 0, i;

    while (((random = rand() % word_table->Offset_table->table_fd_size) % 11) != 0);
    fseek(word_table->Offset_table->table_fd, random, SEEK_SET);
    getline(&word_table->Offset_table->wordOffsetStr, &word_table->lineSize, word_table->Offset_table->table_fd);
    word_table->Offset_table->wordOffset = atoi(word_table->Offset_table->wordOffsetStr);

    fseek(word_table->Offset_table->src_fd, word_table->Offset_table->wordOffset, SEEK_SET);
    word_table->wordSize = getline(&word_table->wordToGuess, &word_table->lineSize, word_table->Offset_table->src_fd);
    word_table->wordSize--;

    *(word_table->wordToGuess + word_table->wordSize) = '\0';
    *input = (char *)malloc(sizeof(char)*word_table->wordSize + 1);
    if (input == NULL)
        return -1;

    for (i = 0; i < word_table->wordSize; i++)
        *(*input + i) = '_';
    return 0;
}

int check_input(word_t* word_table, char **input)
{
    assert(word_table != NULL && input != NULL);
    int i;

    for (i = 0; i < word_table->wordSize; i++)
    {
        
        if (*(*input + i) == *(word_table->wordToGuess + i))
            *(*input + i) = *(word_table->wordToGuess + i);
        else
            *(*input + i) = '_';

    }
    if (strcmp(*input, word_table->wordToGuess) == 0)

        return 0;
    else
        return 1;

}   