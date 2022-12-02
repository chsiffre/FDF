/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:01:16 by charles           #+#    #+#             */
/*   Updated: 2022/12/02 15:09:04 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_coord
{
	ssize_t	i;
    ssize_t	y;
	ssize_t	column_count;
	ssize_t	line_count;
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
	t_coord *s;
}	t_map;

int 	**lets_pars(int fd, char *file, t_coord *b);
ssize_t	ft_column_count(char **str);
ssize_t	ft_line_count(int fd, char *file, t_coord *b);
t_coord	*init_struct(t_coord *b);
void	*free_tab(char **tab, char *line);
void	ft_print_line(t_map *map);
void 	ft_init_structure(t_map *map, int fd, char *file);
void	ft_setup_coord(t_map *map);

#endif