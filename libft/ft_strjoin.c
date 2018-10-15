/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:29:42 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 08:23:27 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ADD_NULL

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	res_len;

	res = NULL;
	if (s1 && s2)
	{
		res_len = (ft_strlen(s1) + ft_strlen(s2));
		if (!(res = ft_strnew(res_len)))
			return (NULL);
		res = ft_strcat(res, (char*)s1);
		res = ft_strcat(res, (char*)s2);
	}
	return (res);
}
