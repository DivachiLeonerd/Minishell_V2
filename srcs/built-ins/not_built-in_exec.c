/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_built-in_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:10:01 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:28:28 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"
#include "../minishell.h"

static void	free_all_paths(char **all_paths)
{
	int	i;

	i = 0;
	while (all_paths[i])
		free(all_paths[i++]);
	free(all_paths);
	return ;
}

// static char	*fix_bin(char *command)
// {
// 	char	**split;
// 	int		size;
// 	int		i;
// 	char	*temp;

// 	i = 0;
// 	split = ft_split(command, '/');
// 	size = how_many_arrays(split);
// 	temp = ft_strdup(split[size - 1]);
// 	printf("temp in fix bin: %s\n", temp);
// 	while (split[i])
// 		free(split[i++]);
// 	free(split[i]);
// 	free(split);
// 	return (temp);
// }

char	*find_command_path(char *command)
{
	int			i;
	char		**all_paths;
	char		*command_path;
	char		*temp;
	struct stat	buff;

	//nota: Nao podemos dar return ao command nunca
	i = 0;
	if (command[0] == '.' || command[0] == '/')
	{
		temp = ft_strdup(command);
		if (access(temp, F_OK) == 0)
		{
			if (access(temp, X_OK) == 0)
			{
				stat(temp, &buff);
				if (S_ISREG(buff.st_mode))
					return (temp);
			}
		}
		g_struct.chad_exitstatus = 13;
		free(temp);
		return (temp = NULL);
	}
	else
		temp = ft_strjoin("/", command);
	while (ft_strncmp("PATH=", g_struct.myenvp[i], 4) != 0)
		i++;
	all_paths = ft_split(g_struct.myenvp[i], ':');
	i = 0;
	while (all_paths[i])
	{
		command_path = ft_strjoin(all_paths[i], temp);
		if (access(command_path, F_OK) == 0 && (ft_strnstr(command_path,
					"..", ft_strlen("..")) == 0))
		{
			//printf("o comando existe\n");
			if (access(command_path, X_OK) == 0)
			{
				//printf("e é executavel\n");
				break ;
			}
		}
		i++;
		free(command_path);
		command_path = NULL;
	}
	free(temp);
	free_all_paths(all_paths);
	// printf("in find_command_path():%s\n", command_path);
	return (command_path);
}

int	execute_non_builtin(char *command_name, char **args)
{
	char	*pathname;

	pathname = find_command_path(command_name);
	free(command_name);
	if (pathname != NULL)
		return (execve(pathname, args, g_struct.myenvp));
	return (127);
}
