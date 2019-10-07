/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fdf_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblack <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:25:30 by kblack            #+#    #+#             */
/*   Updated: 2019/10/01 19:25:34 by kblack           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		free_double_ptr(char **ptr)
{
	int		i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void		free_file(char *file)
{
	free(file);
	file = NULL;
}

void		check_map_input(char **input, t_utl *utl)
{
	size_t	i;

	i = 0;
	while (input[i])
		i++;
	if (utl->len == 0)
		utl->len = i;
	else if (utl->len != 0 && utl->len != i)
	{
		ft_printf("Error: Invalid Map\n");
		exit(1);
	}
}

void store_measurements(t_utl *utl, int height, int width)
{
	utl->height = height;
	utl->width = width;
	utl->scale = WIDTH / width;
}

void			print_error(void)
{
	ft_printf("Error: Invalid file descriptor\n");
	exit(1);
}
