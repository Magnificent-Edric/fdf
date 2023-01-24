/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:04:40 by medric            #+#    #+#             */
/*   Updated: 2021/10/17 17:53:40 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	b;

	i = 0;
	d = (unsigned char *)s;
	b = (unsigned char)c;
	while (i < n)
	{
		if (d[i] == b)
			return ((void *)(d + i));
		i++;
	}
	return (NULL);
}
