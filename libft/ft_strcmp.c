/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:57:34 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 17:12:51 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*f1;
	unsigned char	*f2;

	f1 = (unsigned char*)s1;
	f2 = (unsigned char*)s2;
	i = 0;
	while ((f1[i] == f2[i]) && (f1[i] != '\0') && (f2[i] != '\0'))
		i++;
	return (f1[i] - f2[i]);
}
