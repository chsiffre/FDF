/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:21 by chsiffre          #+#    #+#             */
/*   Updated: 2022/12/09 14:38:15 by chsiffre         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


void ft_print_line(t_map *map)
{
	double	delta_x;
	double	delta_y;
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
		if ((int)map->y1 * WIN_W + (int)map->x1 < WIN_W * WIN_H && \
				(int)map->x1 < WIN_W && (int)map->x1 > 0 && \
				(int)map->y1 < WIN_H && (int)map->y1 > 0)
			map->data[(int)map->y1 * WIN_W + (int)map->x1] = ft_color(map);
		map->x1 += delta_x;
		map->y1 += delta_y;
	}
}

int	ft_color(t_map *map)
{
	int x;
	
	x = map->s->max / 8;
	if (map->high >= x * 8 || map->high1 >= x * 8)
		return (0xD1380B);
	else if (map->high > x * 7 || map->high1 > x * 7)
		return (0x9D450C);
	else if (map->high > x * 6 || map->high1 > x * 6)
		return (0xD27C41);
	else if (map->high > x * 5 || map->high1 > x * 5)
		return (0xB0AC2D);
	else if (map->high > x * 4 || map->high1 > x * 4)
		return (0xA0B02D);
	else if (map->high > x * 3 || map->high1 > x * 3)
		return (0x81C822);
	else if (map->high > x * 2 || map->high1 > x * 2)
		return (0x8FD71F);
	else if (map->high > 0 || map->high1 > 0)
		return (0x63F200);
	else
		return (0x1FB0D7);
}

void ft_isometric_line(double *x, double *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(3.141592654/3);
	*y = (*x + *y) * sin(3.141592654/6) - (z * map->alt);
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
	map->image = mlx_new_image(map->mlx_ptr, WIN_W, WIN_H);
	map->data = (int *) mlx_get_data_addr(map->image, &map->bpp, &map->size_l, &map->endian);
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
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->image, 0, 0);

}
