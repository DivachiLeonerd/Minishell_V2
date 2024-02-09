/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:01:10 by afonso            #+#    #+#             */
/*   Updated: 2021/12/27 14:06:38 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst_head;
	t_list	*new_element;

	if (!lst)
		return (NULL);
	newlst_head = ft_lstnew(f(lst->content));
	if (!newlst_head)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			del(new_element->content);
			ft_lstclear(&new_element, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst_head, new_element);
		lst = lst->next;
	}
	return (newlst_head);
}
