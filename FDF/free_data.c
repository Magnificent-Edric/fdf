/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:30:35 by medric            #+#    #+#             */
/*   Updated: 2022/05/05 18:50:21 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

void	free_matrix(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->height)
	{
		free(fdf->z[i]);
		i++;
	}
	free(fdf->z);
}

void	free_array(char **str)
{
	int	i;
	int	len_s;

	i = 0;
	len_s = 2;
	while (i < len_s)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_color(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->height)
	{
		free(fdf->color[i]);
		i++;
	}
	free(fdf->color);
}

void	free_all_matrix(t_fdf *fdf)
{
	free_matrix(fdf);
}
