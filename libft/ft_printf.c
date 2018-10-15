/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 12:24:59 by llanga            #+#    #+#             */
/*   Updated: 2018/08/05 12:25:09 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char *format, ...)
{
	va_list va;
	size_t	l;

	l = 0;
	va_start(va, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			l += ft_fnscall(&(format), va);
		}
		else
			l += ift_putchar(*format);
		format++;
	}
	va_end(va);
	return (l);
}
