/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:35:59 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/20 17:42:11 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_realloc(char **map, char *line)
{
	char	**newstr;
	size_t	sze;
	size_t	i;

	i = 0;
	sze = 0;
	while (map && map[sze])
		sze++;
	newstr = (char **) malloc(sizeof(char **) * (sze + 2));
	while (i < sze)
	{
		newstr[i] = map[i]; 
		i++;
	}
	newstr[i] = line;
	newstr[i + 1] = 0;
	free(map);
	return (newstr);
}

int	ft_check_line(char *line)
{
	if (!line)
		return (0);
	if (line[ft_strlen(line) - 1] == '\n')
		return (ft_check_midlines(line));
	else if (line[ft_strlen(line)] == '\0')
		return (ft_check_bordlines(line));
	return (0);
}

void	ft_replace(char **map)
{
	size_t	i;

	i = 0;
	while (map[i + 1])
	{
		map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
}

char	**ft_stock_map(int fd)
{
	char	**map;
	char	*line;

	line = get_next_line(fd);
	map = NULL;
	while (line)
	{
		if (!ft_check_line(line))
			return (NULL);
		map = ft_realloc(map, line);
		line = get_next_line(fd);
	}
	ft_replace(map);
	return (map);
}
