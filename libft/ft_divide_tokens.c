/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:16:20 by afonso            #+#    #+#             */
/*   Updated: 2023/05/22 15:06:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_counter(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '\"' )
		{
			count++;
			while (*s && (*s != '\'' || *s != '\"'))
				s++;
		}
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_divide_tokens(char const *s, char c)
{
	char	**dst;
	char	*str;
	size_t	i;

	dst = (char **)malloc(sizeof(char *) * (char_counter(s, c) + 1));
	if (!dst)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s == '\"')
		{
			s++;
			str = (char *)s;
			while (*s && (*s != '\"'))
				s++;
			dst[i] = (char *)malloc(s - str + 1);
			if (!dst)
				return (0);
			ft_strlcpy(dst[i++], str, s - str + 1);
			s++;
		}
		else if (*s != c)
		{
			str = (char *)s;
			while (*s && *s != c)
				s++;
			dst[i] = (char *)malloc(s - str + 1);
			if (!dst)
				return (0);
			ft_strlcpy(dst[i++], str, s - str + 1);
		}
		else
			s++;
	}
	dst[i] = NULL;
	return (dst);
}
