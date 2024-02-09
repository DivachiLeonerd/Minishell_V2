/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:51:08 by atereso-          #+#    #+#             */
/*   Updated: 2021/12/19 12:20:46 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*findback_c(char *start_s, const char *end_s, int c)
{
	if (c > 256)
		c = c - 256;
	while (end_s != start_s)
	{
		end_s--;
		if (*end_s == c)
			return ((char *)end_s);
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*s)
		s++;
	return (findback_c(start, ++s, c));
}
