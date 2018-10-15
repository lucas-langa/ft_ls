/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 11:30:39 by llanga            #+#    #+#             */
/*   Updated: 2018/08/05 11:36:05 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_hexsizer(intmax_t digit)
{
	char		size;

	size = 1;
	digit /= 16;
	while (digit)
	{
		digit /= 16;
		size++;
	}
	return (size);
}

static	char	ft_hexlen(t_flist *lst, intmax_t digit)
{
	char		t;
	char		r;

	t = 0;
	r = ft_hexsizer(digit);
	if (lst->prcsn != -1 && lst->prcsn > r)
	{
		t = (lst->prcsn - r);
		r = lst->prcsn;
	}
	if (lst->flags[5] == '#' && digit != 0)
		r += 2;
	if (t > 0)
		lst->prcsn = t;
	else if (digit == 0 && lst->prcsn == 0)
	{
		lst->prcsn = -2;
		r = 0;
	}
	else
		lst->prcsn = -1;
	return (r);
}

static	char	ft_puthex(uintmax_t digit, t_flist *lst, char *base)
{
	char		l;

	l = 0;
	if (digit == 0 && lst->prcsn == -2)
		return (0);
	if (digit >= 16)
	{
		l += ft_puthex(digit / 16, lst, base);
		l += ift_putchar(base[digit % 16]);
	}
	else
		l += ift_putchar(base[digit % 16]);
	return (l);
}

static	short	ft_pre_hexhandle(t_flist *lst, uintmax_t digit)
{
	short		l;

	l = 0;
	if ((lst->flags)[2] == '0' && lst->prcsn == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_hexlen(lst, digit);
	if (lst->flags[0] == '0' && lst->flags[5] == '#' && digit != 0)
		l += (lst->specifier == 'X') ? (ift_putstr("0X", -1)) :
		(ift_putstr("0x", -1));
	while ((lst->flags)[1] != '-' && lst->width > (lst->size))
		(l += ift_putchar((lst->flags)[0])) && lst->width--;
	if ((lst->flags[0] == ' ' && lst->flags[5] == '#' && digit != 0))
		l += (lst->specifier == 'X') ? (ift_putstr("0X", -1)) :
		(ift_putstr("0x", -1));
	while (lst->prcsn != -1 && lst->prcsn > 0)
		(l += ift_putchar('0')) && lst->prcsn--;
	l += (lst->specifier == 'X') ? ft_puthex(digit, lst, "0123456789ABCDEF") :
	ft_puthex(digit, lst, "0123456789abcdef");
	while (lst->width > lst->size && (lst->flags)[1] == '-')
		(l += ift_putchar(' ')) && lst->width--;
	return (l);
}

int				ft_hexhandle(t_flist *lst, void *n11)
{
	if (lst->j)
		return (ft_pre_hexhandle(lst, (uintmax_t)n11));
	else if (lst->ll)
		return (ft_pre_hexhandle(lst, (unsigned long long)n11));
	else if (lst->z)
		return (ft_pre_hexhandle(lst, (size_t)n11));
	else if (lst->l)
		return (ft_pre_hexhandle(lst, (unsigned long)n11));
	else if (lst->h)
		return (ft_pre_hexhandle(lst, (unsigned short)n11));
	else if (lst->hh)
		return (ft_pre_hexhandle(lst, (unsigned char)n11));
	else
		return (ft_pre_hexhandle(lst, (unsigned int)n11));
}
