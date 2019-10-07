/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:28:28 by kblack            #+#    #+#             */
/*   Updated: 2019/09/30 22:28:38 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Counts the number of columns in the map
** >> Doesn't handle if there are
** ===========NEED TO FIX: will cound too many col for double digits====
*/

int				count_columns(char **tmp)
{
	int			i;

	i = 0;
	while (tmp[i] != '\0')
		i++;
	return (i);
}

/*
** Uses GNL to find number of rows and columns; closes the file and opens
** again to get the xyz-coordinates and store in an array of t_coordinates
** structures
*/

int				render(t_utl *utl)
{
	mlx_clear_window(utl->m_ptr, utl->w_ptr);
	ft_bzero(utl->img->buf, sizeof(int) * WIDTH * HEIGHT);
	handle_input(utl);
	coordinates(utl->map, utl);
	mlx_put_image_to_window(utl->m_ptr, utl->w_ptr, utl->img->image, 0, 0);
	return (0);
}

void			read_number_col_row(char *line, const char *file, t_utl *utl)
{
	int			height;
	int			width;
	int			fd;
	char		**tmp;

	height = 0;
	width = 0;
	tmp = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error();
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		width = count_columns(tmp);
		height++;
		free_double_ptr(tmp);
		free(line);
		line = NULL;
		tmp = NULL;
	}
	close(fd);
	store_measurements(utl, height, width);
}

void			read_map(char *line, t_utl *utl, t_map **map, int fd)
{
	int			x;
	int			y;
	char		**tmp;

	utl->x_offset = WIDTH / 2 - utl->width / 2 * utl->scale;
	utl->y_offset = HEIGHT / 2 - utl->height / 2 * utl->scale;
	y = 0;
	while (get_next_line(fd, &line))
	{
		tmp = ft_strsplit(line, ' ');
		check_map_input(tmp, utl);
		map[y] = malloc(utl->width * sizeof(t_map));
		x = -1;
		while (tmp[++x])
		{
			map[y][x].x = x * utl->scale + utl->x_offset;
			map[y][x].y = y * utl->scale + utl->y_offset;
			map[y][x].z = utl->scale * ft_atoi(tmp[x]);
		}
		y++;
		free_double_ptr(tmp);
		free_file(line);
	}
	close(fd);
}

void			set_hooks(t_utl *utl)
{
	mlx_hook(utl->w_ptr, 2, 0, key_down, utl);
	mlx_hook(utl->w_ptr, 3, 0, key_up, utl);
	mlx_loop_hook(utl->m_ptr, render, utl);
}
