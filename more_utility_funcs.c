/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utility_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:51:19 by llanga            #+#    #+#             */
/*   Updated: 2018/09/17 15:51:20 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		str_dumps(t_dir_list *node, char *rights, char *uname, char *gname)
{
	node->rights = rights;
	node->usr_name = uname;
	node->grpname = gname;
	return ;
}

int			adir(const char *name)
{
	struct stat buf;

	if (stat(name, &buf) != 0)
		return (0);
	return (S_ISDIR(buf.st_mode));
}

void		lb_data_in(t_dir_things *x, t_dir_list *node)
{
	int i;

	i = 0;
	x->block_size += !x->dash_a && node->dname[0] == '.' ? i : x->buf.st_blocks;
	node->links = x->buf.st_nlink;
	node->fsize = x->buf.st_size;
	(x->pwd) = getpwuid(x->buf.st_uid);
	(x->grp) = getgrgid(x->buf.st_gid);
}

int			erro_kill(struct passwd *pwd)
{
	if (!pwd)
	{
		printf("I'm not allowed to access this file/folder\n");
		return (1);
	}
	else
		return (0);
}
