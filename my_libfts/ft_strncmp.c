/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:01:01 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 17:01:03 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t			i;
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	i = 0;
	new_str1 = (unsigned char *)str1;
	new_str2 = (unsigned char *)str2;
	while ((i < num) && (new_str1[i] != '\0') && (new_str2[i] != '\0')
		&& (new_str1[i] == new_str2[i]))
	{
		i++;
	}
	if (i == num)
		return (0);
	return (new_str1[i] - new_str2[i]);
}
