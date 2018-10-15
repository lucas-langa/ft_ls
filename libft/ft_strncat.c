/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:47:50 by lucas             #+#    #+#             */
/*   Updated: 2018/06/15 14:37:09 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len_dest;

	len_dest = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i] != '\0')
	{
		s1[len_dest++] = s2[i];
		i++;
	}
	s1[len_dest] = '\0';
	return (s1);
}
