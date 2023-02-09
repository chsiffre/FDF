/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maping.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:16:21 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/09 12:53:57 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_line(t_map *map)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	choose_view(map);
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

void	ft_2d(double *x, double *y, t_map *map)
{
	*x += map->min;
	*y += map->max;
}

void	ft_isometric(double *x, double *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(3.141592654 / 3);
	*y = (*x + *y) * sin(3.141592654 / 6) - (z * map->alt);
	*x += map->min;
	*y += (map->max);
}

void	ft_place_line(t_map *map, int y, int x)
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

int	ft_setup_coord(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->data = (int *)
		mlx_get_data_addr(map->image, &map->bpp, &map->size_l, &map->endian);
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
	return (0);
}
