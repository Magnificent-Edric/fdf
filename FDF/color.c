/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:01:39 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:38:45 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../mlx_linux/mlx.h"

double	color_read(int s, int e, int curr)
{
	double	place;
	double	dist;

	place = curr - s;
	dist = e - s;
	if (dist == 0)
		return (1.0);
	else
		return (place / dist);
}

int	default_color(int z, t_fdf *fdf)
{
	double	perc;

	perc = color_read(fdf->data.min, fdf->data.maxim, z);
	if (perc < 0.2)
		return (COLOR_D);
	else if (perc < 0.4)
		return (COLOR_RED);
	else if (perc < 0.6)
		return (FLAMINGO);
	else if (perc < 0.8)
		return (JAFFA);
	else
		return (SAFFRON);
}

int	deep_color(int z, t_fdf *fdf)
{
	double	perc;

	perc = color_read(fdf->data.min, fdf->data.maxim, z);
	if (perc < 0.05)
		return (0x000066);
	else if (perc < 0.1)
		return (FS);
	else if (perc < 0.2)
		return (T);
	else if (perc < 0.3)
		return (TH);
	else if (perc < 0.4)
		return (F);
	else if (perc < 0.5)
		return (FI);
	else if (perc < 0.6)
		return (S);
	else if (perc < 0.7)
		return (SE);
	else if (perc < 0.8)
		return (E);
	else
		return (N);
}

int	create_color(int c1, int c2, float prc)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((float)(get_r(c2) - get_r(c1)) *prc) + (float) get_r(c1));
	g = (int)(((float)(get_g(c2) - get_g(c1)) *prc) + (float) get_g(c1));
	b = (int)(((float)(get_b(c2) - get_b(c1)) *prc) + (float) get_b(c1));
	return (create_trgb(255, r, g, b));
}
