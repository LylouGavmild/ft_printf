/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:44:42 by abutet            #+#    #+#             */
/*   Updated: 2023/11/20 11:46:41 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putp_rec(long unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 15)
	{
		len += ft_putp_rec(nbr / 16);
		len += ft_putp_rec(nbr % 16);
	}
	else
	{
		len += ft_putchar_fd_len("0123456789abcdef"[nbr % 16]);
	}
	return (len);
}

int	ft_putp(long unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += ft_putstr_fd_len("(nil)");
	else
	{
		len += ft_putstr_fd_len("0x");
		len += ft_putp_rec(nbr);
	}
	return (len);
}
