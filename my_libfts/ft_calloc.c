/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:58:27 by medric            #+#    #+#             */
/*   Updated: 2021/10/13 16:58:32 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*str;

	str = malloc(size * number);
	if (str)
		ft_bzero(str, number * size);
	if (str == 0)
		return (NULL);
	return ((void *)str);
}
