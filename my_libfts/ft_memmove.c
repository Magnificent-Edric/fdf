/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:54:43 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 16:54:52 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	i = 0;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (new_dst == 0 && new_src == 0)
		return (NULL);
	if (new_dst < new_src)
	{
		while (i++ < len)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst = new_dst + len - 1;
		new_src = new_src + len - 1;
		while (i++ < len)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
