/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:41:08 by nainhaja          #+#    #+#             */
/*   Updated: 2021/06/30 17:41:10 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_path(char **path, int *ind, t_args_ind *commands, char **path_3)
{
	int		plus;
	int		test2;

	plus = 0;
	*ind = 0;
	while (path_3[plus])
	{
		test2 = open(ft_strjoin(path_3[plus], commands[0].cmds[0]), O_RDONLY);
		if (test2 > 0)
		{
			*ind = 1;
			*path = ft_strjoin(path_3[plus], commands[0].cmds[0]);
		}
		close(test2);
		plus++;
	}
}

void	ft_check_abs(char **path, int *ind, t_args_ind *commands, char **path_3)
{
	int		plus;
	int		test1;

	plus = 0;
	while (path_3[plus])
	{
		test1 = open(commands[0].cmds[0], O_RDONLY);
		if (test1 > 0 && *ind == 0)
		{
			*path = commands[0].cmds[0];
			*ind = 1;
		}
		close(test1);
		plus++;
	}
}

void	ft_get_secpath(char **path, int *ind, t_args_ind *t, char **tab)
{
	int	i;
	int	test1;
	int	test2;

	i = 0;
	*ind = 0;
	while (tab[i])
	{
		test1 = open(t[1].cmds[0], O_RDONLY);
		test2 = open(ft_strjoin(tab[i], t[1].cmds[0]), O_RDONLY);
		if (test2 > 0)
		{
			*ind = 1;
			*path = ft_strjoin(tab[i], t[1].cmds[0]);
			close(test2);
		}
		else if (test1 > 0)
		{
			*ind = 1;
			*path = t[1].cmds[0];
		}
		close(test2);
		close(test1);
		i++;
	}
}
