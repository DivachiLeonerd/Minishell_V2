/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:39:13 by afonso            #+#    #+#             */
/*   Updated: 2022/03/02 16:09:08 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	print_integer(int i, char format)
{
	char	*s;
	int		counter;

	if (format == 'c')
	{
		ft_putchar_fd(i, 1);
		return (1);
	}
	s = ft_itoa(i);
	counter = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (counter);
}
