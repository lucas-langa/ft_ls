/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:14:07 by llanga            #+#    #+#             */
/*   Updated: 2018/09/17 15:14:09 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		fx_lstiter(t_dir_list *node, t_dir_things *x,
				void (*display)(t_dir_list *node, t_dir_things *x))
{
	t_dir_list *ptr;

	if (!node)
		return ;
	ptr = node;
	(x->dash_l && x->dir) ? printf("total %ld\n", x->block_size) : 0;
	while (ptr)
	{
		if (!(x->dash_a) && ptr->dname[0] == '.')
		{
			ptr = ptr->next;
			continue;
		}
		display(ptr, x);
		ptr = ptr->next;
	}
	return ;
}

void		displaydata(t_dir_list *dir_list, t_dir_things *x)
{
	char *temp;

	temp = NULL;
	if (x->dash_l && (x->dash_a || x->dash_r || x->dash_t))
	{
		temp = ft_strsub(ctime(&dir_list->mod_time), 4, 12);
		printf("%s %4lu %-8s %-8s %8ld %.12s %s\n", dir_list->rights,
				dir_list->links, dir_list->usr_name, dir_list->grpname,
				dir_list->fsize, temp, dir_list->dname);
		ft_strdel(&temp);
	}
	else if (x->dash_l)
	{
		temp = ft_strsub(ctime(&dir_list->mod_time), 4, 12);
		printf("%s %4lu %-8s %-8s %8ld %.12s %s\n", dir_list->rights,
				dir_list->links, dir_list->usr_name, dir_list->grpname,
				dir_list->fsize, temp, dir_list->dname);
		ft_strdel(&temp);
	}
	else if (x->dash_a || x->dash_r || x->dash_t)
		printf("%s\n", dir_list->dname);
	else
		printf("%s\n", dir_list->dname);
	return ;
}

void		do_something(t_dir_things *x, t_dir_list *dir_list,
						t_dirname *node, char *path)
{
	t_dirname *ptr;

	ptr = node;
	if (!ptr)
	{
		dir_list = read_dir(path ? path : ".", x);
		dir_list = sort_type(dir_list, x);
		fx_lstiter(dir_list, x, &displaydata);
		free_dir_list(&dir_list);
	}
	else
	{
		while (ptr != NULL)
		{
			dir_list = read_dir(ptr->name, x);
			dir_list = sort_type(dir_list, x);
			x->dir && ((x->n_dirs) >= 2) ? printf("%s:\n", ptr->name) : 0;
			fx_lstiter(dir_list, x, &displaydata);
			free_dir_list(&dir_list);
			x->block_size = 0;
			ptr = ptr->next;
		}
	}
	return ;
}
