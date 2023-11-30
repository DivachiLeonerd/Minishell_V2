/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:19:32 by atereso-          #+#    #+#             */
/*   Updated: 2021/12/19 15:06:18 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*array;

	array = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (array[i] == (unsigned char)c)
			return ((char *)&array[i]);
		i++;
	}
	return (NULL);
}
