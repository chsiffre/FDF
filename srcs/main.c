/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:22:49 by chsiffre          #+#    #+#             */
/*   Updated: 2022/12/06 18:45:25 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

// void ft_putchar(int c)
// {
// 	write(1, &c, 1);
// }
// int deal_key(int key, void *win_ptr)
// {
// 	key = 55;
// 	ft_putchar('X');
// 	mlx_pixel_put(mlx_init(), win_ptr, 100, 100, 0xFFAF33);
// 	return (0);
// }

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
int main()
{
	t_map *map;
	map = malloc(sizeof(t_map));
	char *file = "file";
	int fd = open(file, O_RDONLY);
	ft_init_structure(map, fd, file);
	close(fd);
	free(map->s);
	free(map);
	return 0;
}
