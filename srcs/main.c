/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:22:49 by chsiffre          #+#    #+#             */
/*   Updated: 2022/11/30 18:12:51 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void ft_putchar(int c)
{
	write(1, &c, 1);
}
int deal_key(int key, void *win_ptr)
{
	key = 55;
	ft_putchar('X');
	mlx_pixel_put(mlx_init(), win_ptr, 100, 100, 0xFFAF33);
	return (0);
}

int main()
{
	t_map *map;
	map = malloc(sizeof(t_map));
	char *file = "file";
	int fd = open(file, O_RDONLY);
	ft_init_structure(map, fd, file);
	ft_print_line(map);
	mlx_loop(map->mlx_ptr);
}
