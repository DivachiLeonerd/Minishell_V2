/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:11:47 by afonso            #+#    #+#             */
/*   Updated: 2021/12/14 17:16:03 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (!lst || !del)
		return ;
	temp = *lst;
	temp2 = temp;
	while (temp)
	{
		temp2 = temp2->next;
		del(temp->content);
		free(temp);
		temp = temp2;
	}
	*lst = temp;
	return ;
}
