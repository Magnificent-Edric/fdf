/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:41:52 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:39:05 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	coords1(int x1, int y1, t_fdf *fdf)
{
	t_coord1	coord1;

	fdf->coord1.z1 = (float) fdf->z[y1][x1];
	fdf->coord1.x1 = (float) x1;
	fdf->coord1.y1 = (float) y1;
	if (fdf->color_find == 1 && fdf->color_deep == 0 && fdf->color[y1][x1] != 0)
		fdf->color1 = fdf->color[y1][x1];
	else if (fdf->color_find == 0 && fdf->color_deep == 0)
		fdf->color1 = default_color(fdf->coord1.z1, fdf);
	else if (fdf->color_find == 1 && fdf->color[y1][x1] == 0
		&& fdf->color_deep == 0)
		fdf->color1 = default_color(fdf->coord1.z1, fdf);
	else if ((fdf->color_deep == 1 && fdf->color_find == 0)
		|| (fdf->color_find == 1 && fdf->color_deep == 1))
		fdf->color1 = deep_color(fdf->coord1.z1, fdf);
}

void	coords0(int x0, int y0, t_fdf *fdf)
{
	t_coord0	coord0;

	fdf->coord0.z = (float) fdf->z[y0][x0];
	fdf->coord0.x0 = (float) x0;
	fdf->coord0.y0 = (float) y0;
	if (fdf->color_find == 1 && fdf->color_deep == 0 && fdf->color[y0][x0] != 0)
		fdf->color0 = fdf->color[y0][x0];
	else if (fdf->color_find == 0 && fdf->color_deep == 0)
		fdf->color0 = default_color(fdf->coord0.z, fdf);
	else if (fdf->color_find == 1 && fdf->color[y0][x0] == 0
		&& fdf->color_deep == 0)
		fdf->color0 = default_color(fdf->coord0.z, fdf);
	else if ((fdf->color_deep == 1 && fdf->color_find == 0)
		|| (fdf->color_find == 1 && fdf->color_deep == 1))
		fdf->color0 = deep_color(fdf->coord0.z, fdf);
}
