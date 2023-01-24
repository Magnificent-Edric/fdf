/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:58:55 by medric            #+#    #+#             */
/*   Updated: 2022/04/16 17:46:37 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_libft.h"

static int	check(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	check_space(const char *str)
{
	long long int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\r') && str[i] != '\0')
		i++;
	return (i);
}

static int	check_error(int count, int minimum, int t)
{
	int	ad;

	ad = 0;
	if (count > 19 && minimum < 0)
		ad = 0;
	else if (minimum > 0 && count > 19)
		ad = -1;
	else
		ad = t;
	return (ad);
}

int	ft_atoi(const char *str)
{
	int					minimum;
	long long int		t;
	long long int		count;
	long long int		i;

	t = 0;
	i = 0;
	minimum = 1;
	count = 0;
	i = check_space(str);
	if (str[i] == '-' || str[i] == '+')
	{
		minimum = check(str[i]);
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		t = t * 10 + (str[i] - '0');
		i++;
		count++;
	}
	if (minimum)
		t = minimum * t;
	t = check_error(count, minimum, t);
	return (t);
}
