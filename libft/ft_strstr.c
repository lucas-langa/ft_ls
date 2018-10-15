/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:07:24 by llanga            #+#    #+#             */
/*   Updated: 2018/06/06 08:53:13 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n_compare(const char *s1, const char *s2, int s1_dex)
{
	int i;

	i = 0;
	while ((s1[s1_dex] == s2[i]) && s1[s1_dex] && s2[i])
	{
		i++;
		s1_dex++;
	}
	if (s2[i] == '\0')
		return (1);
	return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*temp;

	temp = (char*)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (temp);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (n_compare(haystack, needle, i) == 1)
				return (&temp[i]);
		}
		i++;
	}
	return (NULL);
}
