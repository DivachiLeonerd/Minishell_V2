#include "../../headers/minishellv2.h"

int is_line_blank(char *line)
{
    int     i;
    i = 0;
   while (line[i])
   {
        if (line[i] >= 33 || line[i] <= 126)
                return (0);
        i++;
   }
   return (1);
}

char    *print_prompt()
{
    int i;
   char *cwd;
   char *new_cwd;

    new_cwd = NULL;
   i = 0;
   cwd = getcwd(NULL, 0);
   if (!cwd)
       return (NULL);
   while (cwd[i])
   {
        if (!ft_strncmp(get_env_user(env), &(cwd[i]), ft_strlen(&(cwd[i]))))
            break ;
        i++;
   }
   if (cwd[i] == NULL)
        return (cwd);
    new_cwd = get_new_cwd(cwd);
}

char    *get_prompt_line()
{
    char    *line;

    line = NULL;
    while (1)
    {
        line = readline(print_prompt());
        if (!line)
        {
            printf("exit.\n");
            exit(0);
        }
        if (!is_line_blank(line))
            break ;
        free(line);
        printf("\n");
    }
    //last_line is gonna be a new variable that represents the last
    //command in a .shell_history text file
}   return (line);
