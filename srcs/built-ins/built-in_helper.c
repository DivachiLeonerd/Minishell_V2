/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:24:14 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 18:30:15 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"
#include "../tree/parser.h"
#include "../minishell.h"

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
	g_struct.myenvp = malloc((len + 1) * sizeof(char *));
	if (g_struct.myenvp == NULL)
		return (NULL);
	g_struct.myenvp[len] = NULL;
	while (i < len)
	{
		g_struct.myenvp[i] = ft_strdup(envp[i]);
		if (g_struct.myenvp[i] == NULL)
		{
			free_bad_env_build(g_struct.myenvp, i);
			return (NULL);
		}
		i++;
	}
	return (g_struct.myenvp);
}

char	**env_realloc(char **envp, char **new_env,
		int numof_new_arrays, char *var)
{
	int		len;

	if (numof_new_arrays == 0)
	{
		envp = replace_env_var(envp, var);
		return (envp);
	}
	len = how_many_arrays(envp);
	new_env = malloc(((len + 1) + numof_new_arrays) * sizeof(char *));
	if (new_env == NULL)
		no_mem(new_env);
	if (numof_new_arrays > 0)
		add_var_to_env(new_env, envp, var);
	else
		delete_var_from_env(new_env, envp, var);
	free_matrix(envp);
	// env(*new_env);
	envp = NULL;
	return (new_env);
}

void	free_matrix(char **envp)
{
	int	i;
	int	j;

	j = 0;
	i = how_many_arrays(envp);
	while (j < i)
	{
		free(envp[j]);
		j++;
	}
	free(envp);
}
