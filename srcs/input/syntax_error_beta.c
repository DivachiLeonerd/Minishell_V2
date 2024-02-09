/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_beta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:23:15 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/24 18:01:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/parser.h"

int	valid_eol(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if (line[i - 1] == '>' || line[i - 1] == '<' || line[i - 1] == '|')
	{
		printf("Ohh, do you need help honey?\n");
		return (1);
	}
	if (line[i - 1] == ' ')
	{
		i--;
		line[i] = '\0';
		valid_eol(line);
	}
	return (0);
}

int	syntax_checker(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] == ' ')
		i++;
	if (line[0] == '>' || line[0] == '<' || line[0] == '|')
	{
		printf("STOOPID BEETCH\n");
		return (1);
	}
	//also, the last character cant be <, > or >>
	while (line[i] && j < 3)
	{
		i++;
		if (line[i] == '>' || line[i] == '<' || line[i] == '|')
			j++;
		else
			j = 0;
		//This is for cases like: "[text] <| [text]", "<|" isn't valid
		if (j == 2 && line[i] != line[i - 1])
			return (2);
	}
	if (valid_eol(line))
		return (1);
	if (line[i] == 0)
		return (0);
	else
		return (1);
	return (0);
}
