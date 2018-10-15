/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:36:57 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 08:37:01 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*ss1;
	unsigned char		*ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	i = 0;
	while ((i < n))
	{
		if ((ss1[i] > ss2[i]) || (ss2[i] > ss1[i]))
			return (ss1[i] - ss2[i]);
		i++;
		if (i == n)
			break ;
	}
	return (0);
}
