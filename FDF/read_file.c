/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:48:24 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 19:44:02 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

static int	ft_word_count(char *s, char c)
{
	size_t		kol_s;
	size_t		i;

	i = 0;
	kol_s = 0;
	while (s[i] != '\n' && s[i])
	{
		if (s[i] != c)
		{
			kol_s++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (kol_s);
}

int	get_height_and_widht(char *file_name, t_fdf *fdf)
{
	char	*line;
	int		height;
	int		fd;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		del_fdf(fdf, fd);
	line = get_next_line(fd);
	fdf->weight = ft_word_count(line, ' ');
	if (line)
	{
		height++;
		while (line)
		{
			free(line);
			line = get_next_line(fd);
			height++;
		}
		free(line);
	}
	height--;
	close(fd);
	return (height);
}

void	check_line_correct(char *line, t_fdf *fdf)
{
	int		i;
	char	**tmp;

	fdf->param = 0;
	i = ft_word_count(line, ' ');
	if (i != fdf->weight)
		uncorrect_data_line(fdf, line);
}

void	creat_matrix_map(int *z, char *line, int *c, t_fdf *fdf)
{
	char	**param;
	char	**num_hex;

	check_line_correct(line, fdf);
	param = ft_split(line, ' ');
	while (param[fdf->param])
	{
		if (ft_checkchar(param[fdf->param], ',', fdf) == SUCCESS)
		{
			check_data_param(param[fdf->param], fdf, line, param);
			num_hex = ft_split(param[fdf->param], ',');
			z[fdf->param] = ft_atoi(num_hex[0]);
			c[fdf->param] = ft_atoi_hex(num_hex[1]);
			free_array(num_hex);
		}
		else if (ft_checkchar(param[fdf->param], ',', fdf) == FAILED)
		{
			z[fdf->param] = ft_atoi(param[fdf->param]);
			c[fdf->param] = 0;
		}
		free(param[fdf->param]);
		fdf->param++;
	}
	free(param[fdf->param]);
	free(param);
}

void	read_file(t_fdf *fdf, char *file_name)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fdf->height = get_height_and_widht(file_name, fdf);
	if (fdf->height < 1 || fdf->weight < 1)
		del_win(fdf);
	creat_matrix_color(fdf);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		del(fdf, fd);
	while (i < fdf->height)
	{
		line = get_next_line(fd);
		creat_matrix_map(fdf->z[i], line, fdf->color[i], fdf);
		i++;
		free(line);
	}
	fdf->color[i] = NULL;
	fdf->z[i] = NULL;
	close(fd);
}
