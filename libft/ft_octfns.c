/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 11:32:49 by llanga            #+#    #+#             */
/*   Updated: 2018/08/06 13:55:39 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_octsizer(intmax_t digit)
{
	char		size;

	size = 1;
	digit /= 8;
	while (digit)
	{
		digit /= 8;
		size++;
	}
	return (size);
}

static	char	ft_octlen(t_flist *lst, intmax_t digit)
{
	char		r;
	char		t;

	r = ft_octsizer(digit);
	t = 0;
	if (lst->prcsn != -1 && lst->prcsn > r)
	{
		t = (lst->prcsn - r);
		r = lst->prcsn;
	}
	if (lst->flags[5] == '#' && digit != 0)
		r += 1;
	if (t > 0)
		lst->prcsn = t;
	else if (digit == 0 && lst->prcsn == 0 && lst->flags[5] != '#')
	{
		lst->prcsn = -2;
		r = 0;
	}
	else
		lst->prcsn = -1;
	return (r);
}

static	char	ft_putoct(uintmax_t digit, t_flist *lst, char *base)
{
	char		l;

	l = 0;
	if (digit == 0 && lst->prcsn == -2)
		return (0);
	if (digit >= 8)
	{
		l += ft_putoct(digit / 8, lst, base);
		l += ift_putchar(base[digit % 8]);
	}
	else
		l += ift_putchar(base[digit % 8]);
	return (l);
}

static	short	ft_pre_octhandle(t_flist *lst, uintmax_t digit)
{
	short		l;

	l = 0;
	if ((lst->flags)[2] == '0' && lst->prcsn == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_octlen(lst, digit);
	if (lst->flags[0] == '0' && lst->flags[5] == '#' && digit != 0)
		l += ift_putchar('0');
	while ((lst->flags)[1] != '-' && lst->width > (lst->size))
		(l += ift_putchar((lst->flags)[0])) && lst->width--;
	if (lst->flags[0] == ' ' && lst->flags[5] == '#' && digit != 0)
		l += ift_putchar('0');
	while (lst->prcsn != -1 && lst->prcsn > 0)
		(l += ift_putchar('0')) && lst->prcsn--;
	l += ft_putoct(digit, lst, "01234567");
	while (lst->width > lst->size && (lst->flags)[1] == '-')
		(l += ift_putchar(' ')) && lst->width--;
	return (l);
}

int				ft_octhandle(t_flist *lst, void *n10)
{
	if (lst->specifier == 'O')
		return (ft_pre_octhandle(lst, (unsigned long)n10));
	else if (lst->j)
		return (ft_pre_octhandle(lst, (uintmax_t)n10));
	else if (lst->ll)
		return (ft_pre_octhandle(lst, (unsigned long long)n10));
	else if (lst->z)
		return (ft_pre_octhandle(lst, (size_t)n10));
	else if (lst->l)
		return (ft_pre_octhandle(lst, (unsigned long)n10));
	else if (lst->h)
		return (ft_pre_octhandle(lst, (unsigned short)n10));
	else if (lst->hh)
		return (ft_pre_octhandle(lst, (unsigned char)n10));
	else
		return (ft_pre_octhandle(lst, (unsigned int)n10));
}
