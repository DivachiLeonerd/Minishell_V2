/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:47:47 by afonso            #+#    #+#             */
/*   Updated: 2021/12/21 20:36:03 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	find_mallocsize(int i, int j, char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*alloc;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	alloc = malloc((find_mallocsize(i, j, s1, s2) + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (s1[i])
	{
		alloc[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		alloc[i] = s2[j];
		i++;
		j++;
	}
	alloc[i] = '\0';
	return (alloc);
}

static	int	find_mallocsize(int i, int j, char const *s1, char const *s2)
{
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	return (i + j);
}
