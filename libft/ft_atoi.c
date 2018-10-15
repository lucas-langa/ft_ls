/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <llanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:27:02 by llanga            #+#    #+#             */
/*   Updated: 2018/06/16 08:53:50 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define DEC_BASE 10

static int			my_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' ||\
			c == '\v' || c == '\f' || c == '\n')
		return (1);
	else
		return (0);
}

static int			num_conv(const char *str)
{
	int res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * DEC_BASE + (*str - '0');
		str++;
	}
	return (res);
}

int					ft_atoi(const char *str)
{
	int res;
	int	sign_count;
	int sign;

	sign = 1;
	res = 0;
	sign_count = 0;
	while (my_whitespace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		sign_count++;
		if (sign_count >= 2)
			return (0);
		str++;
	}
	if (*(str - 1) == '-')
		sign *= -1;
	res = num_conv(str);
	if (res < 0 && sign == 1)
		return (2147483647);
	return (res * sign);
}
