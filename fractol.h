/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 23:35:04 by kblack            #+#    #+#             */
/*   Updated: 2019/10/04 23:35:08 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define MIN(a, b) (a > b) a : b
# define MAX(a, b) (a > b) b : a
# define WIDTH 1000
# define HEIGHT 1000

/*
** struct node of linked list
*/
typedef struct	s_map
{
	float		x;
	float		y;
	float		z;
}				t_map;

typedef struct	s_img
{
	void		*image;
	int			*buf;
	int			bpp;
	int			len;
	int			endian;
}				t_img;

typedef struct	s_utl
{
	int			fd;
	int			scale;
	int			height;
	int			width;
	int			keys[256];
	void		*m_ptr;
	void		*w_ptr;
	t_map		**map;
	t_img		*img;
	size_t		len;
	int			x_offset;
	int			y_offset;
}				t_utl;

/*
**	free_alloc_mem.c
*/
void			free_double_ptr(char **ptr);
void			free_file(char *file);
void			check_map_input(char **input, t_utl *utl);
void			store_measurements(t_utl *utl, int height, int width);
void			print_error(void);

void			coordinates(t_map **mtx, t_utl *utl);
void			draw_line_to_image(t_map p0, t_map p1, t_utl *utl);
void			translate(float mtx[4][4], float tx, float ty, float tz);
void			translate_map(t_utl *utl, float changex, float changey);

/*
**	rotation.c
*/
void			rotation_x(float dst[4][4], float angle);
void			rotation_y(float dst[4][4], float angle);
void			rotation_z(float dst[4][4], float angle);

/*
**	matrix.c
*/
void			mtx_vec_multi(float mtx[4][4], t_map *vec);
void			mtx_multi(float mtx1[4][4], float mtx2[4][4], float dst[4][4]);
void			identity_mtx(float mtx[4][4]);
void			scale_mtx(float dst[4][4], float scale);
void			translate_xyz(float dst[4][4], float x, float y, float z);

/*
**	key_movements.c
*/
int				handle_input(t_utl *utl);
int				key_down(int key, t_utl *utl);
int				key_up(int key, t_utl *utl);
void			apply_mtx_to_vectors(t_utl *utl, float mtx[4][4]);
void			translate_map(t_utl *utl, float changex, float changey);

/*
**	execute_fdf.c
*/
void			read_number_col_row(char *line,
	const char *filename, t_utl *utl);
void			set_hooks(t_utl *utl);
void			read_map(char *line, t_utl *utl, t_map **map, int fd);

#endif
