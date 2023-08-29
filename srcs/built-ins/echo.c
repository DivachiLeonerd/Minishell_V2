/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:25:59 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:08:16 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../minishell.h"
//echo tem que poder usar a flag "-n" que faz com que echo
//não printe \n no final da string escrita
//echo tem de conseguir printar com quotes e single quotes
//e saber printar env vars se tiverem '$' e todos os ficheiros se tiver '*'.

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

char	**find_env_full_var(char *message)
{
	char	*var_name;
	int		i;
	//message: MYVAR=value
	i = 0;
	var_name = get_variable_name(message);
	while (g_struct.myenvp[i])
	{
		if (ft_strncmp(g_struct.myenvp[i], &(var_name[0]),
				ft_strlen(var_name)) == 0)
			break ;
		i++;
	}
	if (g_struct.myenvp[i] == NULL)
	{
		free(var_name);
		return ((char **)0);
	}
	free(var_name);
	return (&(g_struct.myenvp[i]));
}

int	ft_echo(char **args)
{
	int	numberof_args;
	int	i;
	int	j;

	numberof_args = how_many_arrays(args);
	if (numberof_args < 1)
	{
		printf("\n");
		return (-1);
	}
	if (numberof_args == 1)
	{
		printf("\n");
		return (0);
	}
	if (numberof_args == 2 && ft_strncmp(args[1], "-n",
			ft_strlen(args[1])) == 0)
		return (0);
	// isto bem feito era ter um array com todas as flags e ver
	//se n existe nehuma non-flag presente mas como só temos
	// q fazer uma flag.....
	i = 0;
	j = 0;
	if (numberof_args > 2 && args[1][0] == '-')
	{
		i = 1;
		j = 1;
		while (args[1][j] && args[1][j] == 'n')
			j++;
		if (args[1][j] && args[1][j] != 'n')
			printf("%s", args[1]);
	}
	i += 1;
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
		if (args[i])
			printf(" ");
	}
	if (ft_strncmp(args[1], "-n", ft_strlen(args[1])) != 0)
		printf("\n");
	return (0);
}
