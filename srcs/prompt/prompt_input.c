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

char    *get_new_cwd(char   *cwd)
{
    char    new_cwd[255];
    char    *home_value;
    int     i;
    int     j;

    i = 0;
    j = 0;
    home_value = get_env_var(get_env_line(env, "HOME"));
    while (cwd[i])
    {
        if (!ft_strncmp("home/", &(cwd[i]), 6))
        {
            while ()
            {

            }
        }
)
        new_cwd[j] = cwd[i]
        i++;
    }

}
char    *print_prompt()
{
    int i;
   char *cwd;
   char *var_value;

   i = 0;
   cwd = getcwd(NULL, 0);
   if (!cwd)
       return (NULL);
    while (cwd[i])
    {
        if (!ft_strncmp("home/", &(cwd[i]), 6))
            break ;
        i++;
    }
   if (cwd[i] == '\0')
        return (cwd);
    return (get_new_cwd(cwd));
}

char    *get_prompt_line()
{
    char    *line;

    line = NULL;
    while (1)
    {
        line = readline(print_prompt(env));
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
