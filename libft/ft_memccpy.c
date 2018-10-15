/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:45:28 by llanga            #+#    #+#             */
/*   Updated: 2018/06/14 13:46:18 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;

	d = (unsigned char*)dst;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		d[i] = *((unsigned char*)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
			return (&d[i + 1]);
		if (i > n)
			return (0);
		i++;
	}
	return (NULL);
}
