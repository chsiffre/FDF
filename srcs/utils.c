/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:56:21 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/08 19:23:14 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include "ft_printf.h"
#include "mlx.h"

void	clear_image(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			map->data[(int)i * WIN_W + (int)j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_exit(t_map *map)
{
	int	y;

	y = -1;
	while (++y < map->s->line_count)
		free(map->tab[y]);
	free(map->tab);
	exit(0);
	return ;
}

t_map	*ft_init_structure(t_map *map, int fd, char *file)
{
	map->s = init_struct(malloc(sizeof(t_coord)));
	if (!map->s)
		return (NULL);
	map->tab = lets_pars(fd, file, map->s);
	if (!map->tab)
		return (NULL);
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (NULL);
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_W, WIN_H, "42");
	map->image = mlx_new_image(map->mlx_ptr, WIN_W, WIN_H);
	ft_init_var(map);
	ft_setup_coord(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
	return (map);
}

void	ft_init_var(t_map *map)
{
	map->view = 0;
	map->x1 = 0;
	map->x2 = 1;
	map->y1 = 0;
	map->y2 = 1;
	map->alt = 1;
	map->size = round((WIN_W + WIN_H) / 2)
		/ (map->s->column_count + map->s->line_count - 2);
	map->min = (WIN_W - ((map->s->line_count + map->s->column_count)
				* map->size) / sqrt(2)) / 2;
	map->min += map->s->line_count * map->size / sqrt(2);
	map->max = (WIN_H * 3 / 2 - (map->s->line_count * map->size
				+ map->s->column_count * map->size) / sqrt(6)) / 2;
}

int	deal_key(int key, t_map *map)
{
	if (key == 122)
		map->view = 1;
	if (key == 97)
		map->view = 0;
	if (key == 65451)
		map->size += 1;
	if (key == 65453)
		map->size -= 1;
	if (key == 65307)
		ft_exit(map);
	if (key == 110)
		map->alt += 0.1;
	if (key == 109)
		map->alt -= 0.1;
	if (key == 65362)
		map->max += 20;
	if (key == 65364)
		map->max -= 20;
	if (key == 65363)
		map->min -= 20;
	if (key == 65361)
		map->min += 20;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	clear_image(map);
	return (ft_setup_coord(map), 0);
}
