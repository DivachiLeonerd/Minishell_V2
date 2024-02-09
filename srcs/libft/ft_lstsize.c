/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:29:25 by afonso            #+#    #+#             */
/*   Updated: 2021/12/14 12:38:01 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*pointer;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	if (!(lst->next))
		return (1);
	pointer = lst;
	while (pointer->next)
	{
		i++;
		pointer = pointer->next;
	}
	return (++i);
}
