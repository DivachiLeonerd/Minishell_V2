/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:17:04 by atereso-          #+#    #+#             */
/*   Updated: 2021/12/21 13:17:07 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*allocator;
	size_t	i;

	i = 0;
	allocator = malloc(count * size);
	if (!allocator)
		return (NULL);
	while (i < (count * size))
	{
		allocator[i] = 0;
		i++;
	}
	return ((void *)allocator);
}
