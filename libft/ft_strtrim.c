/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 10:45:52 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 11:27:07 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sum_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s)
	{
		j = ft_strlen(s);
		while (sum_whitespace(s[i]))
			i++;
		while (sum_whitespace(s[j - 1]))
			j--;
		if (j == 0)
			return (ft_strdup(""));
	}
	return (ft_strsub((char*)s, i, (j - i)));
}
