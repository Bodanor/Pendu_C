#ifndef __LOADWORDS_H__
#define __LOADWORDS_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct
{
    FILE *src_fd;
    FILE *table_fd;
    long int src_fd_size;
    long int table_fd_size;
    char *wordOffsetStr;
    int wordOffset;

}OffsetTable_t;

OffsetTable_t *createOffsetTable();
int createOffsetFile(char *, OffsetTable_t *);
#endif
