/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:22:49 by chsiffre          #+#    #+#             */
/*   Updated: 2022/12/09 14:38:11 by chsiffre         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "ft_printf.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

void ft_exit(t_map *map)
{
	int	y;
	int i;

	i = 0;
	y = -1;
	while (++y < map->s->line_count)
		free(map->tab[y]);
	free(map->tab);
	exit(0);
	return ;
}

int	deal_key(int key, t_map *map)
{
	if (key == 78)
		map->size += 1;
	if (key == 69)
		map->size -= 1;
	if (key == 53)
		ft_exit(map);
	if (key == 46)
		map->alt += 0.1;
	if (key == 45)
		map->alt -= 0.1;
	if (key == 126)
		map->max += 20;
	if (key == 125)
		map->max -= 20;
	if (key == 124)
		map->min -= 20;
	if (key == 123)
		map->min += 20;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_setup_coord(map);
	return (0);
}

t_map	*ft_init_structure(t_map *map, int fd, char *file)
{
	map->s = init_struct(malloc(sizeof(t_coord)));
	map->tab = lets_pars(fd, file, map->s);
	if (!map->tab)
		return (NULL);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_W, WIN_H, "42");
	map->x1 = 0;
	map->x2 = 1;
	map->y1 = 0;
	map->y2 = 1;
	map->alt = 1;
	map->size = round((WIN_W + WIN_H) / 2) / (map->s->column_count + map->s->line_count - 2);
	map->min = (WIN_W - ((map->s->line_count + map->s->column_count) * map->size) / sqrt(2)) / 2;
	map->min += map->s->line_count * map->size / sqrt(2);
	map->max = (WIN_H * 3/2 - (map->s->line_count * map->size + map->s->column_count * map->size) / sqrt(6)) / 2;
	ft_setup_coord(map);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
	return (map);
}

int main()
{
	t_map *map;
	map = malloc(sizeof(t_map));
	char *file = "file";
	int fd = open(file, O_RDONLY);
	ft_init_structure(map, fd, file);
	close(fd);
	return 0;
}
