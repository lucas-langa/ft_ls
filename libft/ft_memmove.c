/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:03:10 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 08:40:03 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst > src)
	{
		while (len)
		{
			*((char*)dst + (len - 1)) = *((char*)src + (len - 1));
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			*((char*)dst + i) = *((char*)src + i);
			i++;
		}
	}
	return (dst);
}
