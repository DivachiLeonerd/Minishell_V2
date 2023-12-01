#include "../../headers/input.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>

// This is gonna handle all user input as commands
// it's gonna check for command line validity and it's going to
// ask for more input infinitely until input is valid
// It will be the "Interactive mode" or "Normal mode"

char    *get_user_input()
{
    char    *line;

    line = NULL;
    while (1)
    {
        line = readline("I am Born Again:");
        if (!line)
            continue;
        if (line[0] == '0')
        {
            free(line);
            return (NULL);
        }
        printf("\n");
    }
}
