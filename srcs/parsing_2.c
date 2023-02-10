/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:54:04 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/10 11:20:49 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	ft_parse_arg(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i--] != 'f')
		return (1);
	if (str[i--] != 'd')
		return (1);
	if (str[i--] != 'f')
		return (1);
	if (str[i--] != '.')
		return (1);
	return (0);
}

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
