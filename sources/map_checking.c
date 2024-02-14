/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:58:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/14 14:26:01 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_bordlines(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_midlines(char *line)
{
	if (line[0] != 1 && line[ft_strlen(line) - 1] != 1)
		return (0);
	return (1);
}

int ft_checkmap(int fd)
{
	size_t	i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (!line || !ft_check_bordlines(line))
		return (0);
	while(line)
	{
		if(!ft_check_midlines(line))
			return (0);
		get_next_line(fd);
	}
	return (1);
}