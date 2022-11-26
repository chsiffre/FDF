/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:55 by chsiffre          #+#    #+#             */
/*   Updated: 2022/11/26 12:05:21 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*free_tab(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

int ft_column_count(char *str)
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
	int		**tab;
	int		column_count;
	size_t	y;
	size_t	i;
	
	y = 0;
	column_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		if (column_count != ft_column_count(line) && column_count != 0)
			return (0);
		column_count = ft_column_count(line);
		strs = ft_split_charset(line, " \n");
		tab[y] = malloc(column_count * sizeof(int));
		while (strs[++i])
			tab[y][i] = ft_atoi(strs[i]);
		y++;
		free_tab(strs);
		free(line);
	}
	return (tab);
}

#include <stdio.h>

int main()
{
	int fd = open("file", O_RDONLY);
	int i = 0;
	int y = 0;
	int **tab = lets_pars(fd);
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
	return (0);
}