/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:01:09 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 17:01:11 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	t;

	t = 0;
	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[t] != '\0' && t < len)
	{
		if (haystack[t] == needle[0])
		{
			i = 0;
			while (haystack[t + i] == needle[i] && (t + i < len)
				&& (haystack[t + i] != '0') && (needle[i] != '\0'))
				i++;
			if (needle[i] == '\0')
				return ((char *)(haystack + t));
		}
		t++;
	}
	return (NULL);
}
