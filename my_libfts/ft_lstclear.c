/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:03:19 by medric            #+#    #+#             */
/*   Updated: 2021/10/18 16:04:27 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*nextel;

	if (!lst || !del)
		return ;
	nextel = *lst;
	while (nextel)
	{
		current = nextel;
		nextel = current->next;
		ft_lstdelone(current, del);
	}
	*lst = NULL;
}
