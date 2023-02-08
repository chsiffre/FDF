/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:54:04 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/08 19:34:42 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_coord	*init_struct(t_coord *b)
{
	b->i = 0;
	b->y = 0;
	b->column_count = 0;
	b->line_count = 0;
	return (b);
}
