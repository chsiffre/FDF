/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:21 by chsiffre          #+#    #+#             */
/*   Updated: 2022/12/06 18:44:17 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


void ft_print_line(t_map *map)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	ft_isometric_line(&map->x1, &map->y1, map->high, map);
	ft_isometric_line(&map->x2, &map->y2, map->high1, map);
	delta_x = (map->x2 - map->x1);
	delta_y = (map->y2 - map->y1);
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, 0xff8000);
		map->x1 += delta_x;
		map->y1 += delta_y;
	}
}

void ft_isometric_line(double *x, double *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(3.14/3);
	*y = (*x + *y) * sin(3.14/6) - (z * map->alt);
	*x += map->min;
	*y += (map->max);
}

void ft_place_line(t_map *map, int y, int x)
{
	map->high = map->tab[y][x];
	if (x + 1 < map->s->column_count)
	{
		map->x2 = (x + 1) * map->size;
		map->y2 = y * map->size;
		map->x1 = x * map->size;
		map->y1 = y * map->size;
		map->high1 = map->tab[y][x + 1];
		ft_print_line(map);
	}
	if (y + 1 < map->s->line_count)
	{
		map->x1 = x * map->size;
		map->y1 = y * map->size;
		map->x2 = x * map->size;
		map->y2 = (y + 1) * map->size;
		map->high1 = map->tab[y + 1][x];
		ft_print_line(map);
	}
}

void ft_setup_coord(t_map *map)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < map->s->line_count)
	{
		x = 0;
		while (x < map->s->column_count)
		{	
			ft_place_line(map, y, x);
			x++;
		}
		y++;
	}
}

t_map	*ft_init_structure(t_map *map, int fd, char *file)
{
	map->s = init_struct(malloc(sizeof(t_coord)));
	map->tab = lets_pars(fd, file, map->s);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_W, WIN_H, "42");
	map->x1 = 0;
	map->x2 = 1;
	map->y1 = 0;
	map->y2 = 1;
	map->alt = 1;
	map->size = round(WIN_W / (map->s->column_count + map->s->line_count - 2));
	map->min = (WIN_W - ((map->s->line_count + map->s->column_count) * map->size) / sqrt(2)) / 2;
	map->min += map->s->line_count * map->size / sqrt(2);
	map->max = (WIN_H * 3/2 - (map->s->line_count * map->size + map->s->column_count * map->size) / sqrt(6)) / 2;
	ft_setup_coord(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
	return (map);
}