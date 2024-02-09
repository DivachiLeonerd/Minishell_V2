/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:50:59 by atereso-          #+#    #+#             */
/*   Updated: 2021/12/21 20:35:37 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = ft_strlen(to_find);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && ((i + j) < len))
		{
			if (j == n - 1)
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
