/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:43:29 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 17:45:46 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/my_libft.h"

void	check_data_param(char *s, t_fdf *fdf, char *line, char **param)
{
	int	i;

	i = 0;
	if (s[i] == ',')
		free_all_param(s, fdf, line, param);
	else
	{
		while (s[i] != ',')
		{
			if (s[i] >= '0' && s[i] <= '9')
				i++;
			else
				free_all_param(s, fdf, line, param);
		}
	}
}

void	uncorrect_data_line(t_fdf *fdf, char *line)
{
	free(line);
	free_matrix(fdf);
	free_color(fdf);
	free(fdf);
	msg_error(LINE_BAD);
}

void	del_fdf(t_fdf *fdf, int fd)
{
	close(fd);
	free(fdf->mlx_ptr);
	free(fdf);
	msg_error(MAP_NOT_VALID);
}

void	del_win(t_fdf *fdf)
{
	free(fdf->mlx_ptr);
	free(fdf);
	msg_error(MAP_NOT_VALID);
}
