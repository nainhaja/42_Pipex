/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:41:21 by nainhaja          #+#    #+#             */
/*   Updated: 2021/06/30 17:41:22 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork_cmd(int f1, int *fd, char *path, t_args_ind *t)
{
	char	**envv;

	envv = NULL;
	dup2(f1, 0);
	close(f1);
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	execve(path, t[0].cmds, envv);
}

void	ft_error(int i)
{
	if (i == 1)
	{
		ft_putsstr("Pipex Comand not found\n");
		exit(1);
	}
	else if (i == 0)
	{
		ft_putsstr("Pipex No such file or directory\n");
		exit (1);
	}
	else
	{
		ft_putsstr("wrong number of parametres\n");
		exit (0);
	}
}

void	ft_first_command(int ind, int *fd, char *path, t_args_ind *tab)
{
	int	id;
	int	file_1;
	int	t;

	file_1 = open(tab[0].file, O_RDONLY, 0777);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		if (file_1 != -1)
		{
			if (ind != 0)
				ft_fork_cmd(file_1, fd, path, tab);
			else
				ft_error(1);
		}
		else
			ft_error(0);
		exit(0);
	}
	close(file_1);
	close(fd[1]);
	waitpid(id, &t, 0);
}

void	ft_fork_cmd_2(int file_2, int *fd, char *path, t_args_ind *tab)
{
	char	**envv;

	envv = NULL;
	dup2(file_2, 1);
	close(file_2);
	dup2(fd[0], 0);
	close(fd[0]);
	execve(path, tab[1].cmds, envv);
	exit(0);
}

void	ft_second_command(char *file, int *fd, char *path, t_args_ind *tab)
{
	int	pid;
	int	file_2;
	int	t;

	file_2 = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pid = fork();
	if (pid == 0)
		ft_fork_cmd_2(file_2, fd, path, tab);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, &t, 0);
}
