/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:10:03 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/13 17:40:30 by chhoflac         ###   ########.fr       */
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

t_elements	ft_get_elements(char *line)
{
	size_t		i;
	t_elements	elements;

	i = 0;
	elements.start = 0;
	elements.collectibles = 0;
	elements.collectibles = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			elements.start++;
		else if (line[i] == 'C')
			elements.collectibles++;
		else if (line[i] == 'E')
			elements.exit++;
		i++;
	}
}

t_elements	ft_map_check(int fd)
{
	size_t	i;
	char	*line;
	t_elements elements;

	i = 0;
	i = ft_check_bordline(get_next_line(fd));
	while (get_next_line(fd))
	{
		line = get_next_line(fd);
		elements = ft_get_elements(line);
	}
	return (elements);
}


