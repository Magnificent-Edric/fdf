/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:39:39 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 20:40:08 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "my_libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <math.h>
# include "../mlx_linux/mlx.h"

# define ERR_ARG "Invalid number arguments\n"
# define LINE_BAD "Uncorrect line\n"
# define MAP_NOT_VALID "This map don't real\n"
# define MLX "mlx don't work\n"
# define COLOR_D 0x9A1F6A
# define COLOR_RED 0xC2294E
# define FLAMINGO 0xEC4B27
# define JAFFA 0xEF8633
# define SAFFRON 0xF3Af3D
# define WHITE 0xFFFFFF
# define TEXT 0xEAEAEA
# define BACK 0x1E1E1E
# define W 1000
# define H 1000
# define RAD 1.57079632679f
# define RAD_30 0.523599f
# define SUCCESS 1
# define FS 0x003399
# define T 0x3366cc
# define TH 0x3399cc
# define F 0x3399ff
# define FI 0xff66ff
# define S 0xff33cc
# define SE 0xff3399
# define E 0xff0099
# define N 0xff0066
# define FAILED 0

typedef struct s_img
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_back
{
	int	x;
	int	y;
	int	x1;
	int	y1;
}			t_back;

typedef struct s_coord0
{
	float	x0;
	float	y0;
	float	z;	
}			t_coord0;

typedef struct s_data
{
	float	angel_x;
	float	angel_y;
	float	kof_z;
	int		min;
	float	optimal1;
	float	optimal2;
	int		maxim;
	int		coord_summ;
	int		default_color;
	float	tmp;
}			t_data;

typedef struct s_coord1
{
	float	x1;
	float	y1;
	float	z1;
}			t_coord1;

typedef struct s_mouse
{
	int	mouse_down;
	int	x;
	int	y;
}				t_mouse;

typedef struct s_fdf
{
	t_coord0	coord0;
	t_coord1	coord1;
	t_mouse		mouse;
	t_data		data;
	t_back		back;
	int			weight;
	int			height;
	int			**z;
	int			**color;
	float		transfer_h;
	float		transfer_w;
	float		dx;
	float		dy;
	float		place1;
	float		place2;
	float		dz;
	int			key;
	int			param;
	float		max;
	float		max1;
	float		color0;
	float		color1;
	float		color_deep;
	float		colors;
	float		color_deep_step;
	int			shift_x;
	int			zoom;
	int			color_find;
	int			shift_y;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img;
	char		*addr;
	void		*img1;
	char		*addr1;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}			t_fdf;

void		init_param(t_fdf *fdf);
void		read_file(t_fdf *fdf, char *file_name);
void		creat_matrix_map(int *z, char *line, int *c, t_fdf *fdf);
int			get_weight(char *file_name);
int			get_height(char *file_name, t_fdf *fdf);
static int	ft_word_count(char *s, char c);
void		msg_error(char *err);
void		draw_lines(t_fdf *fdf);
int			draw(t_fdf *fdf);
int			delay_key(int key, t_fdf *fdf);
int			draw_new_window(t_fdf *fdf);
int			create_trgb(int t, int r, int g, int b);
double		color_read(int s, int e, int curr);
int			default_color(int z, t_fdf *fdf);
int			create_color(int c1, int c2, float prc);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
void		coords1(int x1, int y1, t_fdf *fdf);
void		coords0(int x0, int y0, t_fdf *fdf);
int			z_coord(int x, int y, int **z, t_fdf *fdf);
void		isometric(float *x_s, float *y_s, float *z_s, t_fdf *fdf);
int			draw_win(t_fdf *base);
int			mouse_move(int x, int y, t_fdf *fdf);
int			fdf_in_winy(float y);
int			fdf_in_winx(float x);
float		max(float n1, float n2);
void		koef_z(int key, t_fdf *fdf);
void		zoom(int key, t_fdf *fdf);
void		shift(int key, t_fdf *fdf);
int			draw_menu(t_fdf *fdf);
void		draw_background(t_fdf *fdf);
void		draw_back(t_fdf *fdf);
void		my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int			mouse_up(int keys, int x, int y, t_fdf *fdf);
int			mouse_down(int keys, int x, int y, t_fdf *fdf);
void		deep(int key, t_fdf *fdf);
int			deep_color(int z, t_fdf *fdf);
void		free_all_matrix(t_fdf *fdf);
void		free_matrix(t_fdf *fdf);
void		return_in_start(int key, t_fdf *fdf);
void		proection(int key, t_fdf *fdf);
void		free_color(t_fdf *fdf);
void		free_tmp(int **m, t_fdf *fdf);
void		maximum(t_fdf *fdf);
void		draw_init(t_fdf *fdf);
int			expose(t_fdf *fdf);
void		free_array(char **str);
void		esc(int key, t_fdf *fdf);
void		proection(int key, t_fdf *fdf);
void		proection_utils(int key, t_fdf *fdf);
void		rot_transf(t_coord0 *coord0, t_coord1 *coord1, int x, int y);
void		creat_matrix_color(t_fdf *fdf);
int			ft_atoi_hex(char *s);
void		atoi_hex_utils(long int *color, char s);
void		brezenheim_usual(t_fdf *fdf, float *color, float color_step);
void		brezenheim_unusual(t_fdf *fdf, float *color);
void		check_data_param(char *s, t_fdf *fdf, char *line, char **param);
void		uncorrect_data_line(t_fdf *fdf, char *line);
void		check_line_correct(char *line, t_fdf *fdf);
int			ft_checkchar(char *s, char c, t_fdf *fdf);
void		del_fdf(t_fdf *fdf, int fd);
void		free_all_param(char *s, t_fdf *fdf, char *line, char **param);
void		free_param(int i, char **param);
void		del(t_fdf *fdf, int fd);
void		del_win(t_fdf *fdf);

#endif