/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:21 by chsiffre          #+#    #+#             */
/*   Updated: 2022/12/04 16:46:58 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void init_coord(t_map *map)
{
	map->x1 *= map->size;
	map->x1 *= map->size;
	map->y1 *= map->size;
	map->y2 *= map->size;
}

void ft_print_line(t_map *map)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	//init_coord(map);
	map->z = map->tab[(int)map->x1][(int)map->y1];
	map->z1 = map->tab[(int)map->x2][(int)map->y2];
	delta_x = (map->x2 - map->x1);
	delta_y = (map->y2 - map->y1);
	pixel_x = map->x1;
	pixel_y = map->y1;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels--)
	{
		if (map->z > 0 || map->z1 > 0)
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, pixel_x, pixel_y, 0xFFFFFF);
		else
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, pixel_x, pixel_y, 0xff8000);
		pixel_x += delta_x;
		pixel_y += delta_y;
	}
}

void ft_isometric_line(double *x, double *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x - *y) * cos(0.8) - z;
}

void ft_place_line(t_map *map, int i, int j)
{
	map->x1 = map->min + (map->size * (j - i)) / sqrt(2);
	map->y1 = map->max - (map->tab[i][j] * map->s->line_count)
		+ (map->size * (i + j)) / sqrt(6);
	if (j + 1 < map->s->column_count)
	{
		map->x2 = map->min + ((map->size * (j + 1)) - (map->size * i)) \
			/ sqrt(2);
		map->y2 = map->max - (map->tab[i][j + 1] * map->s->line_count) \
			+ ((map->size * i) + (map->size * (j + 1))) / sqrt(6);
		ft_print_line(map);
	}
	if (i + 1 < map->s->line_count)
	{
		map->x2 = map->min + ((map->size * j) - (map->size * (i + 1))) \
			/ sqrt(2);
		map->y2 = map->max - (map->tab[i + 1][j] * map->s->line_count) \
			+ ((map->size * (i + 1)) + (map->size * j)) / sqrt(6);
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
			ft_place_line(map, x, y);
			x++;
		}
		y++;
	}
}

void ft_init_structure(t_map *map, int fd, char *file)
{
	map->s = init_struct(malloc(sizeof(t_coord)));
	map->tab = lets_pars(fd, file, map->s);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_W, WIN_H, "42");
	map->x1 = 0;
	map->x2 = 1;
	map->y1 = 0;
	map->y2 = 1;
	printf("%zd ", map->s->column_count);
	printf("%zd ", map->s->line_count);
	map->size = round((WIN_W + WIN_H) / 2) / (map->s->line_count + map->s->column_count - 2);
	map->min = (WIN_W - ((map->s->line_count + map->s->column_count) * map->size) / sqrt(2)) / 2;
	map->min += (map->s->line_count * map->size / sqrt(2));
	map->max = (WIN_H - (map->size * (map->s->line_count + map->s->column_count)) / sqrt(6)) / 2;
	ft_setup_coord(map);
	mlx_loop(map->mlx_ptr);
}