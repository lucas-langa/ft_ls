/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 10:35:45 by llanga            #+#    #+#             */
/*   Updated: 2018/08/05 11:39:49 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_atoif(char **str1)
{
	int			r;
	int			i;
	int			s;

	r = 0;
	i = 0;
	s = 1;
	while ('0' <= (*str1)[i] && (*str1)[i] <= '9')
	{
		r = r * 10 + (*str1)[i] - '0';
		i++;
	}
	(*str1) = &(*str1)[i];
	return (r * s);
}

char		ft_strchrf(char *str0, int form00)
{
	char		*tmp;

	tmp = str0;
	while (*tmp != '\0')
	{
		if (*tmp == form00)
			return (1);
		tmp++;
	}
	if (*tmp == '\0' && form00 == '\0')
		return (0);
	return (0);
}
