/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:33:27 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/19 13:15:38 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_push_left(char *cont)
{
	size_t	i;
	size_t	cursor;

	cursor = ft_str_stop(cont, '\n') + 1;
	i = 0;
	while (cont[cursor])
	{
		cont[i] = cont[cursor];
		cursor++;
		i++;
	}
	while (cont[i])
		cont[i++] = '\0';
}

int	ft_old_line(char **line, size_t nbchar)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(ft_strlen(*line) + nbchar + 1);
	if (!temp)
		return (1);
	while (line[0][i])
	{
		temp[i] = line[0][i];
		i++;
	}
	free(*line);
	temp[i] = '\0';
	*line = temp;
	return (0);
}

// mettre le contenu de buff dans ligne
int	ft_fill(char *buff, char **line, size_t nbchar)
{
	if (*line == 0)
	{
		*line = malloc(nbchar + 1);
		if (!*line)
			return (1);
		line[0][0] = '\0';
	}
	else
		if (ft_old_line(line, nbchar))
			return (1);
	ft_strlcat(*line, buff, ft_strlen(*line) + nbchar + 1);
	if (!ft_strchr(buff, '\n'))
		ft_bzero(buff, BUFFER_SIZE);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		nbchar;

	if (buff[0] == '\0' && read(fd, buff, BUFFER_SIZE) <= 0)
		return (NULL);
	line = 0;
	nbchar = 1;
	while (!ft_strchr(buff, '\n'))
	{
		if (ft_fill(buff, &line, ft_strlen(buff)))
			return (free(line), NULL);
		nbchar = read(fd, buff, BUFFER_SIZE);
		if (nbchar <= 0)
			break ;
	}
	if (nbchar > 0)
	{
		if (ft_fill(buff, &line, ft_str_stop(buff, '\n') + 1))
			return (free(line), NULL);
	}
	else if (nbchar < 0)
		return (free(line), NULL);
	ft_push_left(buff);
	return (line);
}
