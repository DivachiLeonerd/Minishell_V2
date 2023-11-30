/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smol_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:11:50 by afonso            #+#    #+#             */
/*   Updated: 2023/03/06 17:07:05 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_smol_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}
