/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:59 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/23 16:46:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../built-ins/built-ins.h"
#include "../define.h"
#include "minishell.h"

char	*join_tokens(char *s1, char *s2, int i)
{
	char	*new;

	new = NULL;
	if (s1 && s2)
		new = no_mem(ft_strjoin(s1, s2));
	free(s1);
	if (i)
		free(s2);
	return (new);
}

/*expands string wrapped in double quotes and with a '$'*/
char	*str_expander(char *s)
{
	size_t	size;
	char	*temp;
	char	**full_name;
	int		i;

	i = 0;
	temp = NULL;
	if (!s)
	{
		g_struct.chad_exitstatus = 69420;
		return (NULL);
	}
	size = ft_strlen(s);
	if (size == 1 && s[0] == '$')
		return (s);
	if (ft_strncmp(s, "$?", 2) == 0)
	{
		free(s);
		s = ft_itoa(g_struct.chad_exitstatus);
		return (s);
	}
	if (s[0] == '\"')
		i++;
	if (s[i] == '$')
	{
		temp = ft_substr(s, i, size);
		full_name = find_env_full_var(&(temp[1]));
		free(temp);
		if (!full_name)
		{
			free(s);
			return (NULL);
		}
		temp = ft_substr(*full_name, size, ft_strlen(*full_name) - size);
		free(s);
		return (temp);
	}
	return (s);
}
