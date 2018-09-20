/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:52:43 by llanga            #+#    #+#             */
/*   Updated: 2018/09/18 10:08:56 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				eval_flags(char *str, t_dir_things *flags)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "-") == 0)
		ft_putendl("no flags here!");
	if (str[i] != '-')
		return (1);
	if (str[i] == '-')
	{
		while (str[i++] != '\0')
		{
			if ((ft_strchr("lart", str[i]) == NULL))
				ft_putendl("one of your flags is invalid, use l/a/r/t instead");
			if (str[i] == 't')
				flags->dash_t = 1;
			if (str[i] == 'r')
				flags->dash_r = 1;
			if (str[i] == 'a')
				flags->dash_a = 1;
			if (str[i] == 'l')
				flags->dash_l = 1;
		}
	}
	return (2);
}

t_dirname		*mkdir_names_lst(t_dirname *dirs, int i, char **av, int ac)
{
	t_dirname *node;

	node = NULL;
	while (i < ac)
	{
		node = (t_dirname*)malloc(sizeof(t_dirname));
		node->name = av[i] ? av[i] : ".";
		node->next = dirs;
		dirs = node;
		i++;
	}
	return (dirs);
}

char			gimme_file_type(mode_t modething)
{
	char r;

	r = '-';
	if (S_ISDIR(modething))
		return (r = 'd');
	else if (S_ISBLK(modething))
		return (r = 'b');
	else if (S_ISCHR(modething))
		return (r = 'c');
	else if (S_ISFIFO(modething))
		return (r = 'p');
	else if (S_ISSOCK(modething))
		return (r = 's');
	else if (S_ISLNK(modething))
		return (r = 'l');
	return (r);
}

int				main(int ac, char **av)
{
	t_dirname		*node;
	t_dir_list		*dir_list;
	t_dir_things	x;
	int				j;

	dir_list = NULL;
	node = NULL;
	j = 0;
	inistruct(&x);
	if (ac == 1)
	{
		dir_list = read_dir(".", &x);
		dir_list = srt_ascii(dir_list);
		fx_lstiter(dir_list, &x, &displaydata);
		free_dir_list(&dir_list);
	}
	else if (ac >= 2)
	{
		j = eval_flags(av[1], &x);
		x.n_dirs = ac - j;
		node = mkdir_names_lst(node, j, av, ac);
		do_something(&x, dir_list, node, av[0 + j]);
	}
	free_struct(&x);
	exit(0);
}
