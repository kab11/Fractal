/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:31:08 by kblack            #+#    #+#             */
/*   Updated: 2019/09/24 21:31:12 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fdf(const char *filename)
{
	t_utl		utl;
	char		*line;
	t_map		**map;
	t_img		img;

	line = NULL;
	ft_bzero(&map, sizeof(map));
	ft_bzero(&utl, sizeof(utl));
	read_number_col_row(line, filename, &utl);
	map = malloc(utl.height * sizeof(t_map *));
	utl.fd = open(filename, O_RDONLY);
	if ((utl.fd = open(filename, O_RDONLY)) < 0)
		print_error();
	read_map(line, &utl, map, utl.fd);
	utl.map = map;
	utl.m_ptr = mlx_init();
	utl.w_ptr = mlx_new_window(utl.m_ptr, WIDTH, HEIGHT, "FDF 42");
	utl.img = &img;
	utl.img->image = mlx_new_image(utl.m_ptr, WIDTH, HEIGHT);
	utl.img->buf = (int *)mlx_get_data_addr(utl.img->image,
		&(utl.img->bpp), &(utl.img->len), &(utl.img->endian));
	ft_bzero(utl.keys, sizeof(int) * 256);
	set_hooks(&utl);
	mlx_loop(utl.m_ptr);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("ERROR: incorrect number of arguments\n");
		return (0);
	}
	fdf(argv[1]);
	return (0);
}
