/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:49:31 by llanga            #+#    #+#             */
/*   Updated: 2018/06/08 12:00:47 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n_compare(const char *s1, const char *s2,\
									int s1_dex, size_t len)
{
	int i;

	i = 0;
	while ((s1[s1_dex] == s2[i]) && s1[s1_dex] && s2[i] && s1_dex != (int)len)
	{
		i++;
		s1_dex++;
	}
	if (s2[i] == '\0')
		return (1);
	return (0);
}

char			*ft_strnstr(const char *haystack,\
					const char *needle, size_t len)
{
	size_t	i;
	char	*temp;

	temp = (char*)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (temp);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (n_compare(haystack, needle, i, len))
				return (&temp[i]);
		}
		i++;
	}
	return (NULL);
}
