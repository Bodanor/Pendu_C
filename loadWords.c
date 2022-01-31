#include "loadWords.h"

OffsetTable_t *createOffsetTable()
{
    OffsetTable_t *Offset_table = malloc(sizeof(OffsetTable_t));
    if (Offset_table == NULL)
        return NULL;
    
    return Offset_table;
}

int createOffsetFile(char *filename, OffsetTable_t *Offset_table)
{
    assert(filename != NULL && Offset_table != NULL);

    char *line = NULL;
    size_t line_size = 0;
    int offset = 0, tmp_offset = 0;

    Offset_table->src_fd = fopen(filename, "r");
    if (Offset_table->src_fd == NULL)
        return -1;
    
    Offset_table->table_fd = fopen("IndexTable.txt", "w");
    if (Offset_table->table_fd == NULL)
        return -2;

    while ((getline(&line, &line_size, Offset_table->src_fd)) != -1)
    {
        offset = ftell(Offset_table->src_fd);
        fprintf(Offset_table->table_fd, "%010d\n", tmp_offset);
        tmp_offset = offset;
    }

    Offset_table->table_fd_size = ftell(Offset_table->table_fd);
    Offset_table->src_fd_size = offset;

    fclose(Offset_table->table_fd);
    return 0;

}