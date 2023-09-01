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
    if (env_line == NULL)
        return (NULL);
    while (env_line[i] != '=')
        i++;
    return (&(env_line[++i]));
}
