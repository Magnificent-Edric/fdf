/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:47:50 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:39:31 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	isometric(float *x_s, float *y_s, float *z_s, t_fdf *fdf)
{
	double	z;
	double	x;
	double	y;

	x = *x_s;
	y = *y_s;
	z = *z_s / fdf->data.kof_z;
	*x_s = (float)(cos(fdf->data.angel_y) * x + sin(fdf->data.angel_y) * z);
	*z_s = (float)(-sin(fdf->data.angel_y) * x + cos(fdf->data.angel_y) * z);
	*y_s = (float)(cos(fdf->data.angel_x) * y \
		- sin(fdf->data.angel_x) * (*z_s));
}

void	draw_init(t_fdf *fdf)
{
	fdf->dx = fdf->coord1.x1 - fdf->coord0.x0;
	fdf->dy = fdf->coord1.y1 - fdf->coord0.y0;
	fdf->max = max(fdf->dx, fdf->dy);
	fdf->dx /= fdf->max;
	fdf->dy /= fdf->max;
}

int	mouse_down(int keys, int x, int y, t_fdf *fdf)
{
	if (keys == 4 || keys == 5)
		zoom(keys, fdf);
	fdf->mouse.mouse_down = 1;
	fdf->mouse.x = x;
	fdf->mouse.y = y;
	return (0);
}

int	mouse_up(int keys, int x, int y, t_fdf *fdf)
{
	(void) keys;
	(void) x;
	(void) y;
	fdf->mouse.mouse_down = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	if (!fdf->mouse.mouse_down)
		return (0);
	if (fdf->mouse.y < y)
		fdf->data.angel_x += (fdf->mouse.y - y) * 0.003;
	if (fdf->mouse.y > y)
		fdf->data.angel_x += (fdf->mouse.y - y) * 0.003;
	if (fdf->mouse.x < x)
		fdf->data.angel_y += (fdf->mouse.x - x) * 0.003;
	if (fdf->mouse.x > x)
		fdf->data.angel_y += (fdf->mouse.x - x) * 0.003;
	fdf->mouse.x = x;
	fdf->mouse.y = y;
	return (0);
}
