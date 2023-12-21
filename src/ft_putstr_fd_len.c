/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:37:12 by abutet            #+#    #+#             */
/*   Updated: 2023/11/20 10:38:46 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd_len(char *s)
{
	int	len;

	len = 0;
	if (!s)
		len += ft_putstr_fd_len("(null)");
	else
	{
		while (s[len])
		{
			ft_putchar_fd(s[len], 1);
			len++;
		}
	}
	return (len);
}
