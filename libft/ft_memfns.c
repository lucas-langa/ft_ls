/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:13:55 by llanga            #+#    #+#             */
/*   Updated: 2018/08/13 12:14:10 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*vdst;
	const unsigned char *vsrc;

	vdst = dst;
	vsrc = src;
	i = 0;
	while (i < n)
	{
		vdst[i] = vsrc[i];
		i++;
	}
	return (dst);
}
