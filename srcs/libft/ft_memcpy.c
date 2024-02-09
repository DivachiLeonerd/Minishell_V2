/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:53:08 by atereso-          #+#    #+#             */
/*   Updated: 2021/12/19 12:22:28 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest0;
	unsigned char	*src0;

	dest0 = (unsigned char *)dest;
	src0 = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (n)
	{
		*dest0 = *src0;
		dest0++;
		src0++;
		n--;
	}
	return (dest);
}
