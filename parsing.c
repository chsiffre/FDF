/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:55 by chsiffre          #+#    #+#             */
/*   Updated: 2022/11/26 19:25:28 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line_bonus.h"
#include "ft_printf.h"
#include <stdlib.h>

void	*free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

size_t	ft_column_count(char **strs)
{
	size_t 	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void init_struct(t_coord *b)
{
	b->i = 0;
	b->y = 0;
	b->column_count = 0;
	b->line_count = 0;
	//b.strs = NULL;
	//b.line = NULL;
}

int ft_line_count(int fd, char *file)
{
	int count;
	char *line;

	line = get_next_line(fd);
	free(line);
	while(line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

int **lets_pars(int fd, char *file)
{
	t_coord b;	

	init_struct(&b);
	b.column_count = ft_line_count(fd, file);
	fd = open(file, O_RDONLY);
	b.tab = (int **) malloc(b.column_count * sizeof(int *));
	while (1)
	{
		b.i = -1;
		b.line = get_next_line(fd);
		if (!b.line)
			return (free(b.line), NULL);
		b.strs = ft_split_charset(b.line, " \n");
		b.column_count = ft_column_count(b.strs);
		b.tab[b.y] = (int*) malloc(b.column_count * sizeof(int));
		while (b.strs[++b.i])
		{
			b.tab[b.y][b.i] = ft_atoi(b.strs[b.i]);
			printf("%d ", b.tab[b.y][b.i]);
		}
		printf("\n"); 
		b.y++;
		free_tab(b.strs);
		free(b.line);
	}
	return (b.tab);
}

#include <stdio.h>

int main(int ac, char **argv)
{
	char *file = "file";
	int fd = open(file, O_RDONLY);
	int i = 0;
	int y = 0;
	int **tab = lets_pars(fd, file);
	free(tab);
	//free(tab[y]);
	// while (y <= 20)
	// {
	// 	printf("%d ", tab[y][i]);
	// 	if (i % 19 == 0 && i != 0)
	// 	{
	// 		y++;
	// 		i = -1;
	// 		write(1, "\n", 1);
	// 	}
	// 	i++;
	// }
	// return (0);
}