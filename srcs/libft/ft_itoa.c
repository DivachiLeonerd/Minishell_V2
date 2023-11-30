/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:24:44 by afonso            #+#    #+#             */
/*   Updated: 2021/12/21 18:41:48 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static	char	*alloc_string(int n);
static	char	*reverse_string(char *string);

char	*ft_itoa(int n)
{
	char	ch;
	int		i;
	char	*string;
	int		aux;

	aux = n;
	if (aux == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	string = alloc_string(aux);
	if (!string)
		return (NULL);
	if (aux == 0)
		string[i++] = '0';
	if (aux < 0)
		aux = -aux;
	while (aux != 0)
	{
		ch = aux % 10 + 48;
		string[i] = ch;
		aux = aux / 10;
		i++;
	}
	string = reverse_string(string);
	return (string);
}

static char	*reverse_string(char *string)
{
	char	tmp;
	int		strlen;
	int		i;
	int		end;
	int		begin;

	i = 0;
	begin = 0;
	strlen = ft_strlen(string);
	end = strlen - 1;
	while (i < (strlen / 2))
	{
		tmp = string[begin];
		string[begin] = string[end];
		string[end] = tmp;
		i++;
		begin++;
		end--;
	}
	return (string);
}

static	char	*alloc_string(int n)
{
	unsigned int	power;
	char			*string;
	int				aux;

	aux = n;
	power = 0;
	if (n == 0)
		power++;
	if (n < 0)
	{
		power++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		power++;
	}
	string = ft_calloc(power + 1, sizeof(char));
	if (!string)
		return (NULL);
	if (aux < 0)
		string[power - 1] = '-';
	return (string);
}
