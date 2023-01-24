/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:00:25 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 17:00:27 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		t;
	size_t		s3;
	char		*sjoin;

	t = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	s3 = ft_strlen(s1) + ft_strlen(s2);
	sjoin = (char *)malloc(sizeof(char) * (s3) + 1);
	if (sjoin == 0)
		return (NULL);
	while (*s1 != '\0')
	{
		sjoin[t] = *s1;
		s1++;
		t++;
	}
	while (*s2 != '\0')
	{
		sjoin[t] = *s2;
		s2++;
		t++;
	}
	sjoin[t] = '\0';
	return (sjoin);
}
