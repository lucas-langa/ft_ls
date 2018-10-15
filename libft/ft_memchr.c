/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:36:27 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 08:36:35 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*src;
	unsigned char		c_hold;

	c_hold = (unsigned char)c;
	src = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == c_hold)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
