/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:05:47 by afonso            #+#    #+#             */
/*   Updated: 2023/05/19 20:05:40 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../minishell.h"
// int	get_env_fd(char **envp)
// {
// 	int fd;
// 	if (access("/usr/local/bin", F_OK) == 0)
// 	{
// 		if (access("/usr/local/bin", W_OK) == 0 && access("/usr/local/bin",
//				R_OK) == 0)
// 			fd = open("/usr/local/bin", O_RDWR);
// 	}
// 	return (fd);
// }

int	export(char **args)
{
	char	**var;
	char	*new_var;
	char	**new_env;
	//variable == "NAME=VALUE"
	errno = 0;
	new_env = NULL;
	var = find_env_full_var(args[0]);
	new_var = ft_strdup(args[0]);
	if (var == NULL) //if var not found
		g_struct.myenvp = env_realloc(g_struct.myenvp, new_env, 1, args[0]);
	else
		g_struct.myenvp = env_realloc(g_struct.myenvp, new_env, 0, args[0]);
	free(new_var);
	return (errno);
}
