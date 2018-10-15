/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:34:08 by llanga            #+#    #+#             */
/*   Updated: 2018/06/15 11:09:54 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ADD_NULL 1

static int		num_len(long n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	}
	else if (n > 0)
	{
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		n_len;
	int		hold;
	long	o;

	o = (long)n;
	hold = 0;
	res = NULL;
	n_len = num_len(n);
	if (!(res = (char*)malloc(sizeof(char) * (ADD_NULL + n_len))))
		return (NULL);
	res[n_len] = '\0';
	n_len--;
	if (o < 0)
	{
		hold = 1;
		res[0] = '-';
		o *= -1;
	}
	while (n_len >= hold)
	{
		res[n_len--] = (o % 10) + '0';
		o /= 10;
	}
	return (res);
}
