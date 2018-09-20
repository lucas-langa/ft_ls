/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:16:00 by llanga            #+#    #+#             */
/*   Updated: 2018/09/04 09:16:01 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		inistruct(t_dir_things *x)
{
	x->block_size = 0;
	x->dir_name = NULL;
	x->path = NULL;
	x->dash_a = 0;
	x->dash_l = 0;
	x->dash_r = 0;
	x->dash_t = 0;
	x->n_dirs = 0;
	return ;
}

void		free_struct(t_dir_things *x)
{
	if (x->path)
		ft_strdel(&x->path);
	if (x->dir_name)
		ft_strdel(&x->dir_name);
	return ;
}
