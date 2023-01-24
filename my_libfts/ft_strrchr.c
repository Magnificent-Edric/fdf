/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:01:18 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 17:01:19 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	size_t			i;
	int				tmp;
	unsigned char	*new_str;

	i = 0;
	tmp = -1;
	new_str = (unsigned char *)str;
	while (new_str[i] != '\0')
	{
		if (new_str[i] == (char)sym)
		{
			tmp = i;
		}
		i++;
	}
	if (sym == '\0')
	{
		tmp = i;
	}
	if (tmp >= 0)
	{
		return ((char *)(new_str + tmp));
	}
	return (NULL);
}
