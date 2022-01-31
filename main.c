#include <stdio.h>
#include <stdlib.h>

#include "loadWords.h"
#include "pendu.h"

int main()
{
    int status, tries, i , found, replay = 1;
    char *input = NULL;
    char *progress_word = NULL;

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


    while (replay == 1)
    {
        found = 0;
        chooseRandomWord(word_table, &progress_word, &input);
        for (tries = 10; tries > 0 && found != 1; tries--)
        {
            printf("\nWord -->\t%s", progress_word);
            printf("\t\tTries left :\t%d", tries);
            printf("\nYour -->\t");
            scanf(" %s", input);
            if (check_input(word_table, &input, &progress_word) == 0)
                found = 1;

        }
        if (found)
            printf("Correct !\n");
        else
            printf("No more tries !\n");
        
        printf("Voulez vous rejouer (o/n)? : ");
        scanf(" %c", input);

        if (*input == 'o')
            replay = 1;
        else
            replay = 0;
    }
        
}