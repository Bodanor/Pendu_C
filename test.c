#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *line = NULL;
    int offset = 0;
    int tmp_offset = 0;
    size_t line_size = 0;

    FILE *src_file = fopen("dico.txt", "r");
    if (src_file == NULL)
        return -1;
    FILE *dst_file = fopen("table.txt", "w");
    if (dst_file == NULL)
        return -1;
    

    while ((getline(&line, &line_size, src_file)) != -1)
    {
        offset = ftell(src_file);
        fprintf(dst_file, "%010d\n", tmp_offset);
        tmp_offset = offset;
    }
    
    int dst_file_size = ftell(dst_file);

    fclose(dst_file);
    dst_file = fopen("table.txt", "r");
    if (dst_file == NULL)
    {
        printf("error");
        return -1;
    }

    srand(time(NULL));
    int random = 0;
    while (((random = rand() % dst_file_size) % 11) != 0);
    fseek(dst_file, random, SEEK_SET);
    getline(&line, &line_size, dst_file);
    printf("string : %s\n", line);
    int a = atoi(line);
    printf("int : %d\n", a);

    fseek(src_file, a, SEEK_SET);
    getline(&line, &line_size, src_file);
    printf("Final word : %s\n", line);


    

}