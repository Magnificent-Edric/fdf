/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:24:54 by medric            #+#    #+#             */
/*   Updated: 2021/10/18 17:51:15 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*base;
	void	*cont;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	base = NULL;
	head = ft_lstnew(f(tmp->content));
	tmp = tmp->next;
	while (tmp)
	{
		cont = f(tmp->content);
		base = ft_lstnew(cont);
		if (!base)
		{
			ft_lstclear(&head, del);
			break ;
		}
		ft_lstadd_back(&head, base);
		tmp = tmp->next;
	}
	return (head);
}
