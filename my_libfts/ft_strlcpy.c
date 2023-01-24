/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:00:40 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 17:00:43 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		s;

	i = 0;
	s = ft_strlen((char *)src);
	if (dst == 0 && src == 0)
		return (0);
	else if (size == 0)
		return (s);
	else if (s < size)
		ft_memcpy(dst, src, s + 1);
	else if (size != 0)
	{
		while (i < size - 1 && *src)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (s);
}
