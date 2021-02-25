/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:53:12 by llanga            #+#    #+#             */
/*   Updated: 2018/09/09 17:54:26 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_list		*read_dir(char *dirname, t_dir_things *x)
{
	t_dir_list		*node;
	t_dir_list		*head;
	struct dirent	*p;
	char			*temp;

	adir(dirname) ? x->path = ft_strjoin(dirname, "/") : 0;
	head = NULL;
	temp = NULL;
	if ((x->dir = opendir(dirname)))
		while ((p = readdir(x->dir)) != NULL)
		{
			lstat((temp = ft_strjoin(x->path, p->d_name)), &x->buf);
			node = fx_lstnew(p->d_name, (x->buf.st_mtime));
			lb_data_in(x, node);
			erro_kill((x->pwd)) ? exit(0) : str_dumps(node,
				set_rights(x->buf.st_mode),
					ft_strdup(x->pwd->pw_name), ft_strdup(x->grp->gr_name));
			fx_lstadd(&head, node);
			ft_strdel(&temp);
		}
	else
		node = check_file(dirname, x);
	!x->dir ? 0 : closedir(x->dir);
	x->path ? ft_strdel(&x->path) : 0;
	return (!(head) ? node : head);
}

t_dir_list		*check_file(char *xfile, t_dir_things *x)
{
	t_dir_list	*node;
	t_dir_list	*head;
	// int			r;
	char		*temp;

	// r = 0;
	node = NULL;
	temp = NULL;
	head = NULL;
	if (lstat(xfile, &x->buf) < 0)
	{
		perror(xfile);
		return (NULL);
	}
	node = fx_lstnew(xfile, (x->buf.st_mtime));
	lb_data_in(x, node);
	erro_kill((x->pwd)) ? exit(0) : str_dumps(node, set_rights(x->buf.st_mode),
		ft_strdup(x->pwd->pw_name), ft_strdup(x->grp->gr_name));
	fx_lstadd(&head, node);
	ft_strdel(&temp);
	return (head);
}

char			*set_rights(mode_t modething)
{
	char *rights;

	rights = NULL;
	rights = ft_strnew(10);
	rights[0] = gimme_file_type(modething);
	rights[1] = (modething & S_IRUSR) ? 'r' : '-';
	rights[2] = (modething & S_IWUSR) ? 'w' : '-';
	rights[3] = (modething & S_IXUSR) ? 'x' : '-';
	rights[4] = (modething & S_IRGRP) ? 'r' : '-';
	rights[5] = (modething & S_IWGRP) ? 'w' : '-';
	rights[6] = (modething & S_IXGRP) ? 'x' : '-';
	rights[7] = (modething & S_IROTH) ? 'r' : '-';
	rights[8] = (modething & S_IWOTH) ? 'w' : '-';
	rights[9] = (modething & S_IXOTH) ? 'x' : '-';
	return (rights);
}
