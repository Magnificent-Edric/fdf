/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:39:07 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 19:40:06 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

int	delay_key(int key, t_fdf *fdf)
{
	shift(key, fdf);
	zoom(key, fdf);
	deep(key, fdf);
	koef_z(key, fdf);
	return_in_start(key, fdf);
	proection(key, fdf);
	esc(key, fdf);
	return (0);
}

void	init_param(t_fdf *fdf)
{
	if (fdf->height <= 10 && fdf->weight <= 10)
		fdf->zoom = 20;
	else if (fdf->height <= 29 && fdf->weight <= 29)
		fdf->zoom = 15;
	else if (fdf->height >= 35 && fdf->weight >= 35)
		fdf->zoom = 3;
	fdf->data.angel_x = 0.0;
	fdf->data.angel_y = 0.0;
	fdf->data.kof_z = 1.0f;
	fdf->color_deep_step = 0;
	fdf->mouse.mouse_down = 0;
	fdf->color_deep = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->transfer_h = fdf->height / 2;
	fdf->transfer_w = fdf->weight / 2;
	fdf->max = 0;
	fdf->dx = 0;
	fdf->place1 = 0;
	fdf->place2 = 0;
	fdf->dy = 0;
	fdf->data.optimal1 = (H / 2) - (fdf->zoom * fdf->height) / 2;
	fdf->data.optimal2 = (W / 2) - (fdf->zoom * fdf->weight) / 2;
	fdf->colors = 0;
}

int	expose(t_fdf *fdf)
{
	free_matrix(fdf);
	free_color(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	free(fdf);
	exit(0);
}

void	del_mlx(t_fdf *fdf)
{
	free_matrix(fdf);
	free_color(fdf);
	free(fdf->mlx_ptr);
	free(fdf);
	msg_error(MLX);
}

int	main(int ac, char *av[])
{
	t_fdf	*fdf;
	t_data	*data;

	if (ac != 2)
		msg_error(ERR_ARG);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->color_find = 0;
	read_file(fdf, av[1]);
	init_param(fdf);
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		del_mlx(fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, W, H, "FDF");
	if (!fdf->win_ptr)
		del_mlx(fdf);
	draw(fdf);
	mlx_hook(fdf->win_ptr, 4, (1L << 2), &mouse_down, fdf);
	mlx_hook(fdf->win_ptr, 5, (1L << 3), &mouse_up, fdf);
	mlx_hook(fdf->win_ptr, 6, (1L << 6), &mouse_move, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, expose, fdf);
	mlx_key_hook(fdf->win_ptr, delay_key, fdf);
	mlx_loop_hook(fdf->mlx_ptr, draw_win, fdf);
	mlx_loop(fdf->mlx_ptr);
}
