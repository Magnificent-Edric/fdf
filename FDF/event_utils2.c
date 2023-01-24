/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:09:51 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:38:39 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

void	rot_transf(t_coord0 *coord0, t_coord1 *coord1, int x, int y)
{
	coord0->x0 += (float) x;
	coord0->y0 += (float) y;
	coord1->x1 += (float) x;
	coord1->y1 += (float) y;
}

void	proection_utils(int key, t_fdf *fdf)
{
	if (key == 32)
	{
		fdf->data.angel_x = 0.0f;
		fdf->data.angel_y = RAD;
		fdf->place1 = - (fdf->data.optimal1) + (H / 2) \
		- (fdf->zoom * fdf->data.maxim);
		fdf->place2 = - (fdf->data.optimal2) + (W / 2) \
		- (fdf->zoom * fdf->weight) / 2;
	}
	if (key == 122)
	{
		fdf->data.angel_x = RAD_30;
		fdf->data.angel_y = RAD_30;
	}
}

void	proection(int key, t_fdf *fdf)
{
	if (key == 120)
	{
		fdf->data.angel_x = RAD;
		fdf->data.angel_y = 0.0f;
		if (fdf->data.maxim > fdf->height)
			fdf->place1 = - (fdf->data.optimal1) + (H / 2) \
			- (fdf->zoom * fdf->data.maxim) / 2;
		else if (fdf->data.maxim <= fdf->height)
			fdf->place1 = - (fdf->data.optimal1) + (H / 2) \
			- (fdf->zoom * fdf->height) / 2;
		fdf->place2 = - (fdf->data.optimal2) + (W / 2) \
		- (fdf->zoom * fdf->weight) / 2;
	}
	proection_utils(key, fdf);
}

int	draw_win(t_fdf *base)
{
	mlx_destroy_image(base->mlx_ptr, base->img);
	draw(base);
	return (0);
}

void	esc(int key, t_fdf *fdf)
{
	if (key == 65307)
		expose(fdf);
}
