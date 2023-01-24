/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:44:53 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:39:39 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

float	max(float n1, float n2)
{
	float	x;
	float	y;

	x = n1;
	y = n2;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		return ((float) x);
	else
		return ((float) y);
}

int	fdf_in_winx(float x)
{
	if (x < 0)
		return (0);
	if (x >= W)
		return (W - 1);
	return ((int) x);
}

int	fdf_in_winy(float y)
{
	if (y < 0)
		return (0);
	if (y >= H)
		return (H - 1);
	return ((int) y);
}

void	maximum(t_fdf *fdf)
{
	int	j;
	int	i;

	i = 0;
	fdf->data.min = fdf->z[0][0];
	fdf->data.maxim = fdf->z[0][0];
	while (i < fdf->height - 1)
	{
		j = 0;
		while (j < fdf->weight - 1)
		{
			if (fdf->data.maxim < fdf->z[i][j])
				fdf->data.maxim = fdf->z[i][j];
			if (fdf->data.min > fdf->z[i][j])
				fdf->data.min = fdf->z[i][j];
			j++;
		}
		i++;
	}
}
