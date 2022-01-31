#include <stdio.h>
#include <stdlib.h>

#include "loadWords.h"
#include "pendu.h"

int main()
{
    int status, tries = 10, i , found = 0;
    char *input = NULL;
    OffsetTable_t *Offset_table = createOffsetTable();
    if (Offset_table == NULL)
    {
        printf("Error while creating struct !\n");
        return -1;
    }
    status = createOffsetFile("dico.txt", Offset_table);
    if (status == -1)
    {
        printf("Couldn't read word file !\n");
        return -1;
    }
    else if (status == -2)
    {
        printf("couldn't write the index Table !\n(Check permissions)\n");
        return -2;
    }

    word_t *word_table = createWord_t(Offset_table);
    if (word_table == NULL)
    {
        printf("Malloc Error !\n");
    }
    status = initPendu(word_table);
    if (status == -1)
    {
        printf("Coudln't read the index Table back !\n(Check permissions)\n");
        return -1;
    }

    chooseRandomWord(word_table, &input);

    for (; tries > 0 && found != 1; tries--)
    {
        printf("Tries left :\t%d\n\n", tries);
        printf("Word -->\t%s", input);
        printf("\nYour -->\t");
        scanf("%s", input);
        if (check_input(word_table, &input) == 0)
            found = 1;

    }
    if (found)
        printf("Correct !\n");
    else
        printf("No more tries !\n");
    
}