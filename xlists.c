/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlists.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:10:48 by llanga            #+#    #+#             */
/*   Updated: 2018/09/17 16:10:51 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_list		*fx_lstnew(char *dname, time_t mod_time)
{
	t_dir_list *node;

	node = NULL;
	if (!(node = (t_dir_list*)malloc(sizeof(t_dir_list))))
		return (NULL);
	if (!dname)
	{
		node->dname = NULL;
		node->mod_time = 0;
		node->next = NULL;
		return (node);
	}
	else
	{
		node->dname = ft_strnew(ft_strlen(dname));
		ft_strcpy(node->dname, dname);
		node->mod_time = mod_time;
		node->next = NULL;
		return (node);
	}
}

void			fx_lstadd(t_dir_list **node, t_dir_list *new)
{
	new->next = (*node);
	(*node) = new;
	return ;
}

t_dir_list		*swap_nptr(t_dir_list *node, t_dir_list *node2)
{
	node->next = node2->next;
	node2->next = node;
	return (node2);
}
