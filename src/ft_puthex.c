/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:39:30 by abutet            #+#    #+#             */
/*   Updated: 2023/11/20 10:41:45 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	void	ft_trans(unsigned int nbr, char *base, int *len)
{
	if (nbr > 15)
	{
		ft_trans(nbr / 16, base, len);
		ft_trans(nbr % 16, base, len);
	}
	else
	{
		*len = *len + 1;
		ft_putchar_fd(base[nbr % 16], 1);
	}
}

int	ft_puthex(unsigned int nbr, char c)
{
	int	len;

	len = 0;
	if (c == 'x')
		ft_trans(nbr, "0123456789abcdef", &len);
	else
		ft_trans(nbr, "0123456789ABCDEF", &len);
	return (len);
}
