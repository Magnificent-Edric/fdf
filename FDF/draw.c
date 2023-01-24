/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:31:50 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:39:14 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	if (dst - fdf->addr > 0)
		*(unsigned int *)dst = color;
}

void	start(t_fdf *fdf, t_coord0 *coord0, t_coord1 *coord1)
{
	rot_transf(coord0, coord1, -(fdf->transfer_w), -(fdf->transfer_h));
	isometric(&coord0->x0, &coord0->y0, &coord0->z, fdf);
	isometric(&coord1->x1, &coord1->y1, &coord1->z1, fdf);
	rot_transf(coord0, coord1, (fdf->transfer_w), (fdf->transfer_h));
	fdf->coord0.x0 = (fdf->coord0.x0 + fdf->shift_x) * fdf->zoom \
		+ fdf->data.optimal1 + fdf->place1;
	fdf->coord0.y0 = (fdf->coord0.y0 + fdf->shift_y) * fdf->zoom \
		+ fdf->data.optimal2 + fdf->place2;
	fdf->coord1.x1 = (fdf->coord1.x1 + fdf->shift_x) * fdf->zoom \
		+ fdf->data.optimal1 + fdf->place1;
	fdf->coord1.y1 = (fdf->coord1.y1 + fdf->shift_y) * fdf->zoom \
		+ fdf->data.optimal2 + fdf->place2;
}

void	brezenheim(t_fdf *fdf)
{
	float	color;
	float	color_step;

	color = 0;
	start(fdf, &fdf->coord0, &fdf->coord1);
	draw_init(fdf);
	color_step = 1.0f / fdf->max;
	if ((int)(fdf->coord1.x1 - fdf->coord0.x0) == 0
		&& (int)(fdf->coord1.y1 - fdf->coord0.y0) == 0)
		brezenheim_unusual(fdf, &color);
	else
		brezenheim_usual(fdf, &color, color_step);
}

void	draw_lines(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->weight)
		{
			if (x != fdf->weight - 1)
			{
				coords0(x, y, fdf);
				coords1(x + 1, y, fdf);
				brezenheim(fdf);
			}
			if (y != fdf->height - 1)
			{
				coords0(x, y, fdf);
				coords1(x, y + 1, fdf);
				brezenheim(fdf);
			}
			x++;
		}
		y++;
	}
}

int	draw(t_fdf *fdf)
{
	maximum(fdf);
	fdf->color_deep_step = 1.0f / fdf->data.maxim;
	fdf->img = mlx_new_image(fdf->mlx_ptr, W, H);
	if (!fdf->img)
		return (0);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
		&fdf->line_length, &fdf->endian);
	if (!fdf->addr)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img);
		return (0);
	}
	draw_lines(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img, 0, 0);
	return (0);
}
