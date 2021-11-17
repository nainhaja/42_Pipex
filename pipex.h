/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:43:38 by nainhaja          #+#    #+#             */
/*   Updated: 2021/06/30 17:43:40 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <time.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_args_num{
	char	**cmds;
	int		checker;
	char	*file;
}	t_args_ind;

int		ft_strrlen(char **v);
char	**ft_AfterEqq(char *k, int *checker_1);
void	copy(char **t, int n, char ***path_3);
void	ft_fork_cmd(int f, int *fd, char *path, t_args_ind *tab);
void	ft_first_command(int ind, int *fd, char *path, t_args_ind *tab);
void	ft_fork_cmd_2(int f, int *fd, char *path, t_args_ind *tab);
void	ft_second_command(char *file, int *fd, char *path, t_args_ind *tab);
void	ft_get_path(char **path, int *ind, t_args_ind *tab, char **path_3);
void	ft_get_secpath(char **path, int *ind, t_args_ind *tab, char **path_3);
void	ft_get_commands(char **argv, char ***test1, char ***test2);
void	ft_getfile(char **argv, char **test1, char **test2);
void	ft_check_cmd(int checker_2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putsstr(char *s);
void	ft_error(int i);
void	ft_check_abs(char **path, int *ind, t_args_ind *tab, char **path_3);

#endif
