/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:01:16 by charles           #+#    #+#             */
/*   Updated: 2022/11/26 18:59:53 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# include <stdlib.h>


typedef struct s_coord
{
	size_t i;
    size_t y;
	int		column_count;
	int		line_count;
	int 	**tab;
	char 	*line;
	char	**strs;

}	t_coord;

int 	**lets_pars(int fd, char *file);
size_t	ft_column_count(char **str);
void	init_struct(t_coord *b);
void	*free_tab(char **tab);

#endif