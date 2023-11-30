/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:27:00 by afonso            #+#    #+#             */
/*   Updated: 2022/03/08 11:33:07 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static	int	prepare_string(unsigned long long quotient, int strlen,
				char *string);

int	print_pointer(void	*ptr_x)
{
	char						string[16];
	unsigned long long int		quotient;
	int							strlen;

	if (ptr_x == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	quotient = (unsigned long long)ptr_x;
	strlen = prepare_string(quotient, 0, string);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(string, 1);
	return (strlen + 2);
}

static	int	prepare_string(unsigned long long quotient, int strlen,
		char *string)
{
	int					aux;
	unsigned long long	temp;

	temp = quotient;
	while (temp)
	{
			temp /= 16;
			strlen++;
	}
	aux = strlen;
	while (aux <= 16)
		string[aux++] = '\0';
	while (quotient)
	{
		string[--strlen] = (unsigned char)(quotient % 16);
		if (string[strlen] > 9)
			string[strlen] += 87;
		else
			string[strlen] += 48;
		quotient = quotient / 16;
	}
	return (ft_strlen(string));
}

// int	main(void)
// {
// 	unsigned int	i;
// 	i = 100000000;
// 	printf("%p\n", &i);
// 	print_pointer(&i);
// }
