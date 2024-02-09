/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:56:05 by atereso-          #+#    #+#             */
/*   Updated: 2023/04/03 17:35:55 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*alloc;

	i = 0;
	if (!s1)
		return (NULL);
	alloc = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (i <= ft_strlen(s1))
	{
		alloc[i] = ((char *)s1)[i];
		i++;
	}
	return (alloc);
}
