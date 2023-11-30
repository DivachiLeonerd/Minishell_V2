#include <stdlib.h>
#include "../../headers/globals.h"
#include "../../headers/libft.h"

void	free_bad_env_build(char **envp, int failed_index)
{
	while (failed_index >= 0)
		free(envp[failed_index--]);
	free(envp);
	return ;
}

int	how_many_arrays(char **double_ptr)
{
	int		i;

	i = 0;
	if (!double_ptr)
		return (0);
	while (double_ptr[i] != NULL)
		i++;
	return (i);
}

char	**build_envp(char **envp)
{
	int		i;
	int		len;

	i = 0;
	len = how_many_arrays(envp);
    gvar.envp = malloc((len + 1) * sizeof(char *));
	if (gvar.envp == NULL)
		return (NULL);
	gvar.envp[len] = NULL;
	while (i < len)
	{
		gvar.envp[i] = ft_strdup(envp[i]);
		if (gvar.envp[i] == NULL)
		{
			free_bad_env_build(gvar.envp, i);
			return (NULL);
		}
		i++;
	}
	return (gvar.envp);
}
