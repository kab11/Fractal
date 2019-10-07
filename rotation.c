/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:34:15 by kblack            #+#    #+#             */
/*   Updated: 2019/09/30 21:34:17 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		rotation_x(float dst[4][4], float angle)
{
	float	rotate_mtx[4][4];

	identity_mtx(rotate_mtx);
	rotate_mtx[1][1] = cos(angle);
	rotate_mtx[1][2] = -sin(angle);
	rotate_mtx[2][1] = sin(angle);
	rotate_mtx[2][2] = cos(angle);
	mtx_multi(rotate_mtx, dst, dst);
}

void		rotation_y(float dst[4][4], float angle)
{
	float	rotate_mtx[4][4];

	identity_mtx(rotate_mtx);
	rotate_mtx[0][0] = cos(angle);
	rotate_mtx[0][2] = sin(angle);
	rotate_mtx[2][0] = -sin(angle);
	rotate_mtx[2][2] = cos(angle);
	mtx_multi(rotate_mtx, dst, dst);
}

void		rotation_z(float dst[4][4], float angle)
{
	float	rotate_mtx[4][4];

	identity_mtx(rotate_mtx);
	rotate_mtx[0][0] = cos(angle);
	rotate_mtx[0][1] = -sin(angle);
	rotate_mtx[1][0] = sin(angle);
	rotate_mtx[1][1] = cos(angle);
	mtx_multi(rotate_mtx, dst, dst);
}
