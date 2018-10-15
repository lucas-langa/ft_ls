/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:31:59 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 16:16:09 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_dst;
	size_t src_len;

	src_len = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (len_dst > dstsize)
		return (dstsize + src_len);
	if (len_dst < dstsize)
		ft_strncat((dst + len_dst), src, (dstsize - len_dst - 1));
	return (len_dst + src_len);
}
