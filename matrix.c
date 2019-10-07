/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:32:39 by kblack            #+#    #+#             */
/*   Updated: 2019/09/30 21:32:42 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mtx_vec_multi(float mtx[4][4], t_map *vec)
{
	float	x;
	float	y;
	float	z;

	x = vec->x * mtx[0][0] + vec->y * mtx[0][1] +
		vec->z * mtx[0][2] + mtx[0][3];
	y = vec->x * mtx[1][0] + vec->y * mtx[1][1] +
		vec->z * mtx[1][2] + mtx[1][3];
	z = vec->x * mtx[2][0] + vec->y * mtx[2][1] +
		vec->z * mtx[2][2] + mtx[2][3];
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void		mtx_multi(float mtx1[4][4], float mtx2[4][4], float dst[4][4])
{
	int		y;
	int		x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			dst[y][x] = mtx1[y][0] * mtx2[0][x] +
						mtx1[y][1] * mtx2[1][x] +
						mtx1[y][2] * mtx2[2][x] +
						mtx1[y][3] * mtx2[3][x];
		}
	}
}

void		identity_mtx(float mtx[4][4])
{
	ft_bzero(mtx, sizeof(float) * 4 * 4);
	mtx[0][0] = 1.0f;
	mtx[1][1] = 1.0f;
	mtx[2][2] = 1.0f;
	mtx[3][3] = 1.0f;
}

void		scale_mtx(float dst[4][4], float scale)
{
	float	scale_mtx[4][4];

	identity_mtx(scale_mtx);
	scale_mtx[0][0] = scale;
	scale_mtx[1][1] = scale;
	scale_mtx[2][2] = scale;
	mtx_multi(scale_mtx, dst, dst);
}

void		translate_xyz(float dst[4][4], float x, float y, float z)
{
	float	translation_mtx[4][4];

	identity_mtx(translation_mtx);
	translation_mtx[0][3] = x;
	translation_mtx[1][3] = y;
	translation_mtx[2][3] = z;
	mtx_multi(translation_mtx, dst, dst);
}
