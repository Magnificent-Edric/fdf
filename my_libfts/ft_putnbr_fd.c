/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:08:29 by medric            #+#    #+#             */
/*   Updated: 2021/10/16 18:51:42 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(long int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static void	putrec(long int n, int fd)
{
	char	numb;

	if (n >= 10)
		putrec(n / 10, fd);
	numb = '0' + (n % 10);
	write(fd, &numb, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int			sign;
	long int	num;

	num = n;
	sign = check(n);
	if (sign < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	putrec(num, fd);
}
