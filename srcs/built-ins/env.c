/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:45:50 by afonso            #+#    #+#             */
/*   Updated: 2023/05/17 18:24:22 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../minishell.h"

int	env(void)
{
	int	i;

	i = 0;
	while (g_struct.myenvp[i])
	{
		printf("%s\n", g_struct.myenvp[i]);
		i++;
	}
	return (0);
}
