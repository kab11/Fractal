/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:13:34 by kblack            #+#    #+#             */
/*   Updated: 2019/09/30 22:13:43 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_down(int key, t_utl *utl)
{
	utl->keys[key] = 1;
	return (0);
}

int				key_up(int key, t_utl *utl)
{
	utl->keys[key] = 0;
	return (0);
}

void			apply_mtx_to_vectors(t_utl *utl, float mtx[4][4])
{
	int			x;
	int			y;

	y = -1;
	while (++y < utl->height)
	{
		x = -1;
		while (++x < utl->width)
		{
			mtx_vec_multi(mtx, &utl->map[y][x]);
		}
	}
}

void			translate_map(t_utl *utl, float changex, float changey)
{
	int			x;
	int			y;

	y = -1;
	while (utl->height > ++y)
	{
		x = -1;
		while (utl->width > ++x)
		{
			utl->map[y][x].x += changex;
			utl->map[y][x].y += changey;
		}
	}
}

/*
** left arrow || right arrow
** (utl->keys[123] ^ utl->keys[124])
**
** up arrow || down arrow
** (utl->keys[125] ^ utl->keys[126])
*/

int				handle_input(t_utl *utl)
{
	float		mtx[4][4];

	identity_mtx(mtx);
	if (utl->keys[53])
		exit(0);
	if (utl->keys[0] ^ utl->keys[2])
		rotation_y(mtx, (utl->keys[0] ? -0.05f : 0.05f));
	if (utl->keys[13] ^ utl->keys[1])
		rotation_x(mtx, (utl->keys[13] ? 0.05f : -0.05f));
	if (utl->keys[12] ^ utl->keys[14])
		rotation_z(mtx, (utl->keys[12] ? 0.05f : -0.05f));
	if (utl->keys[123] ^ utl->keys[124])
		translate_xyz(mtx, (utl->keys[123] ? -10 : 10), 0, 0);
	if (utl->keys[125] ^ utl->keys[126])
		translate_xyz(mtx, 0, (utl->keys[125] ? 10 : -10), 0);
	if (utl->keys[69] ^ utl->keys[78])
		scale_mtx(mtx, (utl->keys[69] ? 1.1f : 0.9f));
	translate_map(utl, -WIDTH / 2, -HEIGHT / 2);
	apply_mtx_to_vectors(utl, mtx);
	translate_map(utl, WIDTH / 2, HEIGHT / 2);
	return (0);
}
