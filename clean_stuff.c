/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:03:12 by llanga            #+#    #+#             */
/*   Updated: 2018/09/12 18:03:13 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_dir_list(t_dir_list **dlist)
{
	t_dir_list *ptr;

	ptr = NULL;
	if ((dlist && *dlist))
	{
		ptr = (*dlist);
		while (ptr)
		{
			(*dlist) = (*dlist)->next;
			ptr->next = NULL;
			ft_memdel((void*)&ptr->dname);
			ft_memdel((void*)&ptr->grpname);
			ft_memdel((void*)&ptr->rights);
			ft_memdel((void*)&ptr->usr_name);
			ft_memdel((void*)&ptr);
			ptr = (*dlist);
		}
	}
	return ;
}
