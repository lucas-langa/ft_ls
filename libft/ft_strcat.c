/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:35:02 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 15:39:17 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t dest_len;

	dest_len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[dest_len] = s2[i];
		dest_len++;
		i++;
	}
	s1[dest_len] = '\0';
	return (s1);
}
