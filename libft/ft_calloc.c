/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:17:52 by charles           #+#    #+#             */
/*   Updated: 2022/11/14 10:55:56 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;

	if (count == 0 || size == 0)
		return (malloc(0));
	if ((SIZE_MAX / size < count))
		return (NULL);
	dest = malloc((count * size));
	if (!dest)
		return (NULL);
	ft_bzero(dest, (size * count));
	return (dest);
}
