/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:38:51 by afonso            #+#    #+#             */
/*   Updated: 2022/03/03 13:26:13 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	print_unsigned_int(unsigned int u)
{
	char	*s;
	int		counter;

	s = ft_utoa(u);
	counter = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (counter);
}
