/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:12:07 by afonso            #+#    #+#             */
/*   Updated: 2021/12/10 17:00:28 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstring;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	newstring = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		newstring[i] = f(i, s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
