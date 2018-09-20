/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:56:09 by llanga            #+#    #+#             */
/*   Updated: 2018/09/12 12:58:41 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_list		*srt_ascii(t_dir_list *node)
{
	if (!node)
		return (NULL);
	if (node->next != NULL && ft_strcmp(node->dname, node->next->dname) > 0)
		node = swap_nptr(node, node->next);
	node->next = srt_ascii(node->next);
	if (node->next != NULL &&
	ft_strcmp(node->dname, node->next->dname) > 0)
	{
		node = swap_nptr(node, node->next);
		node->next = srt_ascii(node->next);
	}
	return (node);
}

t_dir_list		*srt_rascii(t_dir_list *node)
{
	if (!node)
		return (NULL);
	if (node->next != NULL && ft_strcmp(node->dname, node->next->dname) < 0)
		node = swap_nptr(node, node->next);
	node->next = srt_rascii(node->next);
	if (node->next != NULL &&
	ft_strcmp(node->dname, node->next->dname) < 0)
	{
		node = swap_nptr(node, node->next);
		node->next = srt_rascii(node->next);
	}
	return (node);
}

t_dir_list		*srt_mtime(t_dir_list *node)
{
	if (!node)
		return (NULL);
	if (node->next != NULL && (node->mod_time < node->next->mod_time))
		node = swap_nptr(node, node->next);
	node->next = srt_mtime(node->next);
	if (node->next != NULL && (node->mod_time < node->next->mod_time))
	{
		node = swap_nptr(node, node->next);
		node->next = srt_mtime(node->next);
	}
	return (node);
}

t_dir_list		*srt_rmtime(t_dir_list *node)
{
	if (!node)
		return (NULL);
	if (node->next != NULL && (node->mod_time > node->next->mod_time))
		node = swap_nptr(node, node->next);
	node->next = srt_rmtime(node->next);
	if (node->next != NULL && (node->mod_time > node->next->mod_time))
	{
		node = swap_nptr(node, node->next);
		node->next = srt_rmtime(node->next);
	}
	return (node);
}

t_dir_list		*sort_type(t_dir_list *dir_list, t_dir_things *x)
{
	if (!dir_list)
		return (NULL);
	if ((x->dash_t && x->dash_r && x->dash_l) || (x->dash_t && x->dash_r))
		return (dir_list = srt_rmtime(dir_list));
	if (x->dash_l && x->dash_r)
		return (dir_list = srt_rascii(dir_list));
	if (x->dash_l && x->dash_t)
		return (dir_list = srt_mtime(dir_list));
	if (x->dash_t)
		return (dir_list = srt_mtime(dir_list));
	if (x->dash_l)
		return (dir_list = srt_ascii(dir_list));
	if (x->dash_r)
		return (dir_list = srt_rascii(dir_list));
	if (x->dash_a)
		return (dir_list = srt_ascii(dir_list));
	else
		return (dir_list = srt_ascii(dir_list));
}
