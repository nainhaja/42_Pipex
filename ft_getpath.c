/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:42:52 by nainhaja          #+#    #+#             */
/*   Updated: 2021/06/30 17:42:55 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strrlen(char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		i++;
	}
	return (i);
}

char	**ft_AfterEqq(char *k, int *checker_1)
{
	int		i;
	int		j;
	char	*path;
	char	**path_2;
	char	*str;

	i = 0;
	j = 0;
	*checker_1 = 1;
	path = strstr(k, "PATH");
	path_2 = ft_split(&path[5], ':');
	while (path_2[i])
	{
		str = path_2[i];
		path_2[i] = ft_strjoin(path_2[i], "/");
		free(str);
		i++;
	}
	return (path_2);
}

void	copy(char **t, int n, char ***path_3)
{
	int	checker_1;
	int	i;

	i = 0;
	checker_1 = 0;
	while (i < n)
	{
		if (strstr(t[i], "PATH") != NULL)
			*path_3 = ft_AfterEqq(t[i], &checker_1);
		i++;
	}
	if (checker_1 == 0)
	{
		ft_putsstr("No such file or Directory \n");
		exit(127);
	}
}
