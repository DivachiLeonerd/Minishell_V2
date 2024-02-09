/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:16:20 by afonso            #+#    #+#             */
/*   Updated: 2021/12/27 19:26:15 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	**free_split(int i, char **split)
{
	while (i-- < 0)
		free(split[i]);
	return (NULL);
}

static int	word_count(char const *s, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static int	how_many_char(const char *s, char c, int wordnum)
{
	int	i;
	int	counter;
	int	chrnum;

	chrnum = 0;
	counter = 0;
	i = 0;
	while (s[i] && counter <= wordnum)
	{
		if (s[i] != c)
		{
			counter++;
			while ((s[i] != c && s[i]))
			{
				i++;
				if (wordnum == counter)
					chrnum++;
			}
		}
		if (s[i])
			i++;
	}
	return (chrnum);
}

static char const	*return_word(char const *s, int c, int wordnum)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (s[i] && (counter <= wordnum))
	{
		if (s[i] != c)
		{
			counter++;
			while ((s[i] != c && s[i]))
			{
				if (wordnum == counter)
					return (&s[i]);
				i++;
			}
		}
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	split = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[word_count(s, c)] = NULL;
	while (i < word_count(s, c))
	{
		split[i] = ft_substr(s, return_word(s, c, i + 1) - s,
				how_many_char(s, c, i + 1));
		if (!split[i])
			return (free_split(i, split));
		i++;
	}
	return (split);
}

// int	main(void)
// {
// 	char	**_split;
// 	int		i;
// 	int		j;
// 	char	ch = ' ';

// 	i = 0;
// 	_split = ft_split("Hwllo Wolrd", ch);
// 	if (!_split)
// 		return (1);
// 	while (_split[i])
// 	{
// 		j = 0;
// 		while (_split[i][j] != 0)
// 			write(1, (_split[i]) + j++, 1);
// 		write(1, "\n",1);
// 		i++;
// 	}
// 	free_split(i, _split);
// }
