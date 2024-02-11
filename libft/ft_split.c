/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:53:57 by chhoflac          #+#    #+#             */
/*   Updated: 2023/11/23 22:14:02 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *s, char c)
{
	size_t	i;
	size_t	cnt;

	if (!s)
		return ((size_t) NULL);
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0') == 0
			&& (s[i + 1] == c || s[i + 1] == '\0') == 1)
			cnt++;
		i++;
	}
	return (cnt);
}

static size_t	ft_getsub(char const *s, int c, int start)
{
	size_t	key;

	key = start;
	while (s[key] != c && s[key])
		key++;
	return (key);
}

static char	**ft_clean(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	i = 0;
	k = -1;
	tab = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			j = ft_getsub(s, c, i);
			tab[++k] = ft_substr(s, i, j - i);
			if (!tab[k])
				return (ft_clean(tab));
			i = j;
		}
	}
	return (tab);
}
