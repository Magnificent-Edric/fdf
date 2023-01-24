/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:01:26 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 17:01:27 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size_sub;
	size_t	i;

	i = 0;
	size_sub = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_sub = ft_strlen(s1);
	while (size_sub && ft_strchr(set, s1[size_sub]))
		size_sub--;
	str = ft_substr((char *)s1, 0, size_sub + 1);
	return (str);
}
