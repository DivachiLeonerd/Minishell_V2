/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:36 by afonso            #+#    #+#             */
/*   Updated: 2021/12/14 16:14:49 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_position;

	if (lst)
	{
		if (*lst)
		{
			last_position = ft_lstlast(*lst);
			last_position->next = new;
		}
		else
			*lst = new;
		new->next = NULL;
	}
	return ;
}
