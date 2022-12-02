/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:01:16 by charles           #+#    #+#             */
/*   Updated: 2022/11/30 18:10:10 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_coord
{
	size_t 	i;
    size_t 	y;
	size_t	column_count;
	int 	**tab;
	char 	*line;
	char	**strs;

}	t_coord;

typedef struct s_map
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	void	*mlx_ptr;
	void	*win_ptr;
	int		**tab;
}	t_map;

int 	**lets_pars(int fd, char *file);
size_t	ft_column_count(char **str);
void	init_struct(t_coord *b);
void	*free_tab(char **tab, char *line);
void	ft_print_line(t_map *map);
void 	ft_init_structure(t_map *map, int fd, char *file);

#endif