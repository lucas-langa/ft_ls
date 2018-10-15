/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgtfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 11:30:20 by llanga            #+#    #+#             */
/*   Updated: 2018/08/06 14:02:39 by llanga	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_dgtsizer(intmax_t digit)
{
	char		size;

	size = 1;
	digit /= 10;
	while (digit)
	{
		digit /= 10;
		size++;
	}
	return (size);
}

static	char	ft_dgtlen(t_flist *lst, intmax_t digit)
{
	char		r;
	char		t;

	r = ft_dgtsizer(digit);
	t = 0;
	if (lst->prcsn != -1 && lst->prcsn > r)
	{
		t = lst->prcsn - r;
		r = lst->prcsn;
	}
	if (t > 0)
		lst->prcsn = t;
	else if (digit == 0 && lst->prcsn == 0)
	{
		lst->prcsn = -2;
		r = 0;
	}
	else
		lst->prcsn = -1;
	if ((digit < 0) || (((lst->flags)[3] == '+' || (lst->flags)[4] == ' ') &&
	digit >= 0))
		r++;
	return (r);
}

static	char	ft_putdgt(intmax_t digit, t_flist *lst)
{
	char		l;

	l = 0;
	if (digit == 0 && lst->prcsn == -2)
		return (0);
	if (-10 < digit && digit < 10)
		l += ift_putchar(ABS(digit) + '0');
	else
	{
		l += ft_putdgt(digit / 10, lst);
		l += ft_putdgt(digit % 10, lst);
	}
	return (l);
}

static	short	ft_pre_dgthandle(t_flist *lst, intmax_t digit, int *l)
{
	if ((lst->flags)[2] == '0' && lst->prcsn == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_dgtlen(lst, digit);
	if (digit < 0 && lst->flags[0] == '0')
		*l += ift_putchar('-');
	else if (digit >= 0 && lst->flags[0] == '0' && lst->flags[3] == '+')
		*l += ift_putchar('+');
	else if (lst->flags[0] == '0' && lst->flags[4] == ' ')
		*l += ift_putchar(' ');
	while ((lst->flags)[1] != '-' && lst->width > (lst->size))
		(*l += ift_putchar((lst->flags)[0])) && lst->width--;
	if ((lst->flags)[3] == '+' && digit >= 0 && lst->flags[0] != '0')
		*l += ift_putchar('+');
	else if (digit < 0 && lst->flags[0] == ' ' && lst->flags[0] != '0')
		*l += ift_putchar('-');
	else if ((lst->flags)[4] == ' ' && digit >= 0 && lst->flags[0] != '0')
		*l += ift_putchar(' ');
	while (lst->prcsn != -1 && lst->prcsn > 0)
		(*l += ift_putchar('0')) && lst->prcsn--;
	*l += ft_putdgt(digit, lst);
	while (lst->width > lst->size && (lst->flags)[1] == '-')
		(*l += ift_putchar(' ')) && lst->width--;
	return (*l);
}

int				ft_dgthandle(t_flist *lst, void *n00)
{
	int			l;

	l = 0;
	if (lst->specifier == 'D')
		(ft_pre_dgthandle(lst, (long)n00, &l));
	else if (lst->j)
		(ft_pre_dgthandle(lst, (intmax_t)n00, &l));
	else if (lst->ll)
		(ft_pre_dgthandle(lst, (long long)n00, &l));
	else if (lst->z)
		(ft_pre_dgthandle(lst, (size_t)n00, &l));
	else if (lst->l)
		(ft_pre_dgthandle(lst, (long)n00, &l));
	else if (lst->h)
		(ft_pre_dgthandle(lst, (short)n00, &l));
	else if (lst->hh)
		(ft_pre_dgthandle(lst, (char)n00, &l));
	else
		(ft_pre_dgthandle(lst, (int)n00, &l));
	return (l);
}
