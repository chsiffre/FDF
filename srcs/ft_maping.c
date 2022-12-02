/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:21 by chsiffre          #+#    #+#             */
/*   Updated: 2022/11/30 18:11:33 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_init_structure(t_map *map, int fd, char *file)
{
	map->tab = lets_pars(fd, file);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
}

void ft_print_line(t_map *map)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = 10 - 0;
	delta_y = 10 - 0;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = map->x1;
	pixel_y = map->y1;
	while (pixels--)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, pixel_x, pixel_y, 0xFFAF33);
		pixel_x += delta_x;
		pixel_y += delta_y;
	}
}