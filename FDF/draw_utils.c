/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:46:29 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:39:09 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	brezenheim_unusual(t_fdf *fdf, float *color)
{
	if (fdf->color_deep == 0)
		my_mlx_pixel_put(fdf, fdf_in_winx(fdf->coord0.x0), \
			fdf_in_winy(fdf->coord0.y0), \
			create_color((int) fdf->color0, (int) fdf->color1, *color));
	else if (fdf->color_deep == 1)
		my_mlx_pixel_put(fdf, fdf_in_winx(fdf->coord0.x0), \
			fdf_in_winy(fdf->coord0.y0), \
			create_color((int) fdf->color0, (int) fdf->color1, *color));
}

void	brezenheim_usual(t_fdf *fdf, float *color, float color_step)
{
	while ((int)(fdf->coord1.x1 - fdf->coord0.x0)
		|| (int)(fdf->coord1.y1 - fdf->coord0.y0))
	{
		if (fdf->color_deep == 0)
			my_mlx_pixel_put(fdf, fdf_in_winx(fdf->coord0.x0), \
				fdf_in_winy(fdf->coord0.y0), \
				create_color((int) fdf->color0, (int) fdf->color1, *color));
		else if (fdf->color_deep == 1)
			my_mlx_pixel_put(fdf, fdf_in_winx(fdf->coord0.x0), \
				fdf_in_winy(fdf->coord0.y0), \
				create_color((int) fdf->color0, (int) fdf->color1, *color));
		*color += color_step;
		fdf->coord0.x0 += fdf->dx;
		fdf->coord0.y0 += fdf->dy;
	}
}
