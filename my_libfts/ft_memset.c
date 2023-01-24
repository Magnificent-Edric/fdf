/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:59:20 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 16:59:22 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int n, size_t len)
{
	size_t			i;
	unsigned char	*new_dest;

	i = 0;
	new_dest = dest;
	while (i < len)
	{
		*new_dest = n;
		new_dest++;
		i++;
	}
	return (dest);
}
