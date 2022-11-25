/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:55 by chsiffre          #+#    #+#             */
/*   Updated: 2022/11/25 16:50:13 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"
#include "ft_printf.h"


void	*free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

int ft_line_count(char *str)
{
	size_t 	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count + 1);
}

int **lets_pars(int fd)
{
	char 	**strs;
	char 	*line;
	char 	*total_file;
	int		**tab;
	ssize_t	i;
	ssize_t	y;
	ssize_t 	x;
	int 	line_count;
	int		column_count;

	x = 0;
	i = 0;
	y = -1;
	column_count = 0;
	line_count = 0;
	//column_count = ft_line_count(line);
	while (get_next_line(fd))
	{
		total_file = ft_strjoin_2(total_file, line);
		line = get_next_line(fd);
		line_count++;
	}
	strs = ft_split_charset(total_file, " \n");
	while (++y < line_count)
		tab[y] = malloc(column_count * sizeof(int));
	y = 0;
	while (strs[x])
	{
		tab[y][i] = ft_atoi(strs[x]);
		ft_printf("%d ", tab[y][i]);
		if (i % (column_count - 1) == 0 && i > 0)
		{
			y++;
			write(1, "\n", 1);
			i = -1;
		}
		i++;
		x++;
	}
	free(total_file);
	free_tab(strs);
	return (tab);
}

#include <stdio.h>

int main()
{
	int fd = open("file", O_RDONLY);
	int i = 0;
	int y = 0;
	int **tab = lets_pars(fd);
	return (0);
}