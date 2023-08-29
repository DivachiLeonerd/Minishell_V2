/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:17:04 by atereso-          #+#    #+#             */
/*   Updated: 2021/12/21 13:17:07 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

long int	ft_atol(const char *str)
{
	long int	number;
	long int	i;
	int			neg;

	neg = 1;
	number = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (str[i] - 48) + number * 10;
		i++;
	}
	return (number * (long int)neg);
}
