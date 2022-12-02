/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:21 by chsiffre          #+#    #+#             */
/*   Updated: 2022/12/02 17:02:42 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void ft_init_structure(t_map *map, int fd, char *file)
{
	map->s = init_struct(malloc(sizeof(t_coord)));
	map->tab = lets_pars(fd, file, map->s);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "42");
	map->x1 = 20;
	map->x2 = 20;
	map->y1 = 0;
	map->y2 = 20;
	ft_setup_coord(map);
	mlx_loop(map->mlx_ptr);
}

void ft_place_line(t_map *map, int i, int j)
{
	map->x1 = i * 100;
	map->y1 = j *100;
	map->x2 = (i + 1) * 100;
	map->y2 = j * 100;
	if (i + 1 < map->s->column_count)
		ft_print_line(map);
	map->x2 = i * 100;
	map->y2 = (j + 1) * 100;
	if (j + 1 < map->s->line_count)
		ft_print_line(map);
}
void ft_setup_coord(t_map *map)
{
	ssize_t x;
	ssize_t y;

	x = 0;
	y = 0;
	while (y < map->s->line_count)
	{
		x = 0;
		while (x < map->s->column_count)
		{
			ft_place_line(map, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void ft_print_line(t_map *map)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = (map->x2 - map->x1);
	delta_y = (map->y2 - map->y1);
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