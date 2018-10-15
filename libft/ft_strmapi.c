/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:46:45 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 08:50:00 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*f_s;

	f_s = NULL;
	if (s)
	{
		i = 0;
		s_len = ft_strlen(s);
		if (!(f_s = (char*)malloc((1 + s_len) * sizeof(char))))
			return (NULL);
		while (i < s_len)
		{
			f_s[i] = f(i, s[i]);
			i++;
		}
		f_s[i] = '\0';
	}
	return (f_s);
}
