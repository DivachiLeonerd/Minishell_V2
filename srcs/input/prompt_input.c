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
    int     numof_bs;

    numof_bs = 0;
    i = 0;
    j = 0;
    ft_memset(new_cwd, 0, 255);
    home_value = get_env_var(get_env_line(gvar.env));
    home_value = ft_substr(home_value, 0, ft_strlen(home_value));
    while (cwd[i])
    {
        if (!ft_strncmp(home_value, &(cwd[i]), ft_strlen(home_value)))
        {
            while (numof_bs < 2)
            {
                i++;
                if (cwd[i] == '\\')
                    numof_bs++;
            }
            new_cwd[j] = '~';
            j++;
        }
        if (new_cwd[j] && cwd[i])
            new_cwd[j++] = cwd[i++];
    }
    free(home_value);
    home_value = ft_substr(new_cwd, 0, ft_strlen(new_cwd));
    return (home_value);
}
char    *print_prompt()
{
    int i;
   char *cwd;

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
        return (readline(cwd));
    return (readline(get_new_cwd(cwd)));
}

char    *get_prompt_line()
{
    char    *line;

    line = NULL;
    while (1)
    {
        line = print_prompt();
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
    return (line);
}
