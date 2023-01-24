/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:43:54 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 17:42:33 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

void	creat_matrix_color(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->color = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	while (i < fdf->height)
		fdf->color[i++] = (int *)malloc(sizeof(int) * (fdf->weight + 1));
	i = 0;
	fdf->z = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	while (i < fdf->height)
		fdf->z[i++] = (int *)malloc(sizeof(int) * (fdf->weight + 1));
}

void	atoi_hex_utils(long int *color, char s)
{
	if (s >= '0' && s <= '9')
		*color = *color * 16 + (s - '0');
	if (s >= 'a' && s <= 'f')
		*color = *color * 16 + (10 + (s - 'a'));
	if (s >= 'A' && s <= 'F')
		*color = *color * 16 + (10 + (s - 'A'));
}

int	ft_atoi_hex(char *s)
{
	long int	color;

	color = 0;
	if (*s == '0')
		s++;
	if (*s == 'x')
		s++;
	while (*s != '\0' && ((*s >= '0' && *s <= '9') || \
	(*s >= 'a' && *s <= 'f') || (*s >= 'A' && *s <= 'F')))
	{
		atoi_hex_utils(&color, *s);
		s++;
	}
	return ((int) color);
}

int	ft_checkchar(char *s, char c, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			fdf->color_find = 1;
			return (SUCCESS);
		}
		i++;
	}
	return (FAILED);
}
