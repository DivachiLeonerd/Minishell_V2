#include "../../headers/input.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include "../../headers/common.h"

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
        print_prompt(0);
        line = readline(NULL);
        if (!line)
        {
            free(line);
            return (NULL);
        }
        else if (line[0] == '\0')
            free(line);
        else
            return (line);
        printf("\n");
    }
}
