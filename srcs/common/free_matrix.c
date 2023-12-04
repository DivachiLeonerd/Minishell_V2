#include <stdlib.h>

void    free_matrix(char **matrix)
{
    int i;

    i = 0;
    if (!matrix)
        return ;
    while (matrix[i] != NULL)
    {
        free(matrix[i++]);
    }
    free(matrix);
    return ;
}