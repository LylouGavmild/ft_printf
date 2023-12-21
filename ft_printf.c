/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:20:41 by abutet            #+#    #+#             */
/*   Updated: 2023/11/22 12:45:30 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_percent(va_list ptr, char c)
{
	int	ret;

	if (c == 'c')
		ret = ft_putchar_fd_len(va_arg(ptr, int));
	else if (c == 's')
		ret = ft_putstr_fd_len(va_arg(ptr, char *));
	else if (c == 'p')
		ret = ft_putp(va_arg(ptr, long unsigned int));
	else if (c == 'd')
		ret = ft_putnbr_fd_len(va_arg(ptr, int));
	else if (c == 'i')
		ret = ft_putnbr_fd_len(va_arg(ptr, int));
	else if (c == 'u')
		ret = ft_putunbr(va_arg(ptr, unsigned int));
	else if (c == 'x')
		ret = ft_puthex(va_arg(ptr, unsigned int), 'x');
	else if (c == 'X')
		ret = ft_puthex(va_arg(ptr, unsigned int), 'X');
	else
	{
		ret = ft_putchar_fd_len('%');
		if (c != '%')
			ret += ft_putchar_fd_len(c);
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			i++;
			len++;
		}
		else
		{
			len += ft_handle_percent(ptr, s[i + 1]);
			i = i + 2;
		}
	}
	va_end(ptr);
	return (len);
}
