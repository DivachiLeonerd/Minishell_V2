/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:43:59 by atereso-          #+#    #+#             */
/*   Updated: 2023/07/29 11:49:26 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// input: char *command_line
// checks if basic syntatic rules are met. If that's the case then go to parser
// if not then just write an error to stderr and go wait for further input again
#include "../headers/minishellv2.h"

int	syntax_checker(char *command_line)
{
	int	i;
	int	special_repeated;

	special_repeated = 0;
	i = 0;
	if (!command_line)
		return (1);
	if (command_line[0] == '|')
		return (1);
	while (command_line[i])
	{
		if (command_line[i] == '|')
		{
			//Should We implement here_strings?
			if (command_line[i + 1] == '<' || command_line[i + 1] == '>' || command_line[i + 1] == '|')
			{
				perror("syntax error. Didn't expect '\''");
				write(2, &(command_line[i + 1]), 1);
				perror("'\' 'token");
				return (1);
			}
		}
		if (command_line[i] == '<' || command_line[i] == '>')
		{

			special_repeated++;
			if (special_repeated == 2)
			{
				perror("syntax error. Didn't expect that many '\''");
				write(2, &(command_line[i]), 1);
				perror ("'\'' tokens.");
				return (1);
			}
		}
		else
			special_repeated = 0;
		i++;
	}
}
