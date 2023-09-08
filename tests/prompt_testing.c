#include "../headers/minishellv2.h"

g_struct gvar;


int main(int argc, char **argv, char **envp)
{
    char    *line;
    (void)argc;
    (void)argv;
    
    gvar.env = build_envp(envp);
    line = NULL;

    line = get_prompt_line();
    if (line)
        free(line);
    return (0);
}
