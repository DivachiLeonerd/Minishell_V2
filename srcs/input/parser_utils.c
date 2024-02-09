/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:59 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/18 18:10:39 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parser.h"
#include "../headers/built-ins.h"
#include "../headers/define.h"
#include "../headers/minishell.h"

int	get_token_type(char *token)
{
	int		token_size;
	char	*aux;

	aux = NULL;
	if (!token)
		return (-1);
	if (token[0] == '\0')
		return (-1);
	token_size = ft_smol_strlen(token);
	if (token_size == 1)
	{
		if (token[0] == '>')
			return (O_REDIR);
		else if (token[0] == '<')
			return (I_REDIR);
		else if (token[0] == '|')
			return (PIPE);
	}
	else if (token_size == 2)
	{
		if (token[0] == '>' && token[1] == '>')
			return (APPEND);
		else if (token[0] == '<' && token[1] == '<')
			return (HEREDOC);
	}
	if (is_builtin(token))
		return (BUILTIN);
	else
		aux = find_command_path(token);
	if (aux)
	{
		free(aux);
		return (EXECUTABLE);
	}
	return (WORD);
}

void	*no_mem(void *p)
{
	if (!p)
	{
		g_struct.chad_exitstatus = 12;
		return (NULL);
	}
	return (p);
}
