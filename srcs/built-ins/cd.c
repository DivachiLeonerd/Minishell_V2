/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:19:20 by afonso            #+#    #+#             */
/*   Updated: 2023/05/22 17:05:12 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../tree/parser.h"
#include "../../minishell.h"

// depois temos que usar getcwd() para mudar o prompt
int	cd(char *pathname)
{
	int		ret;
	char	*old_pwd;
	char	*pwd;
	char	*temp;
	char	*aux;

	errno = 0;
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		free(old_pwd);
		return (errno);
	}
	if (!pathname)
	{
		pathname = ft_strdup("$HOME");
		pathname = str_expander(pathname);
		chdir(pathname);
		if (errno != 0)
		{
			free(old_pwd);
			return (errno);
		}
		free(pathname);
	}
	else if (pathname[0] == '~')
	{
		temp = ft_strdup("$HOME");
		temp = str_expander(temp);
		aux = ft_strdup(pathname);
		pwd = ft_substr(aux, 1, ft_strlen(aux) - 1);
		free(aux);
		aux = ft_strjoin(temp, pwd);
		free(temp);
		errno = 0;
		ret = chdir(pathname);
		if (errno != 0)
			g_struct.chad_exitstatus = errno;
		free(aux);
		free(pwd);
	}
	else
	{
		ret = chdir(pathname);
	}
	if (ret == 0)
	{
		temp = ft_strjoin("OLDPWD=", old_pwd);
		free(old_pwd);
		export(&temp);
		free(temp);
		pwd = getcwd(NULL, 0);
		temp = ft_strjoin("PWD=", pwd);
		free(pwd);
		export(&temp);
		free(temp);
		if (errno != 0)
			return (errno);
	}
	else
		free(old_pwd);
	return (errno);
}
