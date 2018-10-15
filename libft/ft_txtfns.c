/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txtfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 10:37:19 by llanga            #+#    #+#             */
/*   Updated: 2018/08/05 12:25:45 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ift_putchar(char chr)
{
	write(1, &chr, 1);
	return (1);
}

int		ift_putstr(char *str, int prcsn)
{
	int	l;

	l = 0;
	if (str == NULL)
		return (ift_putstr("(null)", prcsn));
	while (*str != '\0' && prcsn--)
		l += ift_putchar(*str) && str++;
	return (l);
}

int		ft_putprcnt(t_flist *lst, char p)
{
	int	l;

	l = 0;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	if ((lst->flags)[1] != '-' && lst->width > 1)
	{
		while (((lst->width)-- - 1))
			l += ift_putchar((lst->flags)[0]);
		l += ift_putchar(p);
	}
	else if (lst->width > 1 && (lst->flags)[1] == '-')
	{
		l += ift_putchar(p);
		while ((lst->width)-- - 1)
			l += ift_putchar(' ');
	}
	else
		l += ift_putchar(p);
	return (l);
}

int		ft_chrhandle(t_flist *lst, void *c)
{
	int	l;

	l = 0;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	if ((lst->flags)[1] != '-' && lst->width > 1)
		while (((lst->width)-- - 1))
			l += ift_putchar((lst->flags)[0]);
	if (lst->specifier == 'c' && !lst->l)
		l += ift_putchar((int)c);
	else if (lst->specifier == 'C' || (lst->specifier == 'c' && lst->l))
		l += ift_putchar((int)c);
	else
		l += ift_putchar(lst->specifier);
	if (lst->width > 1 && (lst->flags)[1] == '-')
		while ((lst->width)-- - 1)
			l += ift_putchar(' ');
	return (l);
}

int		ft_strhandle(t_flist *lst, void *s)
{
	int	l;

	lst->size = (s != NULL) ? ft_strlen((char *)s) : 6;
	l = 0;
	lst->size = !lst->prcsn ? lst->width : lst->size;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	while ((lst->flags)[1] != '-' && lst->width > lst->size)
		l += ift_putchar((lst->flags)[0]) && (lst->width)--;
	while ((lst->flags)[1] != '-' && lst->width > lst->prcsn &&
	lst->prcsn != -1 && (lst->size > lst->prcsn))
		l += ift_putchar((lst->flags)[0]) && (lst->width)--;
	if (lst->specifier == 's' && !lst->l)
		l += ift_putstr((char *)s, lst->prcsn);
	else if (lst->specifier == 'S' || (lst->specifier == 's' && lst->l))
		l += ft_putwstr((wchar_t *)s, lst->prcsn);
	while ((lst->flags)[1] == '-' && lst->width > lst->size)
		l += ift_putchar(' ') && lst->width--;
	while ((lst->flags)[1] != '-' && lst->width > lst->prcsn &&
	lst->prcsn != -1 && (lst->size - lst->prcsn))
		l += ift_putchar(' ') && lst->size--;
	return (l);
}
