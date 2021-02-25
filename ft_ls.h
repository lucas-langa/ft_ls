/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llanga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:34:12 by llanga            #+#    #+#             */
/*   Updated: 2018/08/27 09:34:14 by llanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <stdio.h>

typedef struct			s_dirname
{
	char				*name;
	struct s_dirname	*next;
}						t_dirname;

typedef	struct			s_dir_list
{
	char				*dname;
	time_t				mod_time;
	char				*rights;
	char				*usr_name;
	char				*grpname;
	off_t				fsize;
	nlink_t				links;
	struct s_dir_list	*next;
}						t_dir_list;

typedef struct			s_dir_things
{
	struct stat			buf;
	struct passwd		*pwd;
	struct group		*grp;
	DIR					*dir;
	blkcnt_t			block_size;
	char				*dir_name;
	char				*path;
	int					dash_l;
	int					dash_r;
	int					dash_a;
	int					dash_t;
	int					n_dirs;
}						t_dir_things;

int						eval_flags(char *str, t_dir_things *flags);
int						adir(const char *name);
int						eval_flags(char *str, t_dir_things *flags);
char					*set_rights(mode_t modething);
t_dir_list				*fx_lstnew(char *dname, time_t mod_time);
t_dir_list				*read_dir(char *dirname, t_dir_things *x);
t_dir_list				*list_sort(t_dir_list *head);
t_dir_list				*srt_mtime(t_dir_list *node);
t_dir_list				*srt_ascii(t_dir_list *node);
t_dir_list				*srt_rascii(t_dir_list *node);
t_dir_list				*srt_rmtime(t_dir_list *node);
t_dir_list				*sort_type(t_dir_list *dir_list, t_dir_things *x);
t_dir_list				*swap_nptr(t_dir_list *node, t_dir_list *node2);
t_dir_list				*check_file(char *xfile, t_dir_things *x);
t_dir_list				*read_dir(char *dirname, t_dir_things *x);
t_dir_list				*check_file(char *xfile, t_dir_things *x);
t_dirname				*mkdir_names_lst(t_dirname *dirs, int i, char **av,
											int ac);
void					displaydata(t_dir_list *dir_list, t_dir_things *x);
void					do_something(t_dir_things *x, t_dir_list *dir_list,
									t_dirname *node, char *path);
void					fx_lstadd(t_dir_list **node, t_dir_list *new);
void					xkill_list(t_dir_list **node);
void					free_dir_list(t_dir_list **dlist);
void					fx_lstiter(t_dir_list *node, t_dir_things *x,
						void (*display)(t_dir_list *node, t_dir_things *x));
void					str_dumps(t_dir_list *node, char *rights, char *uname,
								char *gname);
void					lb_data_in(t_dir_things *x, t_dir_list *node);
char					gimme_file_type(mode_t modething);
char					*set_rights(mode_t modething);
int						erro_kill(struct passwd *pwd);
void					inistruct(t_dir_things *x);
void					free_struct(t_dir_things *x);

#endif
