/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 11:33:20 by llanga            #+#    #+#             */
/*   Updated: 2018/08/05 11:33:29 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_unssizer(intmax_t digit)
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

static	char	ft_unslen(t_flist *lst, intmax_t digit)
{
	char		r;
	char		t;

	r = ft_unssizer(digit);
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
	return (r);
}

static	char	ft_putuns(uintmax_t digit, t_flist *lst)
{
	char		l;

	l = 0;
	if (digit >= 10)
	{
		l += ft_putuns(digit / 10, lst);
		l += ift_putchar((digit % 10) + '0');
	}
	else
		l += ift_putchar(digit + '0');
	return (l);
}

static	short	ft_pre_unshandle(t_flist *lst, uintmax_t digit)
{
	short		l;

	l = 0;
	if ((lst->flags)[2] == '0' && lst->prcsn == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_unslen(lst, digit);
	while ((lst->flags)[1] != '-' && lst->width > (lst->size))
		(l += ift_putchar((lst->flags)[0])) && lst->width--;
	while (lst->prcsn != -1 && lst->prcsn > 0)
		(l += ift_putchar('0')) && lst->prcsn--;
	l += ft_putuns(digit, lst);
	while (lst->width > lst->size && (lst->flags)[1] == '-')
		(l += ift_putchar(' ')) && lst->width--;
	return (l);
}

int				ft_unshandle(t_flist *lst, void *n01)
{
	if (lst->specifier == 'U')
		return (ft_pre_unshandle(lst, (unsigned long)n01));
	else if (lst->j)
		return (ft_pre_unshandle(lst, (uintmax_t)n01));
	else if (lst->ll)
		return (ft_pre_unshandle(lst, (unsigned long long)n01));
	else if (lst->z)
		return (ft_pre_unshandle(lst, (size_t)n01));
	else if (lst->l)
		return (ft_pre_unshandle(lst, (unsigned long)n01));
	else if (lst->h)
		return (ft_pre_unshandle(lst, (unsigned short)n01));
	else if (lst->hh)
		return (ft_pre_unshandle(lst, (unsigned char)n01));
	else
		return (ft_pre_unshandle(lst, (unsigned int)n01));
}
