/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:59:29 by medric            #+#    #+#             */
/*   Updated: 2022/05/01 22:32:52 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	size_t			i;
	unsigned char	new_sym;

	i = 0;
	new_sym = (unsigned char)symbol;
	while (string[i] != '\0')
	{
		if (string[i] == new_sym)
		{
			return ((char *)(string + i));
		}
		i++;
	}
	if (new_sym == '\0')
		return ((char *)(string + i));
	return (NULL);
}
