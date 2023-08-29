#include "../../headers/minishellv2.h"

char    *get_env_line(char **env, char *varname)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (!ft_strncmp(env[i], "HOME", 4))
            return (env[i]);
        i++;
    }
    return (NULL);
}

char    *get_env_var(char *env_line)
{
    int     i;

    i = 0;
    while (env_line[i] != '=')
        i++;
    return (ft_strdup(&(env_line[++i])));
}