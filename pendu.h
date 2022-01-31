#ifndef __PENDU_H__
#define __PENDU_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#include "loadWords.h"

typedef struct
{
    OffsetTable_t *Offset_table;
    char *wordToGuess;
    int wordSize;
    size_t lineSize;

} word_t;

word_t *createWord_t(OffsetTable_t *);
int initPendu(word_t *);
int chooseRandomWord(word_t*, char **);
int check_input(word_t*, char **);
#endif