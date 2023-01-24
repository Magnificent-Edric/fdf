/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:57:01 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 16:57:06 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*new_dest;
	const unsigned char		*new_src;

	i = 0;
	new_dest = dest;
	new_src = src;
	if (new_dest == 0 && new_src == 0)
		return (NULL);
	while (i < len)
	{
		*new_dest = *new_src;
		new_dest++;
		new_src++;
		i++;
	}
	return (dest);
}
