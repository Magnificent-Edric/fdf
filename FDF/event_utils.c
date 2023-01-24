/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:58:44 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:39:22 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	shift(int key, t_fdf *fdf)
{
	if (key)
	{
		if (key == 65362)
			fdf->shift_y -= 1;
		if (key == 65364)
			fdf->shift_y += 1;
		if (key == 65363)
			fdf->shift_x += 1;
		if (key == 65361)
			fdf->shift_x -= 1;
	}
}

void	zoom(int key, t_fdf *fdf)
{
	if (fdf->zoom <= 35)
	{
		if (key == 65451)
			fdf->zoom += 1;
		if (key == 4)
			fdf->zoom += 1;
	}
	if (fdf->zoom > 1)
	{
		if (key == 65453)
			fdf->zoom -= 1;
		if (key == 5)
			fdf->zoom -= 1;
	}
	fdf->data.optimal1 = (H / 2) - (fdf->zoom * fdf->height) / 2;
	fdf->data.optimal2 = (W / 2) - (fdf->zoom * fdf->weight) / 2;
}

void	koef_z(int key, t_fdf *fdf)
{
	if (key == 101 && fdf->data.kof_z > 0.1f)
		fdf->data.kof_z -= 0.1f;
	if (key == 113)
		fdf->data.kof_z += 0.1f;
}

void	deep(int key, t_fdf *fdf)
{
	if (key == 103)
		fdf->color_deep = 1;
	if (key == 104)
	{
		if (fdf->color_deep == 1)
			fdf->color_deep = 0;
		fdf->color_deep = 0;
	}
}

void	return_in_start(int key, t_fdf *fdf)
{
	if (key == 115)
		init_param(fdf);
}
