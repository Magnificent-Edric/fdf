/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:39:55 by medric            #+#    #+#             */
/*   Updated: 2021/10/12 18:40:05 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	char		*dstn;
	char		*strn;

	i = size;
	dstn = dst;
	strn = (char *)src;
	while (i-- != 0 && *dstn != '\0')
		dstn++;
	dst_len = dstn - dst;
	i = size - dst_len;
	if (i == 0)
		return (dst_len + ft_strlen(strn));
	while (*strn != '\0')
	{
		if (i != 1)
		{
			*dstn++ = *strn;
			i--;
		}
		strn++;
	}
	*dstn = '\0';
	return (dst_len + (strn - src));
}
