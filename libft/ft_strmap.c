/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:01:43 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 09:45:04 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	s_len;
	char	*f_s;

	if (s)
	{
		i = 0;
		s_len = ft_strlen(s);
		if (!(f_s = ft_strnew(s_len)))
			return (NULL);
		while (i < s_len)
		{
			f_s[i] = f((char)s[i]);
			i++;
		}
		return (f_s);
	}
	return (NULL);
}
