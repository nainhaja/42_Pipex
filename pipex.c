/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:29:09 by nainhaja          #+#    #+#             */
/*   Updated: 2021/06/30 17:43:25 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_commands(char **argv, char ***test1, char ***test2)
{
	*test1 = ft_split(argv[2], ' ');
	*test2 = ft_split(argv[3], ' ');
}

void	ft_getfile(char **argv, char **test1, char **test2)
{
	*test1 = argv[1];
	*test2 = argv[4];
}

void	ft_check_cmd(int checker_2)
{
	if (checker_2 == 0)
	{
		ft_putsstr("Pipex Command not found\n");
		if (checker_2 == 0)
			exit(127);
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*absolute_path1;
	char		*absolute_path2;
	char		**path_3;
	t_args_ind	*commands;
	int			fd[2];

	if (argc == 5)
	{
		commands = (t_args_ind *)malloc(sizeof(t_args_ind) * 2);
		copy(env, ft_strrlen(env), &path_3);
		ft_get_commands(argv, &commands[0].cmds, &commands[1].cmds);
		ft_getfile(argv, &commands[0].file, &commands[1].file);
		ft_get_path(&absolute_path1, &commands[0].checker, commands, path_3);
		ft_check_abs(&absolute_path1, &commands[0].checker, commands, path_3);
		ft_get_secpath(&absolute_path2, &commands[1].checker, commands, path_3);
		if (pipe(fd) == -1)
			return (1);
		ft_first_command(commands[0].checker, fd, absolute_path1, commands);
		ft_second_command(commands[1].file, fd, absolute_path2, commands);
		ft_check_cmd(commands[1].checker);
	}
	else
		ft_error(2);
}
