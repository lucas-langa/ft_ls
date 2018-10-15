/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:38:09 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 11:34:48 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ADD_NULL 1
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*res;

	res = NULL;
	if (s)
	{
		i = 0;
		res = ft_memalloc(len + ADD_NULL);
		if (res == NULL)
			return (res);
		ft_bzero(res, (ADD_NULL + len));
		while (i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		return (res);
	}
	return (NULL);
}
