/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:34:03 by medric            #+#    #+#             */
/*   Updated: 2022/05/08 17:40:06 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/my_libft.h"

void	msg_error(char *err)
{
	ft_putstr_fd(err, 0);
	exit(0);
}

void	free_param(int i, char **param)
{
	i++;
	while (param[i])
	{
		free(param[i]);
		i++;
	}
	free(param);
}

void	free_all_param(char *s, t_fdf *fdf, char *line, char **param)
{
	free(line);
	free(s);
	free_param(fdf->param, param);
	free_matrix(fdf);
	free_color(fdf);
	free(fdf);
	msg_error(LINE_BAD);
}

void	del(t_fdf *fdf, int fd)
{
	close(fd);
	free_matrix(fdf);
	free_color(fdf);
	free(fdf);
	msg_error(MAP_NOT_VALID);
}
