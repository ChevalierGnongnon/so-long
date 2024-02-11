/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:17:50 by chhoflac          #+#    #+#             */
/*   Updated: 2023/11/18 16:03:25 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*pr1;
	const char	*pr2;

	i = 0;
	pr1 = s1;
	pr2 = s2;
	while (i < n)
	{
		if (pr1[i] != pr2[i])
			return ((unsigned char)pr1[i] - (unsigned char)pr2[i]);
		i++;
	}
	return (0);
}
