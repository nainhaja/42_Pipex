/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:42:36 by nainhaja          #+#    #+#             */
/*   Updated: 2021/06/30 17:42:40 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (ptr == 0)
		return (0);
	else
	{
		while (s[i])
		{
			ptr[i] = s[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (c == '\0' && str[i] == c)
		return ((str + i));
	if (i == ft_strlen(str))
		return (0);
	ptr = (str + i);
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
