/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:01:16 by charles           #+#    #+#             */
/*   Updated: 2022/11/26 11:25:24 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include "libft.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include <stdlib.h>


typedef struct s_coord
{
	ssize_t i;
    ssize_t y;
	ssize_t x;

}	t_coord;

int **lets_pars(int fd);
int ft_column_count(char *str);


#endif