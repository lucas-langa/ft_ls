/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnscall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 10:34:29 by llanga            #+#    #+#             */
/*   Updated: 2018/08/05 12:24:09 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	list_fill(t_flist *lst)
{
	lst->flags = ft_strdup(" *****");
	lst->width = -1;
	lst->prcsn = -1;
	lst->hh = 0;
	lst->h = 0;
	lst->ll = 0;
	lst->l = 0;
	lst->j = 0;
	lst->z = 0;
}

static	void	ft_flager(char **form01, t_flist *lst)
{
	if (**form01 == '-')
		(lst->flags)[1] = '-';
	else if (**form01 == '0')
		(lst->flags)[2] = '0';
	else if (**form01 == '+')
		(lst->flags)[3] = '+';
	else if (**form01 == ' ')
		(lst->flags)[4] = ' ';
	else if (**form01 == '#')
		(lst->flags)[5] = '#';
}

static	char	ft_dflager(char *form10, char c)
{
	int			r;

	r = 0;
	while (ft_strchrf("-0+ #.123456789hjlz", *form10))
	{
		if (*form10 == c)
			r++;
		form10++;
	}
	if (r % 2 == 0)
		return (1);
	return (0);
}

static	void	ft_modifier(char **form11, t_flist *lst)
{
	if (**form11 == 'h' && lst->h == 0 && lst->hh == 0)
	{
		if (ft_dflager(*form11, 'h'))
			lst->hh = 1;
		else
			lst->h = 1;
	}
	if (**form11 == 'j' && lst->j == 0)
		lst->j = 1;
	if (**form11 == 'l' && lst->l == 0 && lst->ll == 0)
	{
		if (ft_dflager(*form11, 'l'))
			lst->ll = 1;
		else
			lst->l = 1;
	}
	if (**form11 == 'z' && lst->z == 0)
		lst->z = 1;
}

int				ft_fnscall(char **input, va_list va)
{
	t_flist		lst;

	list_fill(&lst);
	while (ft_strchrf("-0+ #.123456789hjlz", **input))
	{
		(ft_strchrf("-0+ #", **input)) ? ft_flager(input, &lst) : 0;
		if (ft_strchrf("123456789", **input))
		{
			lst.width = ft_atoif(input);
			continue ;
		}
		if (**input == '.' && (*input)++)
		{
			lst.prcsn = ft_atoif(input);
			continue ;
		}
		(ft_strchrf("hjlz", **input)) ? ft_modifier(input, &lst) : 0;
		(*input)++;
	}
	if (ft_strchrf("sSpdDioOuUxXcC", **input) != 0)
		lst.specifier = **input;
	else
		lst.specifier = **input;
	return (ft_output(&lst, va));
}
