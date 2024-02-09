/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:54:17 by afonso            #+#    #+#             */
/*   Updated: 2021/12/19 12:33:40 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		index;
	char	*alloc;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	index = 0;
	j = ft_strlen(s1);
	i = 0;
	while ((s1[i] && ft_strchr(set, s1[i])))
		i++;
	while (j >= i && ft_strchr(set, s1[j]))
		j--;
	alloc = malloc((j - i + 2) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (i <= j)
		alloc[index++] = s1[i++];
	alloc[index] = '\0';
	return (alloc);
}
