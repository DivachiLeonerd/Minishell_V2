/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_env_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:58:53 by afonso            #+#    #+#             */
/*   Updated: 2023/05/09 19:23:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*get_variable_name(char *message)
{
	int		i;
	char	*var_name;
	//message: MYVAR=NAME
	i = 0;
	if (!message || message[i] == 0)
		return (NULL);
	while (message[i] != '=' && message[i] != '\0')
		i++;
	var_name = malloc((i + 1) * sizeof(char));
	var_name[i] = 0;
	ft_strlcpy(var_name, &(message[0]), i + 1);
	return (var_name);
}

void	add_var_to_env(char **new_env, char **old_env, char *var)
{
	int	i;

	i = 0;
	while (old_env[i])
	{
		new_env[i] = ft_strdup(old_env[i]);
		i++;
	}
	new_env[i] = ft_strdup(var);
	new_env[++i] = NULL;
	return ;
}

char	**replace_env_var(char **env, char *var)
{
	int		i;
	char	*new_name;

	i = 0;
	new_name = get_variable_name(var);
	while (env[i])
	{
		if (ft_strncmp(env[i], new_name, ft_strlen(new_name)) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup(var);
		}
		i++;
	}
	free(new_name);
	return (env);
}

void	delete_var_from_env(char **new_env, char **old_env, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (old_env[i])
	{
		if (ft_strncmp(old_env[i], var, ft_strlen(var)) == 0)
			i++;
		new_env[j] = ft_strdup(old_env[i]);
		if (old_env[i])
		{
			i++;
			j++;
		}
	}
	new_env[j] = NULL;
	return ;
}
