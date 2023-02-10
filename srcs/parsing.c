/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:55 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/10 11:19:49 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ssize_t	ft_line_count(int fd, char *file, t_coord *b)
{
	ssize_t	count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (count);
		}
		free(line);
		count++;
	}
	b->line_count = count;
	close(fd);
	return (count);
}

int	**lets_pars(int fd, char *file, t_coord *b)
{
	b->tab = (int **) malloc(ft_line_count(fd, file, b) * sizeof(int *));
	if (!b->tab)
		return (NULL);
	while (++b->y || 1)
	{
		b->i = -1;
		b->line = get_next_line(fd);
		if (!b->line)
			break ;
		b->strs = ft_split_charset(b->line, " \n");
		if (!b->strs)
			return (free(b->line), NULL);
		if (b->column_count != ft_column_count(b->strs) && b->column_count != 0)
			return (free_tab(b->strs, b->line), NULL);
		b->column_count = ft_column_count(b->strs);
		b->tab[b->y] = malloc(b->column_count * sizeof(int));
		if (!b->tab[b->y])
			return (free_tab(b->strs, b->line), NULL);
		while (b->strs[++b->i])
			b->tab[b->y][b->i] = ft_atoi(b->strs[b->i]);
		free_tab(b->strs, b->line);
	}
	b->line_count = ft_line_count(fd, file, b);
	ft_save_high_max(b);
	return (b->tab);
}

void	ft_save_high_max(t_coord *b)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	b->max = 0;
	b->min = 0;
	while (y < b->line_count)
	{
		x = 0;
		while (x + 1 < b->column_count)
		{
			if (b->tab[y][x] > b->max)
				b->max = b->tab[y][x + 1];
			if (b->tab[y][x] <= b->min)
				b->min = b->tab[y][x];
			x++;
		}
		y++;
	}
}
