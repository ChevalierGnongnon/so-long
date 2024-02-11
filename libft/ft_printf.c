/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:16:51 by chhoflac          #+#    #+#             */
/*   Updated: 2024/01/31 10:34:01 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_format(const char *s, size_t i, va_list args)
{
	int	length;

	length = 0;
	if (s[i] == 'c')
		length += ft_char(va_arg(args, int));
	else if (s[i] == 's')
		length += ft_string(va_arg(args, char *));
	else if (s[i] == 'p')
		length += ft_pointer(va_arg(args, unsigned long long));
	else if (s[i] == 'd' || s[i] == 'i')
		length += ft_decimal(va_arg(args, int));
	else if (s[i] == 'u')
		length += ft_unsigned(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		length += ft_hexa_low(va_arg(args, unsigned int));
	else if (s[i] == 'X')
		length += ft_hexa_up(va_arg(args, unsigned int));
	else if (s[i] == '%')
	{
		length++;
		write(1, "%", 1);
	}
	return (length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	size_t	length;

	va_start(args, s);
	i = 0;
	length = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			length += ft_get_format(s, i + 1, args);
			i++;
		}
		else
			length += ft_char(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}
