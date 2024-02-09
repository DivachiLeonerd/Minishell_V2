/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:32:10 by afonso            #+#    #+#             */
/*   Updated: 2022/03/08 11:32:19 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static	char	*alloc_string(unsigned int n);
static	char	*reverse_string(char *string);

char	*ft_utoa(unsigned int n)
{
	char			ch;
	unsigned int	i;
	char			*string;
	unsigned int	aux;

	aux = n;
	i = 0;
	string = alloc_string(aux);
	if (!string)
		return (NULL);
	if (aux == 0)
		string[i++] = '0';
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
	char			tmp;
	unsigned int	strlen;
	unsigned int	i;
	unsigned int	end;
	unsigned int	begin;

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

static	char	*alloc_string(unsigned int n)
{
	unsigned int	power;
	char			*string;

	power = 0;
	if (n == 0)
		power++;
	while (n > 0)
	{
		n = n / 10;
		power++;
	}
	string = ft_calloc(power + 1, sizeof(char));
	if (!string)
		return (NULL);
	return (string);
}
