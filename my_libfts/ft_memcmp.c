/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:45:22 by medric            #+#    #+#             */
/*   Updated: 2021/10/12 20:11:58 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*b;

	d = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n--)
	{
		if (*d != *b)
			return (*d - *b);
		d++;
		b++;
	}
	return (0);
}
