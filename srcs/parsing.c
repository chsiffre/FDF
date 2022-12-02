/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:55 by chsiffre          #+#    #+#             */
/*   Updated: 2022/12/02 15:16:08 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	*free_tab(char **tab, char *line)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	free(line);
	return (0);
}

ssize_t	ft_column_count(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

t_coord	*init_struct(t_coord *b)
{
	b->i = 0;
	b->y = 0;
	b->column_count = 0;
	b->line_count = 0;
	return (b);
}

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
	while (1)
	{
		b->i = -1;
		b->line = get_next_line(fd);
		if (!b->line)
			break ;
		b->strs = ft_split_charset(b->line, " \n");
		if (b->column_count != ft_column_count(b->strs) && b->column_count != 0)
			return (free_tab(b->strs, b->line), NULL);
		b->column_count = ft_column_count(b->strs);
		b->tab[b->y] = malloc(b->column_count * sizeof(int));
		if (!b->tab[b->y])
			return (free_tab(b->strs, b->line), NULL);
		while (b->strs[++b->i])
			b->tab[b->y][b->i] = ft_atoi(b->strs[b->i]);
		b->y++;
		free_tab(b->strs, b->line);
	}
	b->line_count = ft_line_count(fd, file, b);
	return (b->tab);
}

// int main(int ac, char **argv)
// {
// 	char *file = "file";
// 	int fd = open(file, O_RDONLY);
// 	int i = 0;
// 	int y = 0;
// 	int **tab = lets_pars(fd, file);
// 	close(fd);
// 	while (y < )
// 	while (y < 20)
// 	{
// 	 	free(tab[y]);
// 		y++;
// 	}
// 	free(tab);
// 	return (0);
// }
