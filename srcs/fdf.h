/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:01:16 by charles           #+#    #+#             */
/*   Updated: 2023/02/08 19:36:42 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"

# ifndef WIN_W
#  define WIN_W 1920
# endif

# ifndef WIN_H
#  define WIN_H 1080
# endif

typedef struct s_coord
{
	ssize_t	i;
	ssize_t	y;
	ssize_t	column_count;
	ssize_t	line_count;
	int		max;
	int		min;
	int		**tab;
	char	*line;
	char	**strs;
}	t_coord;

typedef struct s_map
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	alt;
	int		high;
	int		high1;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	int		**tab;
	int		size_l;
	int		*data;
	int		bpp;
	int		endian;
	int		size;
	int		max;
	int		min;
	double	delta_x;
	double	delta_y;
	int		pixels;
	int		view;
	t_coord	*s;
}	t_map;

void	choose_view(t_map *map);
void	ft_init_var(t_map *map);
void	ft_2d(double *x, double *y, t_map *map);
int		**lets_pars(int fd, char *file, t_coord *b);
ssize_t	ft_column_count(char **str);
ssize_t	ft_line_count(int fd, char *file, t_coord *b);
void	ft_save_high_max(t_coord *b);
t_coord	*init_struct(t_coord *b);
void	*free_tab(char **tab, char *line);
void	ft_isometric(double *x, double *y, int z, t_map *map);
void	ft_print_isometric_line(t_map *map);
t_map	*ft_init_structure(t_map *map, int fd, char *file);
int		ft_setup_coord(t_map *map);
int		deal_key(int key, t_map *map);
int		ft_color(t_map *map);
int		ft_parse_arg(char *str);

#endif