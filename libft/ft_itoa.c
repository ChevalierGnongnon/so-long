/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:05:44 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/12 13:19:01 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getintsize(long long n)
{
	size_t	j;

	if (n == 0)
		return (1);
	j = 0;
	if (n < 0)
	{
		n *= -1;
		j++;
	}
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long long	castn;

	castn = (long long) n;
	str = ft_calloc(ft_getintsize(castn) + 1, sizeof(char));
	i = ft_getintsize(castn) - 1;
	if (!str)
		return (NULL);
	if (castn < 0)
	{
		str[0] = '-';
		castn *= -1;
	}
	str[i + 1] = '\0';
	if (castn == 0)
		str[i] = '0';
	while (castn)
	{
		str[i--] = (castn % 10) + '0';
		castn /= 10;
	}
	return (str);
}
