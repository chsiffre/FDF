/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:22:49 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/09 12:53:23 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (ac != 2)
		return (0);
	if (ft_parse_arg(av[1]))
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	map = ft_init_structure(map, fd, av[1]);
	if (!map)
		return (0);
	close(fd);
	return (0);
}

void	choose_view(t_map *map)
{
	if (map->view == 0)
	{
		ft_isometric(&map->x1, &map->y1, map->high, map);
		ft_isometric(&map->x2, &map->y2, map->high1, map);
	}
	else if (map->view == 1)
	{
		ft_2d(&map->x1, &map->y1, map);
		ft_2d(&map->x2, &map->y2, map);
	}
}

int	ft_color(t_map *map)
{
	int	x;

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
