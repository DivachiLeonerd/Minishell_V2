/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:44:37 by afonso            #+#    #+#             */
/*   Updated: 2023/05/22 17:11:20 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built-ins.h"
#include  "../minishell.h"
//the purpose of this function will be to receive the binary 
//tree output and put it in the appropriate functions

int	is_builtin(char *command)
{
	// printf("in is_builtin\n");
	if (ft_strncmp("echo", command, ft_strlen("echo")) == 0
		|| ft_strncmp("env", command, ft_strlen("env")) == 0
		|| ft_strncmp("exit", command, ft_strlen("exit")) == 0
		|| ft_strncmp("export", command, ft_strlen("export")) == 0
		|| ft_strncmp("cd", command, ft_strlen("cd")) == 0
		|| ft_strncmp("pwd", command, ft_strlen("pwd")) == 0
		|| ft_strncmp("unset", command, ft_strlen("unset")) == 0)
		return (1);
	return (0);
}

int	execute_builtin(char *command, char **args)
{
	int		ret;

	ret = 0;
	if (ft_strncmp("echo", command, ft_strlen(args[0])) == 0)
		ret = ft_echo(args);
	else if (ft_strncmp("env", command, ft_strlen(args[0])) == 0)
		ret = env();
	else if (ft_strncmp("cd", command, ft_strlen(args[0])) == 0)
		ret = cd(args[1]);
	else if (ft_strncmp("pwd", command, ft_strlen(args[0])) == 0)
	{
		ret = ft_pwd();
	}
	else if (ft_strncmp("export", command, ft_strlen(args[0])) == 0)
		ret = export(&(args[1]));
	else if (ft_strncmp("unset", command, ft_strlen(args[0])) == 0)
		ret = unset(&(args[0]));
	return (ret);
}
